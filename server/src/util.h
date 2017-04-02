#ifndef OPS_APP_UTIL_H
# define OPS_APP_UTIL_H

#include <vector>

// Very simple log statement, need to be improved.
void LOG(const char * prefix, const std::vector<char>&  payload);
void LOG(const char * str);
void LOG(const char * str, int extra);

#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))

#endif // OPS_APP_UTIL_H
