#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum MajorType {CE, EE, ME, UD};
class Major {
private:
    MajorType majorType ;
public:
    Major(const MajorType _majorType):majorType(_majorType){}
    Major() : majorType(UD){}
    MajorType getmajorType()const{return majorType;}
};

class Student {
private:
    string name ;
    float gpa ;
    Major major ;
public:
    Student(const string& name1, const MajorType _majortype) : 
        name(name1){this->major=_majortype;}   
    Student(const string& name2, const float _gpa) :
        name(name2){this->gpa=_gpa;}
    void setGPA(const float _gpa){gpa=_gpa;}
    void setMajor(const MajorType _majortype){major=_majortype;}
    string getname()const{return name;}
    float getgpa()const{return gpa;}
    Major getmajor()const{return major;}
    void print()const{
        cout << "Name: " << getname() << " GPA : " << getgpa() << " Major: ";
        if(getmajor().getmajorType()==CE){cout << "Computer Eng.";}
        else if(getmajor().getmajorType()==EE){cout << "Electrical Eng.";}
        else if(getmajor().getmajorType()==ME){cout << "Mechanical Eng.";}
        else {cout << "UD";}
        cout << endl;
    }
};

class School {
private:
    string schoolName ;
    vector<Student> students ;
public:
    School(const string& _schoolName) : schoolName(_schoolName){} 
    Student* addStudent(const string& _name, const MajorType _majortype){
        Student st(_name, _majortype);
        students.push_back(st);
        return &students.back();
    }
    Student* addStudent(const string& _name, const float _gpa){
        Student st(_name, _gpa);
        students.push_back(st);
        return &students.back();
    }
    string getSchoolName()const{return schoolName;}
    void print()const{
        cout << "School Name: " << getSchoolName();
        cout << ", Count: " << students.size()<<endl;
        typedef vector<Student>::const_iterator iterator;
        for(iterator it=students.begin(); it!=students.end(); ++it){
            cout << "\t";
            it->print();
        }
        cout << endl;
    }
    void sort(){
        for (int i=0; i<students.size();i++){
            for(int j=i+1; j<students.size(); j++){
                Student& st=students[i];
                Student& st2=students[j];
                if(st.getgpa()<st2.getgpa()){swap(st, st2);}
            }  
        }
    }
};

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
pnu.sort() ; // descending
pnu.print() ;
}