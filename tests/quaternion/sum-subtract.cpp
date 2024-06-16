#include "quaternion.h"
#include <memory>

int main() {
  auto q1 =
      std::make_shared<Quaternion>(123, 41.23, -123.12312312089, 98797897.21);
  auto q2 = std::make_shared<Quaternion>(987.32, -0.00123, 8987, 123.0);

  if (q1->sum(q2)->subtract(q1)->to_string() == q2->to_string()) {
    return 0;
  } else {
    return 1;
  }
}
