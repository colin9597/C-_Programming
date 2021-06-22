#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString {
    char* str ;
    int size ;
public:
    MyString(const char* newStr) { set(newStr); }
    MyString(const MyString& another)
    : str(another.str), size(another.size) {
        for ( int i = 0; i < size; i++ ) str[i] = another.str[i];
    }
    MyString() = default;
    void set(const char* newStr){
        size = strlen(newStr);
        str = new char[size];
        for ( int i = 0; i < size; i++ ) str[i] = newStr[i];
    }
    bool isEqual(MyString target) const {
        if (strcmp(str, target.getstr()) == 0) return true;
        return false;
    }
    char* getstr() const { return str; }
    void print() const {
        for ( int i = 0; i < size; i++ ) {
            cout << str[i];
        }
        cout << endl;
    };
} ;

int main(){
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

    return 0;
}