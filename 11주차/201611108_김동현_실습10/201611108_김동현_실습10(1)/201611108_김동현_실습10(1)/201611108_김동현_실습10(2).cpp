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
		cout << "캠퍼스 이름 : " << Campus << endl;
		cout << "부산대학교에는 총 " << numOfCampus << "개의 캠퍼스가 있다" << endl;
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
	// 함수에 final 키워드를 사용함으로써 이 함수는 다른 클래스에 상속될 수 없다.
	void set(const int _num)final { numOfMajorBuilding = _num; }
	virtual void count(const int st_num) { numOfStudent = st_num; }
	virtual void print()const {
		cout << "제 전공은 " << majorName << "입니다." << endl;
		cout << "전공건물번호는 " << numOfMajorBuilding << "입니다." << endl;
		cout << "전공 학생들은 총 " << numOfStudent << "명 입니다." << endl << endl;
	}
};

// Final Class
// class에 final 키워드를 사용함으로써 이 class는 다른 클래스에 상속될 수 없다.
class Lecture final : public Major {
	string LectureName;
	int numOfAttendee;
public:
	Lecture() {}
	Lecture(const string& _lecture) : LectureName(_lecture) {}
	~Lecture() {}
	string getLectureName()const { return LectureName;}
	// Virtual function override
	// 상위 클래스의 가상함수를 상속받아 사용
	void count(const int At_num)override { numOfAttendee = At_num; }
	void print()const {
		cout << "제가 듣고 있는 강의는 " << LectureName << "입니다." << endl;
		cout << "수강인원 : " << numOfAttendee << "명 입니다." << endl;
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
	// lecture.set <- Error : set함수는 Major클래스에 final 키워드가 사용 되었기 때문에 (override 키워드를 사용하더라도) 상속받을 수 없다.
	lecture.count(70);
	lecture.print();
}