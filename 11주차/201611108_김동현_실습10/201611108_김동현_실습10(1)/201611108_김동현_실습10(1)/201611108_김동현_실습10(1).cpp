#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string major;
public:
	// �Ϲ����� Constructor 
	Person(const string& _name, const string& _major) : name(_name), major(_major) {}
	// Constructor delegation(���� ������)
	// Constructor���� ���� Ŭ���� ���� �ٸ� Constructor�� �� �� �ִ� ���
	Person(const string& _name) : Person(_name, "Computer Engineering") {}
	void print()const {
		cout << "�̸� : " << name << endl;
		cout << "���� : " << major << endl;
	}
};

class Student :public Person {
	int id;
public:
	Student(const string& _name, const string& _major, const int& _id)
		: Person(_name, _major), id(_id) {}
	// Constructor inheritance
	// ���� Ŭ������ ���ǵ� �����ڸ� ��ӹ޴� ���� Ŭ�������� ����� �� �ְ� �ϴ� ���
	using Person::Person;
	void ID()const {
		cout << "�й� : " << id << endl;
		cout << endl;
	}
};

int main() {
	Student s1("�赿��", "Mathematics", 201611108);
	Student s2("ȫ�浿", "Statistics");
	Student s3("ö��");

	s1.print();
	s1.ID();
	s2.print();
	cout << endl;
	s3.print();
}