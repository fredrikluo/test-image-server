#ifndef APP_SERVER_H
#define APP_SERVER_H

#include <memory>
#include "app_data.h"
#include "network_server.h"

class app_server : public network_server_listener {
 public:
  app_server();
  virtual ~app_server() {}
  virtual void on_new_session(network_session *session);

 private:
  app_server(const app_server &);
  app_server &operator=(const app_server &);

  app_data m_data;
  std::unique_ptr<network_server> m_network_server;
};

#endif  // APP_SERVER_H
