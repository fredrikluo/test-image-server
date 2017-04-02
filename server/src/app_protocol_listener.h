#ifndef APP_PROTOCOL_LISTENER_H
#define APP_PROTOCOL_LISTENER_H

class app_protocol_listener {
 public:
  virtual void on_protocol_command(int cmd) = 0;
};

#endif  // APP_PROTOCOL_LISTENER_H
