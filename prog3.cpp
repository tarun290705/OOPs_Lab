/*  3. Write a C++ program to create a class called COMPLEX and implement the following overloading functions ADD that return a COMPLEX number.
    a. ADD (a, s2) – where a in an integer (real part) and s2 is a complex number.
    b. ADD (s1, s2) – where s1 and s2 are complex numbers.
*/

#include<iostream>
using namespace std;

class COMPLEX {
    private :
        float real, imag;

    public :
        void getdata(float n1, float n2);
        friend COMPLEX add(int a, COMPLEX s2);
        friend COMPLEX add(COMPLEX s1, COMPLEX s2);
        friend ostream& operator <<(ostream& print, COMPLEX& comp);    
};

void COMPLEX :: getdata(float n1, float n2) {
    real = n1;
    imag = n2;
}

COMPLEX add(int a, COMPLEX s2) {
    COMPLEX result;
    result.real = a + s2.real;
    result.imag = s2.imag;
    return result;
}

COMPLEX add(COMPLEX s1, COMPLEX s2) {
    COMPLEX result;
    result.real = s1.real + s2.real;
    result.imag = s1.imag + s2.imag;
    return result;
}

ostream& operator <<(ostream& print, COMPLEX& comp) {
    print<<comp.real<<" + i"<<comp.imag<<endl;
    return print;
}

int main() {
    float n1, n2, n3;
    COMPLEX c1, c2, c3, c4;

    cout<<"Enter real and imaginary part of 1st Complex Number : ";
    cin>>n1>>n2;
    c1.getdata(n1, n2);

    cout<<"Enter real and imaginary part of 2nd Complex Number : ";
    cin>>n1>>n2;
    c2.getdata(n1, n2);

    cout<<"Enter the number to be added to the 1st Complex Number : ";
    cin>>n3;

    c3 = add(c1, c2);
    c4 = add(n3, c2);

    cout<<"Sum of two complex numbers : "<<endl<<"C1 : "<<c1<<"C2 : "<<c2<<"Sum : "<<c3<<endl;
    cout<<"Sum of integer with complex number : "<<endl<<"C2 : "<<c2<<"Integer : "<<n3<<endl<<"Sum : "<<c4<<endl;
    return 0;
}