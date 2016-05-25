#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

enum exp {
	FILE_NOT_FOUND_EXCEPTION,
	EMPTY_FILE_EXCEPTION,
};

class Adatok {
public:
	string cim;
	string terem;
	string ido;
	int hely;
	string tipus;
	friend istream& operator>>(istream& in, Adatok& a);
};

class Output {
public:
	string cim;
	string ido;
	// A csoport
	int osszeg;
	bool cond;
	// B csoport
	int gyerekszam;
	bool cond2;
};

istream& operator>>(istream& in, Adatok& a) {
	string line;
	getline(in,line);
	stringstream ss(line);
	string tempString;
	vector<string> allTemp;
	while(ss >> tempString) {
		allTemp.push_back(tempString);
	}
	if(allTemp.size() > 4) {
		a.tipus = allTemp.back();
		allTemp.pop_back();
		a.hely = atoi(allTemp.back().c_str());
		allTemp.pop_back();
		a.ido = allTemp.back();
		allTemp.pop_back();
		a.terem = allTemp.back();
		allTemp.pop_back();
		a.cim = "";
		for(int i = 0; i < allTemp.size(); ++i) {
			a.cim += (i > 0 ? " " : "") + allTemp.at(i);
		}
	}
	return in;
}

class Enor {
private:
	fstream f;
	Adatok dt;
	Output out;
	bool isFinished;
public:
	Enor(string filename) {
		f.open(filename.c_str());
		if(!f.is_open()) {
			throw FILE_NOT_FOUND_EXCEPTION;
		}
		if(f.peek() == std::ifstream::traits_type::eof()) {
			throw EMPTY_FILE_EXCEPTION;
		}
	}
	void First() {
		f >> dt;
		isFinished = false;
		Next();
	}
	bool End() {
		return isFinished;
	}
	Output Current() {
		return out;
	}
	void Next() {
		if(f.fail()) {
			isFinished = true;
		} else {
			out.cim = dt.cim;
			out.ido = dt.ido;
			out.osszeg = 0;
			out.cond = true;
			out.gyerekszam = 0;
			out.cond2 = false;
			while( !f.fail() && out.cim == dt.cim && out.ido == dt.ido) {
				// A csoport
				if(dt.tipus == "G") {
					out.osszeg += 500;
					out.cond = false;
				} else if(dt.tipus == "D") {
					out.osszeg += 800;
				} else if(dt.tipus == "F") {
					out.osszeg += 1000;
					out.cond = false;
				}
				// B csoport
				if(dt.tipus == "G") {
					out.gyerekszam += 1;
				}
				if(dt.tipus == "D") {
					out.cond2 = true;
				}
				f >> dt;
			}
		}
	}
};

int main()
{
	try {
		Enor enor("input4.txt");
		enor.First();
		//A csoport
		Output max = enor.Current();
		bool volt = false;
		//B csoport
		Output max2 = max;
		bool volt2 = true;
		for(; !enor.End(); enor.Next()) {
			//A csoport
			if(enor.Current().osszeg > max.osszeg) {
				max = enor.Current();
			}
			if(enor.Current().cond) {
				volt = true;
			}
			//B csoport
			if(enor.Current().gyerekszam > max2.gyerekszam) {
				max2 = enor.Current();
			}
			if(!enor.Current().cond2) {
				volt2 = false;
			}
		}
		std::cout << "=========== A csoport =========== " << std::endl;
	 	std::cout << max.cim << std::endl;
		if(volt) {
			std::cout << "Volt olyan eloadas!" << std::endl;
		} else {
			std::cout << "Nem volt olyan eloadas!" << std::endl;
		}
		std::cout << "=========== B csoport =========== " << std::endl;
	 	std::cout << max2.cim << std::endl;
		if(volt2) {
			std::cout << "Volt olyan eloadas!" << std::endl;
		} else {
			std::cout << "Nem volt olyan eloadas!" << std::endl;
		}
	} catch(exp e) {
		switch(e) {
			case FILE_NOT_FOUND_EXCEPTION:
				std::cout << "Nem talalhato a file!" << std::endl;
				break;
			case EMPTY_FILE_EXCEPTION:
				std::cout << "Ures a file!" << std::endl;
				break;
			default:
				std::cout << "Ismeretlen hiba!" << std::endl;
				break;
		}
	}
	return 0;
}