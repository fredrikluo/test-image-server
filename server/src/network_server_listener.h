#ifndef NETWORK_SERVER_LISTENER_H
#define NETWORK_SERVER_LISTENER_H

class network_session;

class network_server_listener {
 public:
  virtual void on_new_session(network_session *session) = 0;
};

#endif  // NETWORK_SERVER_LISTENER_H
