#include <iostream>

int main() {
	int i = 5;
	std::string alma = "alma";
	std::cout << "alma " << "teszt" << std::endl;
	operator<<(std::cout,alma);
	std::cout.operator<<(i);
	return 0;
}
