/*
 * modern programming excercise7
 * 27/11/2015 Nagisa YATA
 */

#include <cmath>
#include <iostream>

namespace exercise {

class ApproximateSolution {
public:
  // babylonian method
  // calculate approximate solution sqrt(x)
  // a0: initial value
  // n : how many repeat
  double babylonian(double x, double a0, int n) {
    double ak = a0;
    for (int i = 0; i < n; i++) {
      ak = (ak + x / ak) / 2.0;
    }

    return ak;
  }
  
  // Newton-Raphson method
  // calculate approximate solution sqrt(x)
  // a0: initial value
  // n : how many repeat
  double newton_raphson(double x, double a0, int n) {
    double ak = a0;
    for (int i = 0; i < n; i++) {
      ak = ak * (3.0 - x * ak * ak) / 2.0;
    }

    return ak * x;
  }
};

}  // namespace excercise

int main(int argc, char *argv[]) {
  std::string x_str, a0_str, n_str;

  // input parameters
  std::cout << "x=";
  std::cin >> x_str;
  std::cout << "a0=";
  std::cin >> a0_str;
  std::cout << "n=";
  std::cin >> n_str;

  int n = std::stod(n_str);
  int x = std::stod(x_str);
  int a0 = std::stod(a0_str);
  // create vector
  exercise::ApproximateSolution approximate;
  // existing library
  std::cout << "C++ sqrt: " << sqrt(x) << std::endl;
  // babylonian method
  std::cout << "Babylonian method: " << approximate.babylonian(x, a0, n) << std::endl;
  // newton-raphson method
  std::cout << "Newton-Raphson method: " << approximate.newton_raphson(x, a0, n) << std::endl;
  
  return 0;
}
