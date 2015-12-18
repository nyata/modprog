/*
 * modern programming excercise12
 * 17/12/2015 Nagisa YATA
 */

#include <iostream>

namespace exercise {

class Glass {
public:
  Glass(){}

  Glass(unsigned int v = 100, unsigned int n = 0) {
    volume = v;
    fillIn(n);
  }

  void fillIn(unsigned int fi) {
    if(fi + content > volume) {
      content = volume;
    } else {
      content += fi;
    }
  }

  unsigned int drink(unsigned int dr) {
    unsigned int drunk = dr;
    if(content < dr) {
      content = 0;
      drunk = content;
    } else {
      content -= dr;
    }
    return drunk;
  }

  friend std::ostream& operator<<(std::ostream& os, const Glass& g);
  friend std::istream& operator>>(std::istream& is, Glass& g);

private:
  unsigned int volume;
  unsigned int content;
};

// overload operator <<
std::ostream& operator<<(std::ostream& os, const Glass& g) {
  os << "volume: " << g.volume << ", content: " << g.content << std::endl;
  return os;
}

// overload operator >>
std::istream& operator>>(std::istream& is, Glass& g) {
  is >> g.volume;
  g.content = 0;
  return is;
}

}  // namespace exercise

int main(int argc, char *argv[]) {
  // test for constructor and <<
  exercise::Glass gl(300, 200);
  std::cout << gl;
  
  // test for fillIN
  gl.fillIn(50);
  std::cout << gl;
  
  // test for drink
  unsigned int drunk = gl.drink(200);
  std::cout << drunk << std::endl;
  
  // test for empty
  drunk = gl.drink(100);
  std::cout << drunk << std::endl;
  
  // test for overflow
  gl.fillIn(350);
  std::cout << gl;

  // test for >>
  std::cout << "Input volume: ";
  std::cin >> gl;
  std::cout << gl;
  return 0;
}
