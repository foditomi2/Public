#include <iostream>
#include <vector>
#include <fstream>

template<class T>
void Beolvas(std::vector<T> &V1) {
	int n;
	std::cin >> n;
	V1.reserve(n);
	T temp;
	for(int i = 0; i < n; ++i) {
		std::cin >> temp;
		V1.push_back(temp);
	}
}

template<class T>
void Beolvas2(std::vector<T> &V1) {
	std::fstream myfile("input.txt");
	int n;
	myfile >> n;
	V1.reserve(n);
	T temp;
	for(int i = 0; i < n; ++i) {
		myfile >> temp;
		V1.push_back(temp);
	}
}

int main() {
	std::vector<std::string> V1;
	Beolvas2(V1);
	for(int i= 0; i < V1.size(); ++i) {
		std::cout << V1[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
