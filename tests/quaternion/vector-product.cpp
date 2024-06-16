#include "quaternion.h"
#include <memory>

int main() {
  auto q1 = std::make_shared<Quaternion>(3, 123, 84923.3248);
  auto q2 = std::make_shared<Quaternion>(98, 0.324, -12312.43);

  std::shared_ptr<Quaternion> p1 = q1->vectorProduct(q2);
  std::shared_ptr<Quaternion> p2 = q2->vectorProduct(q1);

  if (p1->to_string() == p2->conjugate()->to_string()) {
    return 0;
  } else {
    return 1;
  }
}
