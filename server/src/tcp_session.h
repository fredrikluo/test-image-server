#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <cstdlib>
#include <iostream>

#include "network_session.h"

using boost::asio::ip::tcp;

class tcp_session : public network_session {
 private:
  tcp_session(boost::asio::io_service &io_service)
      : m_socket(io_service), m_data(BUF_SIZE) {}

  virtual ~tcp_session() {}

 public:
  tcp::socket &socket() { return m_socket; }

  void start();

  virtual void write(const std::vector<char> &data);
  virtual void close();

 private:
  void read();

  void handle_read(const boost::system::error_code &error,
                   size_t bytes_transferred);

  void handle_write(const boost::system::error_code &error);

  tcp::socket m_socket;
  static const size_t BUF_SIZE = 2048;
  std::vector<char> m_data;
  friend class tcp_server;
};
