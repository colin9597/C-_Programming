#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    cout << "Enter the score count: ";
    int maxsize;
    cin >> maxsize;
   
    string input;
    const char* cmd=input.c_str();
    float total =0;
    int cnt=0;
    int* const scores = new int[maxsize];
    
    while(stricmp(cmd, "quit")!=0){
        cout << "Enter command: (add, sum, average, quit) ";
        cin >> input;
        if (stricmp(cmd, "add")==0){
            if(cnt<maxsize){
                cout << "Enter score: ";
                cin >> scores[cnt];
                if(scores[cnt]<0||scores[cnt]>100){
                    cout<<"Scores shoud be between 0 and 100" << endl;
                }
                else{
                    cout << scores[cnt] << " added" << endl;
                    cnt += 1;
                }
            }
            else {
                cout << "Too many scores" << endl;
            }
        }
        else if(stricmp(cmd, "sum")==0){
            total=0;
            for(int i=0; i<cnt; i++){
                total+=scores[i];
            }
            cout << "Sum: " << total << endl;
        }
        else if(stricmp(cmd, "average")==0){
            total=0;
            for(int i=0; i<cnt; i++){
                total+=scores[i];
            }
            float avg = total/cnt;
            cout << "Average: " << avg << endl;
        }
    }
    cout << "Bye" << endl;

    delete [] scores;
    
    return 0;
}