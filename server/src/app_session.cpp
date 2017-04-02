#include "app_session.h"
#include "util.h"

app_session::app_session(network_session *ns, app_data &data)
    : m_data(data),
      m_protocol(this),
      m_network_session(ns) {
  assert(ns != nullptr &&
         "This can't be NULL, you need to have network session passed in");

  m_network_session->set_listener(this);
}

void app_session::on_data_recv(const std::vector<char> &data) {
  m_protocol.recv(data);
}

void app_session::on_data_write() { m_network_session->close(); }

void app_session::on_destroy() { delete this; }

void app_session::on_protocol_command(int cmd) {
  LOG("app session: recv command", cmd);
  if (cmd == app_protocol::GET_ALL_CMD) {
    m_network_session->write(m_data.get_data());
  }
}
