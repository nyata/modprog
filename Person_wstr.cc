/*
 * modern programming excercise27
 * 
 * 28/01/2016 Nagisa YATA
 */

#include <iostream>
#include <locale>
#include <string>

using namespace std;

namespace exercise {
/*
 * Person class
 */
template <class T>
class Person {
public:
  Person() {}
  Person(T gname, T fname) :
    givenname(gname), familyname(fname) {}

  friend ostream& operator<<(ostream& os, const Person<string>& f);
  friend wostream& operator<<(wostream& os, const Person<wstring>& f);

private:
  T givenname;
  T familyname;
};

// overload operator <<
ostream& operator<<(ostream& os, const Person<string>& h) {
  cout << "string" << endl;
  os << "givenname: " << h.givenname << endl;
  os << "familyname: " << h.familyname << endl;
  return os;
}
// overload operator <<
wostream& operator<<(wostream& os, const Person<wstring>& h) {
  os << "givenname: " << h.givenname << endl;
  os << "familyname: " << h.familyname << endl;
  return os;
}

}  // namespace exercise

int main(int argc, char** argv) {
  locale::global(locale(""));
  if (argc == 2 && string(argv[1]) == "char") {
    cout << "test for string" << endl;
    // string
    string gname = "Nagisa";
    string fname = "Yata";
    exercise::Person<string> p(gname, fname);
    cout << p << endl;
  } else {
    wcout << "test for wstring" << endl;
    wstring wgname = L"なぎさ";
    wstring wfname = L"やた";
    exercise::Person<wstring> p2(wgname, wfname);
    wcout << p2;
    wstring wgname3 = L"ü";
    wstring wfname3 = L"äö";
    exercise::Person<wstring> p3(wgname3, wfname3);
    wcout << p3;
  }

  return 0;
}
