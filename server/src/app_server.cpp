#include "app_server.h"
#include "app_session.h"

// TODO: make it configurable.
app_server::app_server()
    : m_network_server(network_server::get_tcp_server(this, 8080)) {}

void app_server::on_new_session(class network_session *session) {
  // create a app session and connect it to network session
  new app_session(session, m_data);
}
