/*
 * modern programming excercise10
 * date class
 * 04/12/2015 Nagisa YATA
 */

#include <iostream>

namespace exercise {

class Date {
public:
  Date(int d, int m, int y) : day(d), month(m), year(y) {
  }

  void set_date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
  }

  void print_date() {
    std::cout << day << "/" << month << "/" << year << std::endl;
  }

private:
  int day;
  int month;
  int year;
};

}  // namespace exercise

int main(int argc, char *argv[]) {
  // set date
  exercise::Date date(4, 12, 2015);
  date.print_date();

  // change date
  date.set_date(21, 2, 2016);
  date.print_date();

  return 0;
}
