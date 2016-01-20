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

class PrintTuple {
public:
private:
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
  for_each(tlist.begin(), tlist.end(), exercise::print);
  // passing a function object
  // using a lambda expression
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
