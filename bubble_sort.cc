/*
 * exercise 23
 * STL for bubblesort
 * 20/01/2016 Nagisa YATA
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>

using namespace std;

namespace exercise {
template<class T>
list<T> Bubblesort(list<T> list) {
  for (auto i = list.begin(); i != list.end(); i++) {
    for (auto j = list.begin(); j != i; j++) {
      if (*i < *j) {
        iter_swap(i, j);
        /*auto tmp = i;
        i = j;
        j = tmp;*/
      }
    }
  }
/*  cout << "start" << endl;
  int list_size = list.size();
  for (int i = 0; i < list_size; i++) {
    int j = 0;
    int *prev;
    cout << "i: " << i << endl;
    for (int& aj : list) {
      cout << j << endl;
      if (j == 0) {
        prev = &aj;
        j++;
        continue;
      }
      if (j >= list_size-i-2) break;
      cout << aj << "," << *prev << endl;
      cout << (aj<*prev) << endl;
      if (aj < *prev) {
        cout << "change" << endl;
        int *tmp = &aj;
        aj = *prev;
        prev = tmp;
      }
      j++;
    }
  }
*/
  return list;
}
}  // namespace exercise

int main() {
  srand(static_cast<unsigned int>(time(NULL)));
  
  // int
  cout << "----- int -----" << endl;
  list<int> elements;
  int elem_num = 10;
  for (int i = 0; i < elem_num; i++) {
    elements.push_back(rand()%elem_num);
  }
  for(const auto& elem : elements) {
    cout << elem << endl;
  }
  list<int> result = exercise::Bubblesort<int>(elements);
  cout << "----- bubble sort -----" << endl;
  for(const auto& elem : result) {
    cout << elem << endl;
  }
  
  // double
  cout << "----- double -----" <<endl;
  list<double> elements2;
  for (int i = 0; i < elem_num; i++) {
    elements2.push_back(rand());
  }
  for(const auto& elem : elements2) {
    cout << elem << endl;
  }
  list<double> result2 = exercise::Bubblesort<double>(elements2);
  cout << "----- bubble sort -----" << endl;
  for(const auto& elem : result2) {
    cout << elem << endl;
  }
}
