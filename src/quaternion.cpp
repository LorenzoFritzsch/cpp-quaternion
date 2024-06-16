#include "quaternion.h"
#include "algebraic-exception.cpp"
#include <cmath>
#include <memory>

Quaternion::Quaternion(double w, double x, double y, double z) {
  this->w = w;
  this->x = x;
  this->y = y;
  this->z = z;
}

Quaternion::Quaternion(double x, double y, double z) {
  this->w = 0;
  this->x = x;
  this->y = y;
  this->z = z;
}

double Quaternion::norm() { return sqrt(squaredNorm()); }

double Quaternion::squaredNorm() {
  return pow(w, 2) + pow(x, 2) + pow(y, 2) + pow(z, 2);
}

std::shared_ptr<Quaternion> Quaternion::conjugate() {
  return std::make_shared<Quaternion>(w, -x, -y, -z);
}

double Quaternion::scalarProduct(std::weak_ptr<Quaternion> q1) {
  return x * q1.lock()->x + y * q1.lock()->y + z * q1.lock()->z;
}

std::shared_ptr<Quaternion>
Quaternion::vectorProduct(std::weak_ptr<Quaternion> q1) {
  return std::make_shared<Quaternion>(y * q1.lock()->z - z * q1.lock()->y,
                                      z * q1.lock()->x - x * q1.lock()->z,
                                      x * q1.lock()->y - y * q1.lock()->x);
}

std::shared_ptr<Quaternion> Quaternion::scale(double k) {
  return std::make_shared<Quaternion>(w * k, x * k, y * k, z * k);
}

std::shared_ptr<Quaternion> Quaternion::sum(std::weak_ptr<Quaternion> q1) {
  return std::make_shared<Quaternion>(w + q1.lock()->w, x + q1.lock()->x,
                                      y + q1.lock()->y, z + q1.lock()->z);
}

std::shared_ptr<Quaternion> Quaternion::subtract(std::weak_ptr<Quaternion> q1) {
  return std::make_shared<Quaternion>(w - q1.lock()->w, x - q1.lock()->x,
                                      y - q1.lock()->y, z - q1.lock()->z);
}

bool Quaternion::isOrthogonal(std::weak_ptr<Quaternion> q1) {
  return this->scalarProduct(q1) == 0;
}

bool Quaternion::isUnitary() {
  double squaredNorm = this->squaredNorm();
  return squaredNorm / 1 >= 0.9999;
}

std::shared_ptr<Quaternion> Quaternion::normalize() {
  return this->scale(1 / this->norm());
}

std::shared_ptr<Quaternion> Quaternion::multiply(std::weak_ptr<Quaternion> q1) {
  return std::make_shared<Quaternion>(
      w * q1.lock()->w - x * q1.lock()->x - y * q1.lock()->y - z * q1.lock()->z,
      w * q1.lock()->x + x * q1.lock()->w + y * q1.lock()->z - z * q1.lock()->y,
      w * q1.lock()->y + y * q1.lock()->w + z * q1.lock()->x - x * q1.lock()->z,
      w * q1.lock()->z + z * q1.lock()->w + x * q1.lock()->y -
          y * q1.lock()->x);
}

std::shared_ptr<Quaternion> Quaternion::inverse() {
  return this->conjugate()->scale(1 / this->squaredNorm());
}

std::shared_ptr<Quaternion>
Quaternion::symmetric(std::weak_ptr<Quaternion> hyperplane) {
  return hyperplane.lock()
      ->multiply(this->conjugate())
      ->multiply(hyperplane.lock())
      ->multiply(hyperplane.lock()
                     ->multiply(hyperplane.lock()->conjugate())
                     ->inverse())
      ->scale(-1);
}

std::shared_ptr<Quaternion> Quaternion::rotate(std::weak_ptr<Quaternion> axis,
                                               double theta) {
  if (!axis.lock()->isUnitary()) {
    throw AlgebraicException("Axis of rotation is not unitary");
  }

  return this->scale(std::cos(theta))
      ->sum(axis.lock()->scale(
          axis.lock()->scalarProduct(std::make_shared<Quaternion>(
              this->w, this->x, this->y, this->z)) *
          (1 - std::cos(theta))))
      ->sum(axis.lock()
                ->vectorProduct(std::make_shared<Quaternion>(this->w, this->x,
                                                             this->y, this->z))
                ->scale(std::sin(theta)));
}
