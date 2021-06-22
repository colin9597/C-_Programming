#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
private:
    string name ;
    float gpa ;
public:
    Student(const string& _name, const float gpa)
        : name(_name){this->gpa=gpa;}
    
    string getName()const{return name;}
    float getGPA()const{return gpa;}
    void setGPA(const float _gpa){gpa=_gpa;}
    void setName(const string& _name){name=_name;}
    void print()const{cout << "Name: " << getName() << " GPA: " << getGPA() << endl;}
} ;

class School {
private:
    string schoolName ;
    vector<Student> students ;
public:
    School(const string& _schoolName) : schoolName(_schoolName) {}

    void addStudent(const string& name, const float gpa=0.0F){
        Student s(name, gpa);
        students.push_back(s);
    }
    Student& findStudentWithName(const string& name){
        for(int i =0; i<students.size();i++){
            Student& st=students[i];
            if(st.getName()==name) return st;
        }
    }
    void sort(){
        for (int i=0; i<students.size();i++){
            for(int j=i+1; j<students.size(); j++){
                Student& st=students[i];
                Student& st2=students[j];
                if(st.getGPA()<st2.getGPA()){swap(st, st2);}
            }  
        }
    }
    void print()const{
        cout << "School Name: " << getSchoolName();
        cout << ", Count: " << students.size()<<endl;
        typedef vector<Student>::const_iterator iterator;
        for(iterator it=students.begin(); it!=students.end(); ++it){
            cout << "\t";
            it -> print();
        }
        cout << endl;
    }
    string getSchoolName() const {return schoolName;}
} ;

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
