#include "quaternion.h"
#include <memory>

int main() {
  auto quaternion = std::make_unique<Quaternion>(1, 1, 1, 1);
  auto expectedConjugate = std::make_unique<Quaternion>(1, -1, -1, -1);
  auto conjugate = quaternion->conjugate();
  if (expectedConjugate->to_string() == conjugate->to_string()) {
    return 0;
  } else {
    return 1;
  }
}
