#ifndef NETWORK_SERVER_H
#define NETWORK_SERVER_H

#include "network_server_listener.h"

class network_server {
 public:
  static network_server *get_tcp_server(network_server_listener *listener,
                                        short ip);

 protected:
  network_server() {}
};

#endif  // NETWORK_SERVER_H
