#include "app_data.h"
#include <fstream>

const char app_data::MAGIC_HEADER[] = "APP_DATA";
const char *app_data::FILE_LIST[] = {"res/1.jpg",
                                     "res/2.jpg"};

app_data::app_data() {
  for (int i = 0; i < sizeof(FILE_LIST) / sizeof(FILE_LIST[0]); i++) {
    std::vector<char> img;
    read_file(FILE_LIST[i], img);
    m_data.insert(m_data.end(), MAGIC_HEADER,
                  MAGIC_HEADER + sizeof(MAGIC_HEADER));
    m_data.insert(m_data.end(), img.begin(), img.end());
  }
}

void app_data::read_file(const char *filename, std::vector<char> &vec) {
  std::ifstream file(filename, std::ios::binary);
  file.unsetf(std::ios::skipws);
  std::streampos fileSize;

  file.seekg(0, std::ios::end);
  fileSize = file.tellg();
  file.seekg(0, std::ios::beg);

  vec.reserve(fileSize);

  // read the data:
  vec.insert(vec.begin(), std::istream_iterator<char>(file),
             std::istream_iterator<char>());
}
