#include "quaternion.h"
#include <memory>

int main() {
  auto q0 = std::make_shared<Quaternion>(0, 0, 0);
  auto q1 = std::make_shared<Quaternion>(123, 12309.932, -1234);

  if (!q1->isOrthogonal(q1) && q0->isOrthogonal(q0) && q1->isOrthogonal(q0)) {
    return 0;
  } else {
    return 1;
  }
}
