/*
 * modern programming excercise12
 * 17/12/2015 Nagisa YATA
 * 21/01/2016 modified for exercise24
 */

#include <iostream>
#include "glass.h"

namespace exercise {
/*
 * Exception class
 */
GlassException::GlassException(ExceptionType t) : type(t) {}
GlassException::GlassException(ExceptionType t, std::string w)
  : type(t), where(w) {}

std::string GlassException::what() {
  std::string message = "Error in class glass: ";
  switch (type) {
    case ExceptionType::OVERFLOW:
      message += "overflow from container";
      break;
    case ExceptionType::UNDERFLOW:
      message += "underflow from container";
      break;
    case ExceptionType::INVALID:
      message += "invalid value";
      break;
    default:
      message += "unknown error";
  }
  if (!where.empty()) {
    message += (" in " + where);
  }

  return message + ".";
}

/*
 * Glass class
 */
Glass::Glass(unsigned int v, unsigned int n) {
  if (v <= 0) {
    volume = 100;
    throw GlassException(GlassException::ExceptionType::INVALID, "45");
  } else {
    volume = v;
  }
  fillIn(n);
}

void Glass::fillIn(unsigned int fi) {
  if(fi + content > volume) {
    content = volume;
    throw GlassException(GlassException::ExceptionType::OVERFLOW, "55");
  } else {
    content += fi;
  }
}

unsigned int Glass::drink(unsigned int dr) {
  unsigned int drunk = dr;
  if(content < dr) {
    content = 0;
    drunk = content;
    throw GlassException(GlassException::ExceptionType::UNDERFLOW, "66");
  } else {
    content -= dr;
  }
  return drunk;
}

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
