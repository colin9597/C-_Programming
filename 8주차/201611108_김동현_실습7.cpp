#include <iostream>
using namespace std;

class Matrix {
    int** values ;
    int row, column ;
public:
    Matrix(){}
    Matrix(int _row, int _column){
        row=_row; 
        column=_column;
        values=new int*[_row];
        for(int i=0; i<_row;i++){
            values[i]=new int[_column];
        }
    }
    Matrix(const Matrix& another){duplicate(another);}
    ~Matrix(){
        for(int i=0; i<row; i++){
            delete[] values[i];
        }
        delete [] values;
    }
    void duplicate(const Matrix& another){
        for(int i=0; i<another.row; i++){
            delete[] values[i];
        }
        delete [] values;
        row=another.row;
        column=another.column;
        values=new int*[another.row];
        for(int i=0; i<another.row; i++){
            values[i]=new int[another.column];
        }
        for(int i=0; i<another.row; i++){
            for(int j=0; j<another.column; j++){
                values[i][j]=another.values[i][j];
            }
        }
    }    
    Matrix operator  + (const Matrix& m)const{
        Matrix m_3(m.row, m.column);
        for(int i=0; i<m.row; i++){
            for(int j=0; j<m.column; j++){
                m_3.values[i][j]=values[i][j]+m.values[i][j];
            }
        }
        return m_3;
    }
    Matrix operator * (const int n)const{
        Matrix m_4(row, column);
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                m_4.values[i][j]=values[i][j]*10;
            }
        }
        return m_4;
    }
    Matrix& operator = (const Matrix& another){duplicate(another);}
    friend istream& operator >> (istream& is, Matrix& m);
    friend ostream& operator << (ostream& os, const Matrix& m);
};
istream& operator >> (istream& is, Matrix& m){
    for(int i=0; i<m.row; i++){
        for(int j=0; j<m.column; j++){
            is >> m.values[i][j];
        }
    }
    return is;
}
ostream& operator << (ostream& os, const Matrix& m){
    for(int i=0; i<m.row; i++){ 
        for(int j=0; j<m.column; j++){
            os << m.values[i][j] << "\t";
        }
        os << endl;
    }
    return os;  
}

int main() {
    Matrix m1(2, 2), m2(2, 2) ;
    cin >> m1 ;
    cin >> m2 ;
    Matrix m3(m1 + m2);
    Matrix m4(2, 2);
    m4 = m3 * 10 ;
    cout << m3 << endl << m4 << endl ;
}