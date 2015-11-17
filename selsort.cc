/*
 * modern programming excercise1
 * sort array
 * 23/10/2015 Nagisa YATA
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

namespace exercise {

class Sort {
public:
	Sort(int l) : array_length(l) {
		srand((unsigned int)time(NULL));
	}
	
	// sort array by select sort algorithm
	void select_sort(int *array) {
		for (int i = 0; i < array_length; i++) {
			int min = i;
			for (int j = i; j < array_length; j++) {
				if (array[j] < array[min]) {
					min = j;
				}
			}
			swap(&array[i], &array[min]);
		}
	}
	
	// create array whose value is given by random
	void create_array(int *array) {
		for (int i = 0; i < array_length; i++) {
			array[i] = rand();
		}
	}
	
private:
	int array_length;
	
	// swap function
	void swap(int* num1, int* num2) {
		int tmp = *num1;
		*num1 = *num2;
		*num2 = tmp;
	}
};

}  // namespace excercise

int main(int argc, char *argv[]) {
	if (argc < 1) return -1;
	int array_length = atoi(argv[1]);
	std::cout << array_length << "\n";
	int array[array_length];
	exercise::Sort sort(array_length);
	
	// create array
	std::cout << "\n----original array----\n";
	sort.create_array(array);
	for (int i = 0; i < array_length; i++) {
		std::cout << array[i] << "\n";
	}
	
	// sort array
	std::cout << "\n----sort----\n";
	sort.select_sort(array);
	for (int i = 0; i < array_length; i++) {
		std::cout << array[i] << "\n";
	}
}