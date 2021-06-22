#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

struct Rectangle {
    int width;
    int height;
};

enum CommandKind {ADD, SORT, PRINT, CLEAR, EXIT, INVALID};

CommandKind getCommandKind(string commandkind);
Rectangle getRectangle();
void Rprint(const Rectangle R);
void print(const vector<Rectangle>& v);
void sort(vector<Rectangle>& v);

int main() {
    vector<Rectangle> rectangles ;
    while ( true ) {
        string commandString;
        cin >> commandString;
        const CommandKind command = getCommandKind(commandString) ;
        switch ( command ) {
            case ADD : {
                const Rectangle& newRectangle = getRectangle() ;
                rectangles.push_back(newRectangle) ;
                break ;
                }
            case PRINT:
                print(rectangles) ;
                // use const_iterator in print()
                // define and call print(const Rectangle&)
                break ;
            case SORT: {
                sort(rectangles) ; // define and call swap in sort()
                print(rectangles) ;
                break ;
                }
            case CLEAR: rectangles.clear() ; break ;
            case EXIT: break ;
            default: assert (false) ; break ;
        }
        if ( command == EXIT ) break ;
    }
    return 0;
}

CommandKind getCommandKind(string commandkind){
    transform(commandkind.begin(), commandkind.end(), commandkind.begin(), ::toupper);
    if (commandkind == "ADD")
        return CommandKind(ADD);
    else if (commandkind == "SORT")
        return CommandKind(SORT);
    else if (commandkind == "PRINT")
        return CommandKind(PRINT);
    else if (commandkind == "CLEAR")
        return CommandKind(CLEAR);
    else if (commandkind == "EXIT")
        return CommandKind(EXIT);
    else
    {
        return CommandKind(INVALID);
    }
}

Rectangle getRectangle(){
    Rectangle R;
    cin >> R.height;
    cin >> R.width;
    return R;
}

void Rprint(const Rectangle R){
    cout << R.height << "\t";
    cout << R.width << "\t";
    cout << R.height*R.width << endl;
}

void print(const vector<Rectangle>& v){
    cout << "Rectangle Count: " << v.size() << endl;
    typedef vector<Rectangle>::const_iterator iterator;
    for(iterator it=v.begin(); it!=v.end(); ++it){
        Rprint(*it);
    }
}

void sort(vector<Rectangle>& v){
    for (int i=0; i<v.size(); i++){
        for (int j=i+1; j<v.size(); j++){
            int area1=v[i].height*v[i].width;
            int area2=v[j].height*v[j].width;
            if (area1>area2){
                swap(v[i], v[j]);
            }
        }
    }
}