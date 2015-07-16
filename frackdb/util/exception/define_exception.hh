#include <exception>

#define DEFINE_EXCEPTION(NAME, CLASS) \
  struct NAME : public std::exception { \
    virtual const char* what() const noexcept { \
      return #CLASS ": " #NAME; \
    } \
  }
