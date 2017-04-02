#include "tcp_server.h"
#include "util.h"

tcp_server::tcp_server(short port, network_server_listener *listener)
    : m_listener(listener) {
        m_acceptor =
            new tcp::acceptor(m_io_service, tcp::endpoint(tcp::v4(), port));
        start_accept();
        m_io_service.run();
    }


void tcp_server::start_accept() {
    tcp_session *ts = new tcp_session(m_io_service);
    m_acceptor->async_accept(ts->socket(),
            boost::bind(&tcp_server::handle_accept, this, ts,
                boost::asio::placeholders::error));
    m_listener->on_new_session(ts);
}

void tcp_server::handle_accept(tcp_session *tcp_session,
        const boost::system::error_code &error) {
    // deal with the session
    if (!error) {
        LOG("new connection");
        tcp_session->start();
    } else {
        LOG("new connection failed");
        tcp_session->close();
        tcp_session = nullptr;
    }

    start_accept();
}
