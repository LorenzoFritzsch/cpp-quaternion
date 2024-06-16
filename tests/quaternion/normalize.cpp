#include "quaternion.h"
#include <memory>

int main() {
  auto q1 =
      std::make_unique<Quaternion>(-1231.32, 898942.54, 2374.321, 0.99912);
  if (q1->normalize()->isUnitary()) {
    return 0;
  } else {
    return 1;
  }
}
