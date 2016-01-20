/*
 * modern programming excercise16
 * factory building class
 * 05/01/2016 Nagisa YATA
 */

#include <iostream>

namespace exercise {

class FactoryBuilding : public Building {
public:
  FactoryBuilding() {}

  FactoryBuilding(std::string str, unsigned int num, std::string name)
    : Building(str, num), company(name) {
  }
private:
  std::string company;
};

// overload operator <<
std::ostream& operator<<(std::ostream& os, const FactoryBuilding& f) {
  os << "street: " << f.street << ", number: " << f.number << std::endl;
  os << "company name: " << f.company << std::endl;
  return os;
}

}  // namespace exercise

int main(int argc, char *argv[]) {
  exercise::FactoryBuilding factory("Max-Horkheimer-Str.", 16, "WuppertalDomi");
  std::cout << factory;
}
