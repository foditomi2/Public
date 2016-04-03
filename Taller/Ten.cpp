#include <iostream>

int main() {
	const int i = 5;
	int j = 6;
	const int * const p = &i;
	std::cout << *p << std::endl;
	//p = &j;
	//*p = 7;
	std::cout << *p << std::endl;
	std::cout << i << " " << j << std::endl;
	return 0;
}

