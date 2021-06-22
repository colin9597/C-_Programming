#include <iostream>
#include <string>
using namespace std;

class School {
	string Campus;
	int numOfCampus;
public : 
	School() {}
	School(const string& _name) :Campus(_name) {}
	~School() {}
	string getSchoolName()const { return Campus; }
	virtual void set(const int _num) { numOfCampus = _num; }
	virtual void print()const {
		cout << "ķ�۽� �̸� : " << Campus << endl;
		cout << "�λ���б����� �� " << numOfCampus << "���� ķ�۽��� �ִ�" << endl;
		cout << endl;
	}
};

class Major : public School {
	string majorName;
	int numOfMajorBuilding;
	int numOfStudent;
public :
	Major() {}
	Major(const string& _major) :majorName(_major) {}
	~Major() {}
	string getMajorname()const { return majorName; }
	//Final virtual function
	// �Լ��� final Ű���带 ��������ν� �� �Լ��� �ٸ� Ŭ������ ��ӵ� �� ����.
	void set(const int _num)final { numOfMajorBuilding = _num; }
	virtual void count(const int st_num) { numOfStudent = st_num; }
	virtual void print()const {
		cout << "�� ������ " << majorName << "�Դϴ�." << endl;
		cout << "�����ǹ���ȣ�� " << numOfMajorBuilding << "�Դϴ�." << endl;
		cout << "���� �л����� �� " << numOfStudent << "�� �Դϴ�." << endl << endl;
	}
};

// Final Class
// class�� final Ű���带 ��������ν� �� class�� �ٸ� Ŭ������ ��ӵ� �� ����.
class Lecture final : public Major {
	string LectureName;
	int numOfAttendee;
public:
	Lecture() {}
	Lecture(const string& _lecture) : LectureName(_lecture) {}
	~Lecture() {}
	string getLectureName()const { return LectureName;}
	// Virtual function override
	// ���� Ŭ������ �����Լ��� ��ӹ޾� ���
	void count(const int At_num)override { numOfAttendee = At_num; }
	void print()const {
		cout << "���� ��� �ִ� ���Ǵ� " << LectureName << "�Դϴ�." << endl;
		cout << "�����ο� : " << numOfAttendee << "�� �Դϴ�." << endl;
	}
};

int main() {
	School school("PNU");
	school.set(4);
	school.print();
	Major major("mathematics");
	major.set(607);
	major.count(150);
	major.print();
	Lecture lecture("C++");
	// lecture.set <- Error : set�Լ��� MajorŬ������ final Ű���尡 ��� �Ǿ��� ������ (override Ű���带 ����ϴ���) ��ӹ��� �� ����.
	lecture.count(70);
	lecture.print();
}