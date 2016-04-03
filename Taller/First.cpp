#include <iostream>
#include <vector>
#include <fstream>

void teszt(std::vector<int> &V2) {
	V2.resize(10);
	for(int i = 0; i < 5; ++i) {
		V2.push_back(i);
	}
	for(int i = 0; i < V2.size(); ++i) {
		std::cout << V2[i] << " ";
	}
}

void teszt(std::vector<int> V2,int c) {
	V2.resize(10);
	for(int i = 0; i < 5; ++i) {
		V2.push_back(i);
	}
	for(int i = 0; i < V2.size(); ++i) {
		std::cout << V2[i] << " ";
	}
}

void teszt1(const std::vector<int> &V3) {
	int c = 3;
	for(int i = 0; i < V3.size(); ++i) {
		V3[i] += c;
	}
}

int main() {
	int c = 0;
	int A1[10];
	std::vector<int> V1;
	teszt(V1);
	std::cout << std::endl;
	for(int i = 0; i < V1.size(); ++i) {
		std::cout << V1[i] << " ";
	}
	std::cout << std::endl;
	teszt(V1,c);
	std::cout << std::endl;
	teszt1(V1);
	for(int i = 0; i < V1.size(); ++i) {
		std::cout << V1[i] << " ";
	}
	std::cout << std::endl;
	//V1.clear();
	{
		std::vector<int> V1;
		V1.reserve(10);
		for(int i = 0; i < 5; ++i) {
			V1.push_back(i);
		}
		for(int i = 0; i < V1.size(); ++i) {
			std::cout << V1[i] << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}
