/*
 * modern programming excercise12
 * 17/12/2015 Nagisa YATA
 * 21/01/2016 modified for exercise24
 */

#include "glass.h"
#include <iostream>

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
  
  // test for >>
  std::cout << "Input volume: ";
  std::cin >> gl;
  std::cout << gl;
    
  try {
    exercise::Glass gl2(0, 200);
    std::cout << gl2;
  } catch(exercise::GlassException e) {
    std::cout << e.what() << std::endl;
  }
  
  try {
    // test for empty
    drunk = gl.drink(100);
    std::cout << drunk << std::endl;
  } catch(exercise::GlassException e) {
    std::cout << e.what() << std::endl;
  }
    
  try {
    // test for overflow
    gl.fillIn(350);
    std::cout << gl;
  } catch(exercise::GlassException e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
