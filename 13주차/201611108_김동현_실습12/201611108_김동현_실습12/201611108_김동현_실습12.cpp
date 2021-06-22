#include <iostream>
#include <string>
using namespace std;

class StackException {
	const string msg;
public:
	StackException(const string& msg) : msg(msg) {};
	void print() const { cout << msg << endl; }
};

class CharStack {
	int size;
	int top;
	char* s;
public:
	// destructor, copy constructor, and assignment operator
	CharStack(int sz) { 
		if (sz < 0)throw StackException("Invalid StackSize!");
		top = 0; 
		s = new char[size = sz]; 
	}
	CharStack(const CharStack& anotherCS) { copy(anotherCS);}
	~CharStack() { delete[] s; }
	CharStack& operator = (const CharStack& anotherCS) {
		copy(anotherCS);
		return *this;
	}
	void copy(const CharStack& anotherCS) {
		delete[] s;
		size = anotherCS.size;
		top = anotherCS.top;
		s = new char[size];
		for (int i = 0; i < top; i++) {
			s[i] = anotherCS.s[i];
		}
	}
	void push(char c) { 
		if (top >= size)throw StackException("Stack is full!");
		s[top++] = c; 
	}
	char pop() { 
		if (top <= 0)throw StackException("Stack is empty");
		char r = s[--top]; 
		s[top] = '\0'; 
		return r; 
	}
	void print() const {
		for (int i = 0; i < top; i++) cout << s[i];
		cout << endl;
	}
};

int main() {
	int SIZE = 20;
	CharStack cs(SIZE);
	// constructor error test
	cout << "<constructor error test>" << endl;
	try {
		CharStack cs2(-3);
	}
	catch (const StackException & e) {
		e.print();
	}
	cout << endl;

	// push error test
	cout << "<push error test>" << endl;
	string testChar = "Hello world, I'm Jieun.";
	try {
		for (int i = 0; i < testChar.size(); i++) {
			cs.push(testChar.at(i));
		}
	}
	catch (const StackException & e) {
		e.print();
	}
	cs.print();
	cout << endl;

	// copy constructor test
	cout << "<copy constructor test>" << endl;
	CharStack cs2(cs);
	cs2.print();
	cout << endl;

	// assignment operator test
	cout << "<assignment operator test>" << endl;
	CharStack cs3 = cs;
	cs3.print();
	cout << endl;

	// pop error test
	cout << "<pop error test>" << endl;
	try {
		for (int i = 0; i < SIZE + 1; i++) {
			cs.pop();
		}
	}
	catch (const StackException & e) {
		e.print();
	}
	cs.print();
	cout << endl;
}