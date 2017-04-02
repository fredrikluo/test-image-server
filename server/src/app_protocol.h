#ifndef APP_PROTOCOL_H
#define APP_PROTOCOL_H

#include <cassert>
#include <vector>

#include "app_protocol_listener.h"

class app_protocol {
 public:
  static const int NONE_CMD = 0;
  static const int GET_ALL_CMD = 1;

  app_protocol(app_protocol_listener *app_plistener)
      : m_listener(app_plistener) {
    assert(app_plistener != nullptr &&
           "Check your parameter here, listener can't be NULL");
  }

  void recv(const std::vector<char> &data);

 private:
  static const char CMD_GET_ALL[];
  app_protocol_listener *m_listener;
  std::vector<char> m_cmd_buffer;
};

#endif  // APP_PROTOCOL_H
