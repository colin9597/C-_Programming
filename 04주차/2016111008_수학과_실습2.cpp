#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SUBJECT_NO =3;
int total[SUBJECT_NO]={0};
int sum_total=0;

struct StudentInfo {
        string name;
        int scores[SUBJECT_NO];
        int sum;
        float average;
    };

void print(const StudentInfo st, const int k);
void Vprint(const vector<StudentInfo>& vSt, const int k);

int main()
{   
    int num_student;
    cout << "How many students are in your class?" << endl;
    cin >> num_student; 

    vector<StudentInfo> vSt;

    StudentInfo* const st = new StudentInfo[num_student];

    for (int i=0; i<num_student; i++){
        st[i].sum=0;
        cin >> st[i].name;
        for (int j=0; j<SUBJECT_NO; j++){
            cin >> st[i].scores[j];
            st[i].sum+=st[i].scores[j];
        }
        st[i].average=static_cast<float>(st[i].sum)/SUBJECT_NO;

        vSt.push_back(st[i]);        
    }
    cout << endl;   
    
    Vprint(vSt, num_student);

    delete [] st;

    return 0;
}

//print a StudentInfo
void print(const StudentInfo st, const int k){
    cout << st.name << "\t";
    for (int j=0; j<SUBJECT_NO; j++){
        cout << st.scores[j] << "\t";
        total[j]+=st.scores[j];
    }
    sum_total+=st.sum;
    cout << st.sum << "\t";
    cout << st.average << endl; 
}

//print vector<StudentInfo> by using iterator
void Vprint(const vector<StudentInfo>& vSt, const int k){
    int ord=1;
    typedef vector<StudentInfo>::const_iterator iterator;
    for(iterator it=vSt.begin(); it!=vSt.end(); ++it){
        cout << ord << "\t";
        print(*it, k);
        ord+=1;
    }
    cout << "\t" << "Total" << "\t";
    for (int j=0; j<SUBJECT_NO; j++){
        cout << total[j] << "\t";
    }
    cout << sum_total << endl;
}