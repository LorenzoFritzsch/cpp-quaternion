#ifndef CPP_ALGEBRA_QUATERNION_H
#define CPP_ALGEBRA_QUATERNION_H

#include <memory>
#include <string>

class Quaternion {
public:
  double w;
  double x;
  double y;
  double z;

  Quaternion(double w, double x, double y, double z);
  Quaternion(double x, double y, double z);

  virtual std::string to_string() {
    return "(" + std::to_string(w) + ", " + std::to_string(x) + ", " +
           std::to_string(y) + ", " + std::to_string(z) + ")";
  }

  double norm();
  double squaredNorm();
  std::shared_ptr<Quaternion> conjugate();
  double scalarProduct(std::weak_ptr<Quaternion> q1);
  std::shared_ptr<Quaternion> vectorProduct(std::weak_ptr<Quaternion> q1);
  std::shared_ptr<Quaternion> scale(double k);
  std::shared_ptr<Quaternion> sum(std::weak_ptr<Quaternion> q1);
  std::shared_ptr<Quaternion> subtract(std::weak_ptr<Quaternion> q1);
  bool isOrthogonal(std::weak_ptr<Quaternion> q1);
  bool isUnitary();
  std::shared_ptr<Quaternion> normalize();
  std::shared_ptr<Quaternion> multiply(std::weak_ptr<Quaternion> q1);
  std::shared_ptr<Quaternion> inverse();
  std::shared_ptr<Quaternion> symmetric(std::weak_ptr<Quaternion> q1);
  std::shared_ptr<Quaternion> rotate(std::weak_ptr<Quaternion> axis,
                                     double theta);
};

#endif // CPP_ALGEBRA_QUATERNION_H
