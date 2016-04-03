#include <iostream>
#include <vector>
#include <fstream>

struct Hetvege {
	int szombat;
	int vasarnap;
}

void ConsolBeolvasas(int &n,int &k, std::vector<Hetvege> &data) {
	std::cin >> n;
	std::cin >> k;
	data.resize(n);
	int temp;
	for(int i = 0; i < n; ++i) {
		std::cout << "Kerem az " << i << "-edik szombat erteket: ";
		cin >> temp;
		data[i].szombat = temp;
		std::cout << "Kerem az " << i << "-edik vasarnap erteket: ";
		cin >> temp;
		data[i].vasarnap = temp;
	}
}

void FileBeolvasas(int &n,int &k, std::vector<Hetvege> &data,std::string filename) {
	std::fstream myfile(filename.c_str());
	myfile >> n;
	myfile >> k;
	data.resize(n);
	int temp;
	for(int i = 0; i < n; ++i) {
		myfile >> temp;
		data[i].szombat = temp;
		myfile >> temp;
		data[i].vasarnap = temp;
	}
}

bool OptKeres(const int &n,const int &k,const int &i,const std::vector<Hetvege> &data) {
	int kezdet = i-k;
	int veg = i;
	bool log = true;
	while(kezdet < veg && log) {
		log = (data[kezdet].szombat + data[kezdet].vasarnap) < 0;
		kezdet++;
	}
	return log;
}

bool linKeres(const int &n, const int &k,const std::vector<Hetvege> &data) {
	int i = k;
	bool log = false;
	while(i < data.size() && !log) {
		log = OptKeres(n,k,i,data) && (data[i].szombat > 0 || data[i].vasarnap > 0);
		i++;
	}
	return log;
}

int main() {
	int n,k;
	std::vector<Hetvege> data;
	ConsolBeolvasas(n,k,data);
	return 0;
}
