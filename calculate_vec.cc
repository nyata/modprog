/*
 * modern programming excercise6
 * create vector from random value
 * calculate norm and average
 * 17/11/2015 Nagisa YATA
 */

#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

namespace exercise {

class Vector {
public:
  // constructor
  // initialize vector with random number
	Vector(int n, int m) : vec_length(n), max_range(m) {
    // initialize random func
    srand48((unsigned int)time(NULL));

    for (int i = 0; i < vec_length; i++) {
      vec.push_back(lrand48() % max_range + 1);
    }
	}

  // print vector element
  // maximum element is 10
  void print_vector() {
    std::cout << "--- vector element ---" << std::endl;
    int i = 0;
    for (int v : vec) {
      std::cout << v << std::endl;
      i++;
      if (vec_length < 10 && i > vec_length) break;
      if (vec_length > 10 && i > 10) break;
    }
    std::cout << "--- vector element end ---" << std::endl;
  }
	
  // get norm of vector
  double get_norm() {
    return compute_norm();
  }

  // get average of vector
  double get_average() {
    return compute_average();
  }

private:
  int vec_length;
  int max_range;
  std::vector<int> vec;

  // compute norm
  double compute_norm() {
    double sum;
    int* head = &(vec[0]);

    //for (int v : vec) {
    for (int i = 0; i < vec_length; i++) {
      sum += (*(head + i)) ^ 2;
    }

    return sqrt(sum);
  }

  // compute average
  double compute_average() {
    double sum;
    int* head = &(vec[0]);

    //for (int v : vec) {
    for (int i = 0; i < vec_length; i++) {
      sum += (*(head + i));
    }

    return sum / vec_length;
  }
};

}  // namespace excercise

int main(int argc, char *argv[]) {
  std::string n_str, m_str;

  // input parameters
  std::cout << "Please input natural number n:" << std::endl;
  std::cin >> n_str;
  std::cout << "Please input natural number m:" << std::endl;
  std::cin >> m_str;

  // parameter validation
  const char* n_char = n_str.c_str();
  for (int i = 0; i < n_str.size(); i++) {
    if (!isdigit(n_char[i])) {
      std::cout << "error: Please input natural number" << std::endl;
      exit(1);
    }
  }
  const char* m_char = m_str.c_str();
  for (int i = 0; i < m_str.size(); i++) {
    if (!isdigit(m_char[i])) {
      std::cout << "error: Please input natural number" << std::endl;
      exit(1);
    }
  }

  int n = std::stoi(n_str);
  int m = std::stoi(m_str);
  // create vector
  exercise::Vector vector(n, m);
  // print vector
  vector.print_vector();
  // compute norm of vector
  std::cout << "norm = " << vector.get_norm() << std::endl;
  // compute average of vector
  std::cout << "average = " << vector.get_average() << std::endl;
  return 0;
}
