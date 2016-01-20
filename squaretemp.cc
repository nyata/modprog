/*
 * modern programming excercise7
 * 13/01/2016 Nagisa YATA
 */

#include <cmath>
#include <iostream>

namespace exercise {

template <class T>
T square(T x) {
  return x*x;
}

std::string operator*(const std::string& s1, const std::string& s2) {
  return s1+s2;
}

}  // namespace excercise

int main(int argc, char *argv[]) {
  std::cout << exercise::square<int>(3) << std::endl;
  std::cout << exercise::square<double>(1.1) << std::endl;
  std::cout << exercise::square<std::string>("test") << std::endl;
  return 0;
}
