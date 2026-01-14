/*  7. Write a C++ program to create a class called DATE. Accept two valid dates in the form dd/mm/yy. Implement the following operations by overloading the operations + and -. After every operation display the results by overloading the operator<<.
    a. no_of_days = d1 – d2 ; where d1 and d2 are DATE objects, d1>=d2 and no_of_days is an integer.
    b. d2 = d1 + no_of_days; where d1 is a DATE object and no_of_days is an integer.
*/

#include<iostream>
#define MAX 100
using namespace std;

class STACK {
    private :
        int a[MAX], size, top;

    public :
        STACK(int n) {
            size = n;
            top = -1;
        }    
        friend STACK operator +(STACK s1, int ele);
        friend STACK operator --(STACK s1);
        friend int full(STACK s1);
        friend int empty(STACK s1);
        friend ostream& operator <<(ostream& print, STACK s1);
};

STACK operator +(STACK s1, int ele) {
    s1.a[++s1.top] = ele;
    return s1;
}

STACK operator --(STACK s1) {
    cout<<"The element "<<s1.a[s1.top--]<<" has been popped out of the stack"<<endl;
    return s1;
}

ostream& operator <<(ostream& print, STACK s1) {
    if(empty(s1))
        print<<"The stack is empty"<<endl;
    else {    
        print<<"Stack Status : ";
        for(int i=s1.top; i>=0; i--)
            print<<s1.a[i]<<" ";
        print<<endl; 
    }
    return print;   
}

int full(STACK s1) {
    if(s1.a[s1.top] == (s1.size-1))
        return 1;
    else
        return 0;    
}

int empty(STACK s1) {
    if(s1.a[s1.top] == -1)
        return 1;
    else    
        return 0;    
}

int main() {
    int n, choice, ele;

    cout<<"Enter the size of the stack : ";
    cin>>n;

    STACK s1(n);

    cout<<"\nMENU : "<<endl;
    cout<<"1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT"<<endl;

    do {
        cout<<"\nEnter your choice : ";
        cin>>choice;

        switch(choice) {
            case 1 : cout<<"Enter the element to be inserted : ";
                     cin>>ele;
                     if(full(s1))
                        cout<<"Stack Overflow"<<endl;
                     else 
                        s1 = s1 + ele;
                     cout<<s1;
                     break;      

            case 2 : if(empty(s1))
                         cout<<"Stack Underflow"<<endl;
                     else
                        s1 = --s1;
                     cout<<s1;
                     break;

            case 3 : cout<<s1;
                     break;

            case 4 : cout<<"Thank You!"<<endl;
                     break;

            default : cout<<"invalid Choice"<<endl;                                           
        }
    } while(choice != 4);

    return 0;
}