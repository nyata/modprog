/*
 * modern programming excercise7
 * 08/12/2015 Nagisa YATA
 */

#include <cmath>
#include <iostream>

namespace exercise {

enum class SqrtMethod {
  CPP = 0,
  BABYLONIAN = 1,
  NEWTONRAPHSON = 2,
  EXP = 3
};

class Sqrt {
public:
  Sqrt(){}

  Sqrt(SqrtMethod m, double e, int n) :
    method(m), estimate(e), iterations(n){
  }

  friend std::ostream& operator<<(std::ostream& os, const Sqrt& s);

  // set initial value
  void set_estimate(double e) {
    this->estimate = e;
  }

  // set iterations
  void set_iterations(int n) {
    this->iterations = n;
  }

  // set calculate method
  void set_method(SqrtMethod m) {
    this->method = m;
  }

  // set value
  void set_value(double x) {
    this->calc_value = calculator(x);
  }

  // get initial value
  double get_estimate() const {
    return this->estimate;
  }

  // get iterations value
  int get_iterations() const {
    return this->iterations;
  }

  // get calculate method
  SqrtMethod get_method() const {
    return this->method;
  }
  
  // get calculate method name
  std::string get_method_name() const {
    switch(this->method) {
      case SqrtMethod::CPP:
        return "C++";
      case SqrtMethod::BABYLONIAN:
        return "Baylonian method";
      case SqrtMethod::NEWTONRAPHSON:
        return "Newton-Raphson iteration";
      case SqrtMethod::EXP:
        return "Exponential method";
      default:
        return "C++";
    }
  }

  double get_value() const {
    return this->calc_value;
  }

  double get_result() const {
    return this->result_value;
  }

  double calculator(double x) {
    switch(this->method) {
      case SqrtMethod::CPP:
        return cpp_sqrt(x);
      case SqrtMethod::BABYLONIAN:
        return babylonian(x);
      case SqrtMethod::NEWTONRAPHSON:
        return newton_raphson(x);
      case SqrtMethod::EXP:
        return exponential(x);
      default:
        return cpp_sqrt(x);
    }
  }

private:
  SqrtMethod method;
  double estimate;
  int iterations;
  double calc_value;
  double result_value;

  // babylonian method
  // calculate approximate solution sqrt(x)
  // a0: initial value
  // n : how many repeat
  double babylonian(double x) {
    double ak = this->estimate;
    for (int i = 0; i < this->iterations; i++) {
      ak = (ak + x / ak) / 2.0;
    }

    return ak;
  }
  
  // Newton-Raphson method
  // calculate approximate solution sqrt(x)
  // 1/a0: initial value
  // n : how many repeat
  double newton_raphson(double x) {
    double ak = 1/this->estimate;
    for (int i = 0; i < this->iterations; i++) {
      ak = ak * (3.0 - x * ak * ak) / 2.0;
    }

    return ak * x;
  }
  
  // C++ sqrt method
  // solution sqrt(x)
  double cpp_sqrt(double x) {
    return sqrt(x);
  }

  double exponential(double x) {
    return exp(0.5 - log(x));
  }
};

// overload operator <<
std::ostream& operator<<(std::ostream& os, const Sqrt& s) {
  os << s.get_value();
  return os;
}

}  // namespace excercise

int main(int argc, char *argv[]) {
  bool exit = false;
  char menu;
  double x = 2;
  double a0 = 2;
  int n = 3;
  exercise::SqrtMethod method = exercise::SqrtMethod::CPP;
  exercise::Sqrt calc(method, a0, n);

  while(1) {
    std::cout << std::endl;
    std::cout << "Square root calculator" << std::endl;
    std::cout << "Available options:" << std::endl;
    std::cout << "  c Calculate a square root with the currently selected method." << std::endl;
    std::cout << "  p Print the currently selected values." << std::endl;
    std::cout << "  m Change the method used." << std::endl;
    std::cout << "  i Change iteration count." << std::endl;
    std::cout << "  e Change the estimate." << std::endl;
    std::cout << "  x Exit square root calculator." << std::endl;
    std::cout << "Please  choose an option (c/p/m/i/e/x):" << std::endl;
    std::cout << "> ";
    std::cin >> menu;

    switch(menu) {
      case 'c':
        std::cout << "Please enter x: ";
        std::cin >> x;
        calc.set_value(x);
        std::cout << "Computed square root of x: ";
        std::cout << calc;
        break;
      case 'p':
        std::cout << "Currently selected method: ";
        std::cout << calc.get_method_name() << std::endl;
        std::cout << "Estimate: ";
        std::cout << calc.get_estimate() << std::endl;
        std::cout << ", iterations:";
        std::cout << calc.get_iterations() << std::endl;
        break;
      case 'm':
        int method_int;
        std::cout << "Please select a method:" << std::endl;
        std::cout << "  0 C++ sqrt" << std::endl;
        std::cout << "  1 Babylonian method" << std::endl;
        std::cout << "  2 Newton-Raphson iteration" << std::endl;
        std::cout << "  3 Exponential method" << std::endl;
        std::cout << "> ";
        std::cin >> method_int;
        method = static_cast<exercise::SqrtMethod>(method_int);
        calc.set_method(method);
        break;
      case 'i':
        std::cout << "New iterations:";
        std::cin >> n;
        calc.set_iterations(n);
        break;
      case 'e':
        std::cout << "New estimate:";
        std::cin >> a0;
        calc.set_estimate(a0);
        break;
      case 'x':
        exit = true;
        break;
      default:
        continue;
        break;
    }

    if (exit) {
      break;
    }
  }
  return 0;
}
