/*
 * modern programming excercise16
 * building class
 * 05/01/2016 Nagisa YATA
 */

#include <iostream>

namespace exercise {

enum class HouseType {
  HISTRIC,
  OLD,
  NEW
};

/*
 * Building
 */
class Building {
public:
  Building(){}

  Building(std::string str, unsigned int num) :
    street(str), number(num) {
  }

  friend std::ostream& operator<<(std::ostream& os, const Building& b);

protected:
  std::string street;
  unsigned int number;
};

// overload operator <<
std::ostream& operator<<(std::ostream& os, const Building& b) {
  os << "street: " << b.street << ", number: " << b.number << std::endl;
  return os;
}

/*
 * House class
 */
class House : public Building {
public:
  House() {}

  House(std::string str, unsigned int num, HouseType t)
    : Building(str, num), type(t) {
  }
  friend std::ostream& operator<<(std::ostream& os, const House& f);

protected:
  HouseType type;
};

// overload operator <<
std::ostream& operator<<(std::ostream& os, const House& h) {
  os << "street: " << h.street << ", number: " << h.number << std::endl;
  std::string type = "";
  switch(h.type) {
    case HouseType::HISTRIC:
      type = "Histric";
      break;
    case HouseType::NEW:
      type = "New";
      break;
    case HouseType::OLD:
      type = "Old";
      break;
    default:
      type = "Histric";
      break;
  }
  os << "house type: " << type << std::endl;
  return os;
}

/*
 * Factory building class
 */
class FactoryBuilding : public Building {
public:
  FactoryBuilding() {}

  FactoryBuilding(std::string str, unsigned int num, std::string name)
    : Building(str, num), company(name) {
  }

  friend std::ostream& operator<<(std::ostream& os, const FactoryBuilding& f);

protected:
  std::string company;
};

// overload operator <<
std::ostream& operator<<(std::ostream& os, const FactoryBuilding& f) {
  os << "street: " << f.street << ", number: " << f.number << std::endl;
  os << "company name: " << f.company << std::endl;
  return os;
}

/*
 * Privately owned home class
 */
class PrivatelyOwnedHome : public House {
public:
  PrivatelyOwnedHome() {}

  PrivatelyOwnedHome(std::string str, unsigned int num, HouseType t, std::string name)
    : House(str, num, t), owner(name) {
  }

  friend std::ostream& operator<<(std::ostream& os, const PrivatelyOwnedHome& p);

private:
  std::string owner;
};

// overload operator <<
std::ostream& operator<<(std::ostream& os, const PrivatelyOwnedHome& p) {
  os << "street: " << p.street << ", number: " << p.number << std::endl;
  std::string type = "";
  switch(p.type) {
    case HouseType::HISTRIC:
      type = "Histric";
      break;
    case HouseType::NEW:
      type = "New";
      break;
    case HouseType::OLD:
      type = "Old";
      break;
    default:
      type = "Histric";
      break;
  }
  os << "house type: " << type << ", owner: " << p.owner << std::endl;
  return os;
}

/*
 * Block of flats class
 */
class BlockOfFlats : public House {
public:
  BlockOfFlats() {}

  BlockOfFlats(std::string str, unsigned int num, HouseType t, std::string name, unsigned int f_num)
    : House(str, num, t), landload(name), flat_num(f_num) {
      if (f_num < 1) {
        std::cout << "Error" << std::endl;
        flat_num = 1;
      }
  }

  friend std::ostream& operator<<(std::ostream& os, const BlockOfFlats& b);

private:
  std::string landload;
  unsigned int flat_num;
};

// overload operator <<
std::ostream& operator<<(std::ostream& os, const BlockOfFlats& b) {
  os << "street: " << b.street << ", number: " << b.number << std::endl;
  std::string type = "";
  switch(b.type) {
    case HouseType::HISTRIC:
      type = "Histric";
      break;
    case HouseType::NEW:
      type = "New";
      break;
    case HouseType::OLD:
      type = "Old";
      break;
    default:
      type = "Histric";
      break;
  }
  os << "house type: " << type << ", owner: " << b.landload << ", number of flats: " << b.flat_num << std::endl;
  return os;
}

}  // namespace exercise

int main(int argc, char *argv[]) {
  exercise::Building b[5];

  exercise::Building b0("Max-Horkheimer-Str.", 16);
  exercise::House b1("Max-Horkheimer-Str", 16, exercise::HouseType::HISTRIC);
  exercise::FactoryBuilding b2("Max-Horkheimer-Str", 16, "Wuppertal University");
  exercise::PrivatelyOwnedHome b3("Max-Horkheimer-Str", 16, exercise::HouseType::NEW, "Nagisa");
  exercise::BlockOfFlats b4("Max-Horkheimer-Str", 16, exercise::HouseType::OLD, "University", 100);

  b[0] = b0;
  b[1] = b1;
  b[2] = b2;
  b[3] = b3;
  b[4] = b4;

  for(int i = 0; i < 5; i++) {
    std::cout << b[i];
  }

  std::cout << b0;
  std::cout << b1;
  std::cout << b2;
  std::cout << b3;
  std::cout << b4;
  return 0;
}
