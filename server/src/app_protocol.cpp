#include "app_protocol.h"
#include "util.h"

const char app_protocol::CMD_GET_ALL[] = "GETALL";

void app_protocol::recv(const std::vector<char> &data) {
  for (auto itr = data.begin(); itr != data.end(); ++itr) {
    //  we are looking for "\r"
    char d = *itr;
    const size_t cmd_size = ARRAY_SIZE(CMD_GET_ALL) - 1;
    if (d == 0xd) {
      // we check the buffer
      if (m_cmd_buffer.size() == cmd_size &&
          !strncmp(CMD_GET_ALL, m_cmd_buffer.data(), cmd_size)) {
        m_listener->on_protocol_command(GET_ALL_CMD);
      }

      LOG("recv cmd:", m_cmd_buffer);

      m_cmd_buffer.clear();
    } else if (d >= 'A' && d <= 'Z') {
      // push it to command buffer
      m_cmd_buffer.push_back(d);
    }
  }
}
