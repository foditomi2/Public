#include <iostream>
#include <string>
#include <vector>
#include <sstream>
//Procedure
template <typename T>
void Swap(T &a,T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}
//Function
template<typename T>
T Osszegzes(const std::vector<T> &V1) {
	T sum = T();
	for(int i = 0; i < V1.size(); ++i) {
		sum += V1[i];
	}
	return sum;
}

int main() {
	int a = 3;
	int b = 5;
	Swap(a,b);
	std::cout << a << " " << b << std::endl;
	std::string c = "Alma";
	std::string d = "Fa";
	Swap(c,d);
	std::cout << c << " " << d << std::endl;
	std::vector<std::string> V1;
	for(int i = 0; i < 10; ++i) {
		std::stringstream ss;
		ss << i;
		std::string Result = ss.str();
		V1.push_back(Result + "a");
	}
	for(int i = 0; i < V1.size(); ++i) {
		std::cout << V1[i] << " ";
	}
	std::cout << std::endl;
	std::string e;
	e = Osszegzes(V1);
	std::cout << e << std::endl;
	
	std::vector<int> V2;
	for(int i = 0; i < 10; ++i) {
		V2.push_back(i);
	}
	int f = Osszegzes(V2);
	std::cout << f << std::endl;
}
