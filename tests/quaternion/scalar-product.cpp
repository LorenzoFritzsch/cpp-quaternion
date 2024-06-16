#include "quaternion.h"
#include <memory>

int main() {
  auto q1 = std::make_shared<Quaternion>(8, 3, 321.32);
  auto q2 = std::make_shared<Quaternion>(92.89823, 0.123, 878);

  double cp1 = q1->scalarProduct(q2);
  double cp2 = q2->scalarProduct(q1);

  if (cp1 == cp2) {
    return 0;
  } else {
    return 1;
  }
}
