/*
 * modern programming excercise7
 * 08/12/2015 Nagisa YATA
 */

#include <cmath>
#include <iostream>
#include <iomanip>

namespace exercise {

enum class SqrtMethod {
  CPP = 0,
  BABYLONIAN = 1,
  NEWTONRAPHSON = 2,
  EXP = 3
};

/*
 * SqrtBase class
 */
class SqrtBase {
public:
  SqrtBase(){}

  SqrtBase(std::string m="Sqrt base") :
    method(m){
  }

  virtual double sqrt(double x) = 0;
  friend std::ostream& operator<<(std::ostream& os, const SqrtBase& s);

protected:
  const std::string method;
  virtual std::ostream& print(std::ostream& os) const = 0;
};

/*
 * Cplusplus class
 * compute sqrt using c++ library
 */
class CPlusPlusSqrt : public SqrtBase {
public:
  CPlusPlusSqrt(std::string m="C++") : SqrtBase(m) {}

  // override
  virtual double sqrt(double x) override {
    // std::cout << "test" << std::endl;
    return std::sqrt(x);
  }


protected:
  virtual std::ostream& print(std::ostream& os) const override {
    os << method << " (direct method)" << std::endl;
    return os;
  }
};

/*
 * Exponential class
 * compute sqrt using fomula with exponential
 */
class ExponentialSqrt : public SqrtBase {
public:
  ExponentialSqrt(std::string m="Exponential") : SqrtBase(m) {}

  // override
  virtual double sqrt(double x) override {
    return std::exp(0.5 - std::log(x));
  }


protected:
  virtual std::ostream& print(std::ostream& os) const override {
    os << method << " (direct method)" << std::endl;
    return os;
  }
};

/*
 * IterativeSqrt class
 * abstract class which compute sqrt using iterative method
 */
class IterativeSqrt : public SqrtBase {
public:
  IterativeSqrt(std::string s="Iterative", double e=1.0, int i=3) : SqrtBase(s), estimate(e), iteration(i) {}

  void setEstimate(double e) {
    estimate = e;
  }

  void setIterations(int i) {
    iteration = i;
  }

protected:
  double estimate;
  int iteration;

  virtual std::ostream& print(std::ostream& os) const = 0;
};

/*
 * BabylonianSqrt class
 * 
 */
class BabylonianSqrt : public IterativeSqrt {
public:
  BabylonianSqrt() : IterativeSqrt("Babylonian", 1.0, 3) {}
  BabylonianSqrt(std::string s="Babylonian") : IterativeSqrt(s, 1.0, 3) {}
  BabylonianSqrt(double e=1.0, int i=3) : IterativeSqrt("Babylonian", e, i) {}
  // BabylonianSqrt(double e=1.0) : IterativeSqrt("Babylonian", e, 3) {}
  // BabylonianSqrt(int i=3) : IterativeSqrt("Babylonian", 1.0, i) {}
  BabylonianSqrt(std::string s="Babylonian", double e=1.0, int i=3) : IterativeSqrt(s, e, i) {}

  virtual double sqrt(double x) override {
    double ak = this->estimate;
    for (int i = 0; i < this->iteration; i++) {
      ak = (ak + x / ak) / 2.0;
    }

    return ak;
  }

protected:
  virtual std::ostream& print(std::ostream& os) const override {
    os << method << " (iterative method)" << std::endl;
    return os;
  }
};

class NewtonRaphsonSqrt : public IterativeSqrt {
public:
  NewtonRaphsonSqrt() : IterativeSqrt("Newton-Raphson", 1.0, 3) {}
  NewtonRaphsonSqrt(std::string s="Newton-Raphson") : IterativeSqrt(s, 1.0, 3) {}
  NewtonRaphsonSqrt(double e=1.0, int i=3) : IterativeSqrt("Newton-Raphson", e, i) {}
  // NewtonRaphsonSqrt(double e=1.0) : IterativeSqrt("Newton-Raphson", e, 3) {}
  // NewtonRaphsonSqrt(int i=3) : IterativeSqrt("Newton-Raphson", 1.0, i) {}
  NewtonRaphsonSqrt(std::string s="Newton-Raphson", double e=1.0, int i=3) : IterativeSqrt(s, e, i) {}

  virtual double sqrt(double x) override {
    double ak = 1/this->estimate;
    for (int i = 0; i < this->iteration; i++) {
      ak = ak * (3.0 - x * ak * ak) / 2.0;
    }

    return ak * x;
  }

protected:
  virtual std::ostream& print(std::ostream& os) const override {
    os << method << " (iterative method)" << std::endl;
    return os;
  }
};

// overload operator <<
std::ostream& operator<<(std::ostream& os, const SqrtBase& s) {
  return s.print(os);
}

}  // namespace excercise

int main() {
  const int max = 8;
  exercise::SqrtBase* methods[max];
  int i = 0;
  methods[i++] = new exercise::CPlusPlusSqrt;
  methods[i++] = new exercise::ExponentialSqrt;
  methods[i++] = new exercise::BabylonianSqrt(1.0);
  methods[i++] = new exercise::BabylonianSqrt(1.0, 5);
  methods[i++] = new exercise::NewtonRaphsonSqrt(1.0);
  methods[i++] = new exercise::NewtonRaphsonSqrt(1.0, 4);
  methods[i++] = new exercise::NewtonRaphsonSqrt(1.0, 5);
  methods[i++] = new exercise::NewtonRaphsonSqrt(1.0, 6);
  for (i = 0; i < max; ++i) {
    std::cout << " " << std::setw(11) << std::setprecision(10) << std::setiosflags(std::ios::left)
              << methods[i]->sqrt(2) << " --> " << *methods[i]
              << std::resetiosflags(std::ios::left) << std::endl;
  }
  return 0;
}
