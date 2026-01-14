/*  8. Write a C++ program to create a class called MATRIX using a two-dimensional array of integers. 
    Implement the following operations by overloading the operator == which checks the compatibility of two matrices to be added and subtracted. 
    Perform the addition and subtraction by overloading the operators + and – respectively. Display the results by overloading the operator <<.
    If (m1= = m2) {
        m3 = m1 + m2;
        m4 = m1 – m2;
    } else display error
*/

#include<iostream>
using namespace std;

class MATRIX {
    private :
        int row, col, a[10][10];

    public :
        MATRIX(int r, int c) {
            row = r;
            col = c;
        }    
        void getMatrix();
        int operator ==(MATRIX m1);
        MATRIX operator +(MATRIX m1);
        MATRIX operator -(MATRIX m1);
        friend ostream& operator <<(ostream& print, MATRIX& m);
};

void MATRIX :: getMatrix() {
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++) {
            cout<<"["<<i<<","<<j<<"] : ";
            cin>>a[i][j];
        }
}

int MATRIX :: operator ==(MATRIX m1) {
    if((m1.row==row) && (m1.col==col))
        return 1;
    else
        return 0;    
}

MATRIX MATRIX :: operator +(MATRIX m1) {
    MATRIX m2(row, col);
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            m2.a[i][j] = a[i][j] + m1.a[i][j];
    return m2;        
}

MATRIX MATRIX :: operator -(MATRIX m1) {
    MATRIX m2(row, col);
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            m2.a[i][j] = a[i][j] - m1.a[i][j];
    return m2;        
}

ostream& operator <<(ostream& print, MATRIX& m) {
    for(int i=0; i<m.row; i++) {    
        for(int j=0; j<m.col; j++)
            print<<m.a[i][j]<<" ";
        print<<endl;
    }
    return print;    
}

int main() {
    int m, n, p, q;

    cout<<"Enter the order of first matrix : ";
    cin>>m>>n;
    MATRIX m1(m, n);

    cout<<"Enter the order of second matrix : ";
    cin>>p>>q;
    MATRIX m2(p, q);

    if(m1 == m2) {
        cout<<"Enter the elements of first matrix : "<<endl;
        m1.getMatrix();

        cout<<"Enter the elements of second matrix : "<<endl;
        m2.getMatrix();

        MATRIX m3(m, n), m4(m, n);
        m3 = m1 + m2;
        m4 = m1 - m2;

        cout<<"Addition : "<<endl;
        cout<<m1<<" + "<<endl<<m2<<" = "<<endl<<m3<<endl;
        cout<<"Subtraction : "<<endl;
        cout<<m1<<" - "<<endl<<m2<<" = "<<endl<<m4<<endl;
    } else
        cout<<"Two given matrices are non-compactible"<<endl;

    return 0;    
}