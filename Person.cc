/*
 * modern programming excercise26
 * 
 * 28/01/2016 Nagisa YATA
 */

#include <iostream>
using namespace std;

namespace exercise {

/*
 * Address
 */
class Address {
public:
  Address(){}

  Address(string str, string hnum, string pcode, string c, string cou) :
    street(str), housenumber(hnum), postcode(pcode), city(c), country(cou) {
  }

  friend ostream& operator<<(ostream& os, const Address& b);

private:
  string street;
  string housenumber;
  string postcode;
  string city;
  string country;
};

// overload operator <<
ostream& operator<<(ostream& os, const Address& a) {
  os << "street: " << a.street << endl;
  os << "housenumber: " << a.housenumber << endl;
  os << "postcode: " << a.postcode << endl;
  os << "city: " << a.city << endl;
  os << "country: " << a.country << endl;
  return os;
}

/*
 * Person class
 */
class Person {
public:
  Person() {}
  Person(string gname, string fname, Address a) :
    givenname(gname), familyname(fname), address(a) {}

  void move(Address a) {
    address = a;
  }

  friend ostream& operator<<(ostream& os, const Person& f);

private:
  Address address;
  string givenname;
  string familyname;
};

// overload operator <<
ostream& operator<<(ostream& os, const Person& h) {
  os << h.address << endl;
  os << "givenname: " << h.givenname << endl;
  os << "familyname: " << h.familyname << endl;
  return os;
}

}  // namespace exercise

int main(int argc, char *argv[]) {
  exercise::Address ad("Max-horkheimer-Str.", "16", "42119", "Wuppertal", "Germany");
  cout << ad << endl;
  
  exercise::Person yata("Nagisa", "Yata", ad);
  cout << yata << endl;

  exercise::Address move_to("Nerima-ku Nukui", "2-5-3", "1760021", "Tokyo", "Japan");
  yata.move(move_to);
  cout << yata << endl;

  return 0;
}
