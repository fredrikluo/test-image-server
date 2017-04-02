#ifndef NETWORK_SESSION_LISTENER_H
#define NETWORK_SESSION_LISTENER_H

#include <vector>

class network_session_listener {
 public:
  virtual void on_data_recv(const std::vector<char> &data) = 0;
  virtual void on_data_write() = 0;
  virtual void on_destroy() = 0;
};

#endif  // NETWORK_SESSION_LISTENER_H
