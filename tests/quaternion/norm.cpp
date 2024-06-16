#include "quaternion.h"
#include <memory>

int main() {
  auto quaternion = std::make_unique<Quaternion>(1, 3, 4, 5);
  double squaredNorm = quaternion->squaredNorm();
  double norm = quaternion->norm();
  if (squaredNorm == 51 && norm == std::sqrt(squaredNorm)) {
    return 0;
  } else {
    return 1;
  }
}
