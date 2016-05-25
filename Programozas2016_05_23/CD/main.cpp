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
	string name;
	int azon;
	string ido;
	string jarat;
	friend istream& operator>>(istream& in, Adatok& a);
};

class Output {
public:
	string name;
	// C csoport
	int utaz;
	bool cond;
	// D csoport
	int utazasszam;
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
		a.jarat = allTemp.back();
		allTemp.pop_back();
		a.ido = allTemp.back();
		allTemp.pop_back();
		a.azon = atoi(allTemp.back().c_str());
		allTemp.pop_back();
		a.name = "";
		for(int i = 0; i < allTemp.size(); ++i) {
			a.name += (i > 0 ? " " : "") + allTemp.at(i);
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
			out.name = dt.name;
			// C csoport
			out.utaz = 0;
			out.cond = false;
			// D csoport
			out.cond2 = true;
			out.utazasszam = 0;
			while( !f.fail() && out.name == dt.name ) {
				// C csoport
				out.utaz++;
				if(dt.jarat == "7E") {
					out.cond = true;
				}
				// D csoport
				if(dt.jarat != "7E") {
					out.cond2 = false;
				}
				out.utazasszam++;
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
		//C csoport
		double darab = 0;
		double utazasokszama;
		double atlag;
		bool volt = true;
		//D csoport
		int e7utasszam = 0;
		bool volt2 = false;
		for(; !enor.End(); enor.Next()) {
			//C csoport
			darab++;
			utazasokszama += enor.Current().utaz;
			if(!enor.Current().cond) {
				volt = false;
			}
			//D csoport
			if(enor.Current().cond2) {
				e7utasszam++;
			}
			if(enor.Current().utaz >= 5) {
				volt2 = true;
			}
		}
		std::cout << "=========== C csoport =========== " << std::endl;
		atlag = utazasokszama / darab;
	 	std::cout << atlag << std::endl;
		if(volt) {
			std::cout << "Minden utas utazott a 7E jarattal!" << std::endl;
		} else {
			std::cout << "Nem minden utas utazott a 7E jarattal!" << std::endl;
		}
		std::cout << "=========== D csoport =========== " << std::endl;
	 	std::cout << e7utasszam << std::endl;
		if(volt2) {
			std::cout << "Volt olyan utas aki legalabb 5-ször utazott!" << std::endl;
		} else {
			std::cout << "Nem volt olyan utas aki legalabb 5-ször utazott!" << std::endl;
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