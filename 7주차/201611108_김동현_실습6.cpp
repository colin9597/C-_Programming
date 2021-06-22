#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString {
    char* str ;
    int size ;
public:
    MyString(){}
    MyString(const char* _str) {set(_str);}
    MyString(const MyString& other){
        size=other.size;
        str=new char[size];
        for (int i=0; i<size; i++){
            str[i]=other.str[i];
        }
    }
    ~MyString(){
        delete [] str;
    }
    void set(const char* _str){
        size=strlen(_str);
        str=new char[size];
        for (int i=0; i<size; i++){
            str[i]=_str[i];
        }
    }
    bool isEqual(MyString _str)const{
        if(strcmp(getstr(), _str.getstr())==0){return true;}
    }
    void print()const{
        for(int i=0; i<size; i++){
            cout << str[i];
        }
        cout << endl;
    }
    char* getstr()const{return str;}
};

int main() {
    MyString strs[] = {
    MyString("C"),
    MyString(),
    MyString("Java")
    } ;
    strs[1].set("C++") ;
    const MyString target("Java") ;
    for ( int i = 0 ; i < 3 ; i ++ ) {
        const MyString str(strs[i]) ;
        if ( str.isEqual(target) ) {
            cout << "[" << i << "]: " ;
            str.print() ;
            break ;
        }
    }
    for ( int i = 0 ; i < 3 ; i ++ ) {
        const MyString& str = strs[i] ;
        str.print() ;
    }
}