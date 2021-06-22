#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string major;
public:
	// 일반적인 Constructor 
	Person(const string& _name, const string& _major) : name(_name), major(_major) {}
	// Constructor delegation(위임 생성자)
	// Constructor에서 같은 클래스 내의 다른 Constructor를 쓸 수 있는 기능
	Person(const string& _name) : Person(_name, "Computer Engineering") {}
	void print()const {
		cout << "이름 : " << name << endl;
		cout << "전공 : " << major << endl;
	}
};

class Student :public Person {
	int id;
public:
	Student(const string& _name, const string& _major, const int& _id)
		: Person(_name, _major), id(_id) {}
	// Constructor inheritance
	// 상위 클래스에 정의된 생성자를 상속받는 하위 클래스에서 사용할 수 있게 하는 기능
	using Person::Person;
	void ID()const {
		cout << "학번 : " << id << endl;
		cout << endl;
	}
};

int main() {
	Student s1("김동현", "Mathematics", 201611108);
	Student s2("홍길동", "Statistics");
	Student s3("철수");

	s1.print();
	s1.ID();
	s2.print();
	cout << endl;
	s3.print();
}