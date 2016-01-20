/*
 * modern programming excercise7
 * 13/01/2016 Nagisa YATA
 */

#include <cmath>
#include <iostream>

namespace exercise {

template <class T>
class MinAdder{
public:
	MinAdder() {
		empty = true;
	}

	MinAdder<T>& newElement(T t) {
		if (empty) {
			min_address = t;
			empty = false;
			sum = t;
		} else {
			if (min_address > t) {
				min_address = t;
			}
			sum += t;
		}
		return *this;
	}

	// get minimum element
	T getMinimum() {
		if (empty) {
			std::cout << "No elements." << std::endl;
			return 0;
		}
		return min_address;
	}

	// get sum of elements
	T getSum() {
		if (empty) {
			std::cout << "No elements." << std::endl;
			return 0;
		}
		return sum;
	}

private:
	T min_address;
	T sum;
	bool empty;
};


}  // namespace excercise

int main(int argc, char *argv[]) {
	exercise::MinAdder<std::string> ms;
	ms.newElement("Alice").newElement("Charles").newElement("Bob");
	std::cout << "max(ms): " << ms.getMinimum() << std::endl;
	std::cout << "sum(ms): " << ms.getSum() << std::endl;

	exercise::MinAdder<double> ms_d;
	std::cout << "max(ms): " << ms_d.getMinimum() << std::endl;
	std::cout << "sum(ms): " << ms_d.getSum() << std::endl;
	ms_d.newElement(0.8).newElement(0.2).newElement(0.1);
	std::cout << "max(ms): " << ms_d.getMinimum() << std::endl;
	std::cout << "sum(ms): " << ms_d.getSum() << std::endl;
	return 0;
}
