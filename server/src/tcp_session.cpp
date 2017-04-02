#include "tcp_session.h"
#include "util.h"

void tcp_session::start() {
    LOG("tcp start reading");
    read();
}

void tcp_session::write(const std::vector<char> &data) {
    LOG("tcp write", data.size());
    boost::asio::async_write(m_socket,
            boost::asio::buffer(data.data(), data.size()),
            boost::bind(&tcp_session::handle_write, this,
                boost::asio::placeholders::error));
}

void tcp_session::close() {
    m_socket.cancel();
    delete this;
}

void tcp_session::read() {
    m_data.resize(m_data.capacity());
    m_socket.async_read_some(
            boost::asio::buffer(m_data.data(), m_data.capacity()),
            boost::bind(&tcp_session::handle_read, this,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
}

void tcp_session::handle_read(const boost::system::error_code &error,
        size_t bytes_transferred) {
    if (!error) {
        assert(bytes_transferred <= m_data.capacity() &&
                "there is not supposed to happen, check to see if boost has "
                "changed its behavior");

        LOG("tcp recv:", m_data);
        m_data.resize(bytes_transferred);
        // OK we report the data we have received.
        on_data_recv(m_data);
        // set up to read more
        read();
    } else if (error == boost::asio::error::operation_aborted) {
    } else {
        LOG("tcp error:", bytes_transferred);
        close();
    }
}

void tcp_session::handle_write(const boost::system::error_code &error) {
    if (!error) {
        on_data_write();
    } else if (error == boost::asio::error::operation_aborted) {
    } else {
        close();
    }
}

