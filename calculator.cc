/*
 * modern programming excercise5
 * calculator program
 * 17/11/2015 Nagisa YATA
 */

#include <iostream>
#include <string>
#include <vector>

namespace exercise {

class Calculator {
public:
	Calculator() {
	}
	
  std::string calculate(std::string formula) {
    std::string delimitor = formula;
    std::vector<std::string> param = split_formula(formula);
   
    if(param.size() < 3) {
      return "error: operator does not defined";
    }

    // validate
    if(!is_number(param[1]) || !is_number(param[2])) {
      return "error: not a number";
    }

    // calculate value
    if(param[0] == "#") {
      return "exit";
    } else if(param[0] == "+") {
      return std::to_string(std::stod(param[1]) + std::stod(param[2]));
    } else if(param[0] == "-") {
      return std::to_string(std::stod(param[1]) - std::stod(param[2]));
    } else if(param[0] == "/") {
      if(std::stod(param[2]) == 0) {
        return "error: division by zero";
      } else {
        return std::to_string(std::stod(param[1]) / std::stod(param[2]));
      }
    } else if(param[0] == "*") {
      return std::to_string(std::stod(param[1]) * std::stod(param[2]));
    } else {
      return "error: operator does not defined";
    }
  }

private:
  std::string delimitor[6] = {"+", "-", "*", "/", "#"};

  // split formula by delimtiors
  std::vector<std::string> split_formula(std::string formula) {
    std::vector<std::string> numbers;
    int position = 0;

    // find delimitor
    std::string delim = find_delimitor(formula, position);
    if(delim == "") {
      return numbers;
    }
    numbers.push_back(delim);

    int found;
    // devide number by delimitor
    while ((found = formula.find(delim, position)) != std::string::npos) {
      numbers.push_back(std::string(formula, position, found - position));
      position = found + 1;

      // application ver.,
      // delim = find_delimitor(formula, position);
      // if(delim == "") {
      //  break;
      // }
    }
    numbers.push_back(std::string(formula, position, formula.size() - position));

    return numbers;
  }

  // find delimitor in formula from start position
  std::string find_delimitor(std::string formula, int start_pos) {
    for(std::string d : delimitor) {
      if(formula.find(d, start_pos) != std::string::npos) {
        return d;
      }
    }
    std::cout << "error: unknown operator" << std::endl;
    return "";
  }

  // check number
  bool is_number(std::string num) {
    std::vector<std::string> numbers;
    int found;
    int position = 0;
    // devide number by delimitor
    while ((found = num.find(".", position)) != std::string::npos) {
      numbers.push_back(std::string(num, position, found - position));
      position = found + 1;
    }
    numbers.push_back(std::string(num, position, num.size() - position));
    
    if(numbers.size() > 2) return false;
    for(std::string n : numbers) {
      const char* str = n.c_str();
      for(int i = 0; i < n.size(); i++) {
        if(!isdigit(str[i])) return false;
      }
    }
    return true;
  }
};

}  // namespace exercise

int main(int argc, char *argv[]) {
  std::string formula;
  exercise::Calculator calc;
  
  std::cout << "Please input fomula(like doublevalue1 operator doublevalue)\n";
  std::cout << "Operators +,-,*,/ are allow\n";
  std::cout << "Operator # terminates the program: \n";

  while(1) {
    // input fomula
    std::cin >> formula;
    
    std::string result = calc.calculate(formula);
    std::cout << result << "\n";
    if(strstr(result.c_str(), "error")) {
      continue;
    }
    if(result == "exit") break;
  }
  return 0;
}
