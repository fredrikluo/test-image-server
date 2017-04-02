#ifndef APP_SESSION_H
#define APP_SESSION_H

#include "app_data.h"
#include "app_protocol.h"
#include "network_session.h"

class app_session : public network_session_listener,
                    public app_protocol_listener {
 public:
  app_session(network_session *ns, app_data &data);
  virtual ~app_session() {}

  virtual void on_data_recv(const std::vector<char> &data);
  virtual void on_data_write();
  virtual void on_destroy();
  virtual void on_protocol_command(int cmd);

 private:
  app_data &m_data;
  app_protocol m_protocol;
  network_session *m_network_session;
};

#endif  // APP_SESSION_H
