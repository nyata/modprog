/*
 * exercise 22
 * STL
 * 20/01/2016 Nagisa YATA
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <tuple>

using namespace std;

namespace exercise {
void print(tuple<int, int, int> triple) {
  int a = get<0>(triple);
  int b = get<1>(triple);
  int c = get<2>(triple);

  if (a * a + b * b == c * c) {
    cout << a
         << ", " << b
         << ", " << c << endl;
  }
}

class PrintPythagorean {
public:
  PrintPythagorean(ostream& o) : os(o) {}
  ostream& operator()(tuple<int, int, int> triple) {
    int a = get<0>(triple);
    int b = get<1>(triple);
    int c = get<2>(triple);

    if (a * a + b * b == c * c) {
      os << a
         << ", " << b
         << ", " << c << endl;
    }
    return os;
  }
private:
  ostream& os;
};
}  // namespace exercise

int main() {
  list<tuple<int, int, int>> tlist;
  int n = 10;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        tlist.push_back(make_tuple(i,j,k));
      }
    }
  }

  // passing a function
  cout << "Passing a function" << endl;
  for_each(tlist.begin(), tlist.end(), exercise::print);
  
  // passing a function object
  cout << "Passing a function object" << endl;
  for_each(tlist.begin(), tlist.end(), exercise::PrintPythagorean(cout));

  // using a lambda expression
  cout << "Using a lambda expression" << endl;
  for_each(tlist.begin(), tlist.end(),
           [] (tuple<int, int, int> triple) {
              int a = get<0>(triple);
              int b = get<1>(triple);
              int c = get<2>(triple);

              if (a * a + b * b == c * c) {
                cout << a
                     << ", " << b
                     << ", " << c << endl;
              }
          });
}
