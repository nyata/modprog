/*
 * modern programming excercise13
 * encrypt files with symmetric key algorigthm
 * 17/12/2015 Nagisa YATA
 */

#include <fstream>
#include <iostream>

namespace exercise {

class Encrypt {
public:
  Encrypt() {}

	Encrypt(unsigned int initialize) {
		srand48(initialize);
	}

  bool encrypt_file(std::string in_name, std::string out_name) {
    // open files
    std::ifstream input(in_name);
    std::ofstream output(out_name);
    if(input.fail() || output.fail()) {
      return false;
    }

    // read file byte by byte
    char c;
    while(input.get(c)) {
      // encrypt and output
      output << sym_key(c);
    }

    // close files
    input.close();
    output.close();
    
    return true;
  }
	
private:
  char sym_key(char c) {
    return c^lrand48()%255;
  }
};

}  // namespace exercise

int main(int argc, char *argv[]) {
	if (argc < 3) return -1;
	unsigned int initialize = atoi(argv[1]);
  std::string input = argv[2];
  std::string output = argv[3];

	exercise::Encrypt enc(initialize);
  if(!enc.encrypt_file(input, output)) {
    std::cout << "error" << std::endl;
  }
  return 0;
}
