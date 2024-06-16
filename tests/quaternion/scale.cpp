#include "quaternion.h"
#include <memory>

int main() {
  auto quaternion = std::make_unique<Quaternion>(1, 1, 1, 1);
  double alpha = 5;
  auto expectedScaledQuaternion = std::make_unique<Quaternion>(5, 5, 5, 5);
  if (expectedScaledQuaternion->to_string() ==
      quaternion->scale(alpha)->to_string()) {
    return 0;
  } else {
    return 1;
  }
}
