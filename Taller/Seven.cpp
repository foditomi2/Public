#include <iostream>
#include <vector>
#include <fstream>

template<class T>
std::istream& operator>>(std::istream &in,std::vector<T> &V1) {
	int n;
	in >> n;
	T temp;
	for(int i = 0; i < n; ++i) {
		in >> temp;
		V1.push_back(temp);
	}
	return in;
}

template<class T>
std::ostream& operator<<(std::ostream &out,const std::vector<T> &V1) {
	out << V1.size() << std::endl;
	for(int i = 0; i < V1.size(); ++i) {
		out << V1[i] << " ";
	}
	return out;
}


int main() {
	std::vector<std::string> V1;
	std::fstream myfile("input.txt");
	myfile >> V1;
	std::cout << V1;
	std::cout << std::endl;
	return 0;
}
