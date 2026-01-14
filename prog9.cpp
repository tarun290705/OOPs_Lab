/*  9. Write a C++ program to create a class called OCTAL which has the characteristics of an octal number. Implement the following operations by writing an appropriate constructor and an overloaded operator +.
    a. OCTAL h = x; where x is an integer.
    b. Int y = h + k; where h is an OCTAL object and k is an integer.
    Display the OCTAL result by overloading the operator <<. Also display the values of h and Y.
*/

#include<iostream>
#include<math.h>
using namespace std;

class OCTAL {
    private :
        int oct[15], count;

    public : 
        OCTAL(int x);
        int operator +(int k);
        friend ostream& operator <<(ostream& print, OCTAL o);    
};

OCTAL :: OCTAL(int x) {
    int i= 0, rem, a[15], n;

    while(x != 0) {
        rem = x % 8;
        x /= 8;
        a[i++] = rem;
    }
    count = i;
    n = count - 1;
    for(i=0; i<count; i++) {
        oct[i] = a[n];
        n--;
    }
}

int OCTAL :: operator +(int k) {
    int x = 0, j = count - 1;

    for(int i=0; i<count; i++) {
        x = x + (oct[j]*pow(8,i));
        j--;
    }
    return (x + k);
}

ostream& operator <<(ostream& print, OCTAL o) {
    for(int i=0; i<o.count; i++)
        print<<o.oct[i];
    return print;    
}

int main() {
    int x, k, y;

    cout<<"Enter the integer value of x : ";
    cin>>x;
    OCTAL h = OCTAL(x);
    cout<<"Octal equivalent of "<<x<<" is "<<h<<endl;

    cout<<"Enter the integer to be added to the octal value : ";
    cin>>k;
    y = x + k;
    cout<<h<<"(Octal) + "<<k<<"(Decimal) = "<<y<<"(Decimal)"<<endl;
    
    return 0;
}