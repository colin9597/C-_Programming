# include <vector>
# include <iostream>
# include <string>

using namespace std ;

class Student {
private:
        string name ;
        float gpa ;

public:
        Student(const string& _name, const float gpa) : name(_name) {
                this->gpa = gpa ;
        }
        string getName() const { return name ; }
        float getGPA() const { return gpa ; }

        void setName(const string& newName) { name = newName ; }
        void setGPA(const float newGPA) { gpa = newGPA ; }

        void print() const {
                cout << "Name: " << getName() << " GPA: " << getGPA() << endl ;
        }

        void swapWith(Student& other) {
                const Student temp = other ;
                other = *this ;
                *this = temp ;
        }
} ;


class School {
private:
        string schoolName ;
        vector<Student> students ;

public:
        School(const string& _schoolName) : schoolName(_schoolName) //, students()
                {}

        void addStudent(const string& name, const float gpa = 0.0F) {
                Student newStudent(name, gpa) ;
                students.push_back(newStudent) ;
        } 
        
        Student& findStudentWithName(const string& name)  { // const를 할 수가 없음; vector 내부의 Student 객체에 대한 reference를 반환하므로
                //Student& Student("", 0.0F);
                for ( unsigned int i = 0 ; i < students.size() ; i ++ ) {
                        Student& theStudent = students[i] ;
                        if ( theStudent.getName() == name ) return theStudent;
                }
                //return Student("", 0.0F) ;
        }
        void sort() {
                for ( unsigned int i = 0 ; i < students.size()-1 ; i ++ ) {
                        for ( int unsigned j = i + 1; j < students.size() ;  j ++ ) {
                                if ( students[i].getGPA() < students[j].getGPA() ) {
                                        students[i].swapWith(students[j]) ;
                                }
                        }
                }
        }
        void print() const {
                cout << "School Name: " << getSchoolName() << ", " ;
                cout << "Count: " << students.size() << endl ;
                for ( vector<Student>::const_iterator it = students.begin() ; it != students.end() ; it ++ ) {
                        cout << "\t" ;
                        it->print() ;
                }
                cout << endl ;
        }
        string getSchoolName() const { return schoolName ; }
};


int main() {
        School pnu("PNU") ;

        pnu.addStudent("Kim", 2.7F) ;
        pnu.addStudent("Hong", 3.5F) ;
        pnu.addStudent("Lee") ;
        pnu.addStudent("Joo", 1.5F) ;
        
        pnu.print() ;

        pnu.sort() ; // descending
        pnu.print() ;

        School knu("KNU") ;
        knu.addStudent("Seo", 2.5F) ;
        knu.addStudent("Lee", 3.8F) ;
        knu.print() ;


        Student& lee = pnu.findStudentWithName("Lee") ;
        lee.setGPA(3.3F) ;
        lee.setName("Yoon") ;

        pnu.print() ;

        knu.addStudent("Hong", 4.3F) ;
        Student& hong = knu.findStudentWithName("Hong") ;
        hong.setGPA(3.3F) ;
        hong.setName("Joon") ;
        knu.print() ;
} 