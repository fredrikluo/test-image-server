#ifndef NETWORK_SESSION_H
#define NETWORK_SESSION_H

#include "network_session_listener.h"

class network_session {
 protected:
  network_session() : m_listener(nullptr) {}

  virtual ~network_session() {
    if (m_listener) {
      m_listener->on_destroy();
    }
  }

 public:
  void set_listener(network_session_listener *ns_listener) {
    m_listener = ns_listener;
  }

  virtual void on_data_recv(const std::vector<char> &buffer) {
    if (m_listener) {
      m_listener->on_data_recv(buffer);
    }
  }

  virtual void on_data_write() {
    if (m_listener) {
      m_listener->on_data_write();
    }
  }

  virtual void write(const std::vector<char> &buffer) = 0;
  virtual void close() = 0;

 private:
  network_session_listener *m_listener;
};

#endif  // NETWORK_SESSION_H
