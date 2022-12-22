#ifndef H_UTIL
#define H_UTIL

#include <exception>

class BadArgument : public std::exception {
public:
    explicit BadArgument(const char* msg) : exception(msg) {
    }
};

#define ASSERT(cond) if (!(cond)) throw BadArgument(#cond)


#endif      // H_UTIL