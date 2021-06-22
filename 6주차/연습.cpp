#include <iostream>
#include <string>
#include <vector>

using namespace std ;

enum MajorType { CE, EE, ME, UD};

class Major {
private:
	MajorType majorType ;
public:
	Major(const MajorType M) {
		majorType = M ;
	}
	Major() {
		majorType = UD ;
	}
	MajorType getMajorType() {
		return majorType ;
	}
} ;

class Student {
private:
	string name ;
	float gpa ;
	Major major ;
public:
	Student(const string n2, const MajorType& m2) {
		name = n2 ;
		major = m2 ;
	}
	Student(const string n3, const float g3) {
		name = n3 ;
		gpa = g3 ;
	}
	void setGPA(const float G) {
		gpa = G ;
	}
	void setMajor(const MajorType& M) {
		major = M ;
	}
	
	void print() {
		cout << "	Name: " << name << " GPA: " << gpa << " Major: " ;
		switch (major.getMajorType()) {
			case CE:
				cout << "Computer Eng." << endl ;
				break ;
			case EE:
				cout << "Electrical Eng." << endl ;
				break ;
			case ME:
				cout << "Mechanical Eng." << endl ;
				break ;
			case UD:
				cout << "UD." << endl ;
		}
	}
	float getgpa() {
		return gpa ;
	}
} ;

class School {
private:
	string schoolName ;
	vector<Student> students ;
public:
	School(string n1) {
		schoolName = n1 ;
	}
	Student* addStudent(const string n, const MajorType& m) {
		Student temp(n, m) ;
		students.push_back(temp) ;
        Student* n1;
        *n1=temp;
		return n1 ;
	}
	Student* addStudent(const string n, const float g) {
		Student temp(n, g) ;
		students.push_back(temp) ;
        Student* n2;
        *n2=temp;
		return n2 ;
	}
	void print() {
		cout << "School Name: " << schoolName << ", Count: " << students.size() << endl ;
		typedef vector<Student>::iterator iterator;
		for (iterator it = students.begin(); it != students.end(); it++) {
			(*it).print() ;
		}
		cout << "" << endl ;
	}
	void sort() {
		typedef vector<Student>::iterator iterator;
		for (int j=1; j<students.size()+1; j++){
			for (iterator it = students.begin(); it != students.end()-j; it++) {
				if ((*it).getgpa() < (*(it+1)).getgpa())
					swap (*it, *(it+1)) ;	
			}
		}
	}
	void swap(Student& n1, Student& n2) {
		Student temp = n1 ;
		n1 = n2 ;
		n2 = temp;
	}
} ;

int main() {
	School pnu("PNU") ;
	
	Student* kim = pnu.addStudent("Kim", EE) ;
	kim->setGPA(3.5F) ;
	
	Student* hong = pnu.addStudent("Hong", CE) ;
	hong->setGPA(4.3F) ;
	
	Student* lee = pnu.addStudent("Lee", 4.0F) ;
	lee->setMajor(CE) ;
	
	Student* joo = pnu.addStudent("Joo", 1.5F) ;
	joo->setMajor(ME) ;
	
	pnu.print() ;
	
	pnu.sort() ;
	pnu.print() ;
	
	return 0 ;
}