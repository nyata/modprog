/*
 * modern programming excercise16
 * house class
 * 05/01/2016 Nagisa YATA
 */

#include <iostream>

namespace exercise {

enum class HouseType {
  HISTRIC,
  OLD,
  NEW
};

class House : public Building {
public:

private:
  HouseType type;
};
}  // namespace exercise
