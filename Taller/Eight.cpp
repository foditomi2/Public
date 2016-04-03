#include <iostream>
#include <fstream>
#include <vector>

class Student {
private:
	std::string name;
	int old;
	char sex;
	std::string neptun_kod;
public:
	//Konstruktor
	Student() {}
	Student(std::string n,int o,char s, std::string npk) {
		name = n;
		old = o;
		sex = s;
		neptun_kod = npk;
	}
	const std::string &getName() const {
		return name;
	}
	int getOld() {
		return old;
	}
	char getSex() {
		return sex;
	}
	std::string getNeptun_Kod() {
		return neptun_kod;
	}
	void setName(std::string n) {
		name = n;
	}
};

template<class T>
class Classmate {
private:
	T home_room_teacher;
	std::vector<T> students;
public:
	Classmate(T hrt, std::vector<T> vectorstd) {
		home_room_teacher = hrt;
		students = vectorstd;
	}
	const T& getHrt() const {
		return home_room_teacher;
	}
};

int main() {
	Student s1("Tallér Dániel",23,'F',"ATKPLS");
	Student s2("Bia",19,'N',"AKSEFL");
	std::vector<Student> vectorstd;
	vectorstd.push_back(s1); vectorstd.push_back(s2);
	Student s3("Locu",21,'F',"YTHSTN");
	const Classmate<Student> classmate(s3,vectorstd);
	std::cout << classmate.getHrt().getName() << std::endl;
	std::vector<int> intvector;
	intvector.push_back(1); intvector.push_back(2);
	Classmate<int> classmate2(3,intvector);
	std::cout << classmate2.getHrt() << std::endl;
	return 0;
}
