#ifndef APP_DATA_H
#define APP_DATA_H

#include <vector>

class app_data {
 public:
  app_data();

  virtual ~app_data() {}

  std::vector<char> &get_data() { return m_data; }

 private:
  std::vector<char> m_data;
  static const char *FILE_LIST[];
  static const char MAGIC_HEADER[];

  void read_file(const char *filename, std::vector<char> &vec);
};

#endif  // APP_DATA_H
