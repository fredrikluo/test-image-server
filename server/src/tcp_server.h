#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <cstdlib>
#include <iostream>

#include "network_server.h"
#include "tcp_session.h"

class tcp_server : public network_server {

  tcp_server(short port, network_server_listener *listener);
  virtual ~tcp_server() { delete m_acceptor; }

  void start_accept();
  void handle_accept(tcp_session *tcp_session,
                     const boost::system::error_code &error);

  boost::asio::io_service m_io_service;
  tcp::acceptor *m_acceptor;
  network_server_listener *m_listener;

  friend class network_server;
};

#endif  // TCP_SERVER_H
