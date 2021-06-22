#include <iostream>
#include <cstring>
using namespace std;

class Complex {
private:
	float real, imaginary;
public:
	Complex(float _r=0.0F, float _i=0.0F) : real(_r), imaginary(_i) {}
	bool operator == (const Complex& num)const { return (real == num.real) && (imaginary == num.imaginary); }
	friend ostream& operator << (ostream& os, const Complex& num);
};
ostream& operator << (ostream& os, const Complex& num) {
	os << num.real << ", " << num.imaginary;
	return os;
}

class MyString {
private:
	char* str;
public:
	MyString(const char* const _str) {copy(_str);}
	MyString(const MyString& another) { copy(another.str); }
	MyString() = default;
	//~MyString() { delete [] str; }
	void copy(const char* const another) {
		int len = strlen(another);
		str = new char[len+1];
		for (int i = 0; i < len; i++) { str[i] = another[i]; }
		str[len] = '\0';
	}
	MyString& operator = (const MyString& another) {
		copy(another.str);
		return *this;
	}
	char operator [] (int i) const { return str[i]; }
	bool operator == (const MyString& _str)const { return (strcmp(str, _str.str) == 0); }
	friend ostream& operator << (ostream& os, const MyString& _str);
};
ostream& operator << (ostream& os, const MyString& _str) {
	int len = strlen(_str.str);
	for (int i = 0; i < len; i++) {
		os << _str.str[i];
	}
	return os;
}

template <class T, int size>
class List {
	T* pElems;
	int size;
	int currentSize;
public : 
	List() : currentSize(0) { pElems = new T[size]; }
	List(const List& another) : currentSize(another.currentSize) {
		delete[] pElems;
		pElems = new T[size];
		for (int i = 0; i < currentSize; i++) {
			pElems[i] = another[i];
		}
	}
	~List() { delete[] pElems; }
	void add(const T& anotherElem) {
		pElems = new T[size];
		pElems[currentSize] = anotherElem;
		cout << anotherElem << " is added" << endl;
		currentSize++;
	}
	int find(const T& anotherElems)const {
		for (int i = 0; i < currentSize; i++) {
			if (pElems[i] == anotherElems) {
				cout << anotherElems << " is found" << endl;
				return 0;
			}
		}
		cout << anotherElems << " is not found" << endl;
		return 0;

	}
	int remove(const T& anotherElems){
		for (int i = 0; i < currentSize; i++) {
			if (pElems[i] == anotherElems) {
				for (int j = i; j < currentSize; j++) {
					cout << anotherElems << " is removed" << endl;
					pElems[j] = pElems[j + 1];
				}
				currentSize--;
				return 0;
			}
		}
		cout << anotherElems << " is not found" << endl;
		return 0;
	}
	List& operator = (const List& L) {
		delete[] pElems;
		pElems = new T[size];
		currentSize = L.currentSize;
		for (int i = 0; i < currentSize; i++) {
			pElems[i] = L.pElems[i];
		}
		return *this;
	}
	T& operator[] (int i)const { return pElems[i]; }
	
};

int main() {
	List<Complex, 100> cList;
	List<MyString, 200> sList;
	cList.add(Complex(0, 0));
	cList.add(Complex(1, 1));
	sList.add("abc");
	sList.add("def");
	cList.find(Complex(1, 0));
	sList.find("def");
	cList.remove(Complex(0, 0));
	sList.remove("abc");
	List<MyString, 200> s2List(sList);
	List<MyString, 200> s3List;
	s3List.add("123");
	s3List = s2List;
	s3List.remove("def");
}