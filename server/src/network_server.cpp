#include "network_server.h"
#include "tcp_server.h"

network_server *network_server::get_tcp_server(
    network_server_listener *listener, short port) {
  return new tcp_server(port, listener);
}
