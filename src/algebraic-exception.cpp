#include <exception>
#include <string>

class AlgebraicException : public std::exception {
private:
  std::string message;

public:
  AlgebraicException(std::string msg) : message(msg) {}
  std::string what() { return message; }
};
