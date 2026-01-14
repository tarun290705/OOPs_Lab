/*  1. Given that an EMPLOYEE class contains following members:
    Data members: Employee_Number, Employee_Name, Basic, DA, IT, Net_Sal
    Member functions: to read the data, to calculate Net_Sal and to print data members.
    Write a C++ program to read the data of N employees and compute Net_Sal of each Employee
    (DA=52% of Basic and Income Tax (IT) = 30% of the gross salary).    
*/

#include<iostream>
using namespace std;

class Employee {
    private :
        string emp_name;
        int emp_no, basic;
        float da, it, net_sal;

    public :
        void getdata();
        void display();
        void compute(int basic);    
};

void Employee :: getdata() {
    cout<<"Enter Employee Name : ";
    cin>>emp_name;
    cout<<"Enter Employee Number : ";
    cin>>emp_no;
    cout<<"Enter Basic Salary : ";
    cin>>basic;
}

void Employee :: compute(int basic) {
    da = 0.52 * basic;
    it = 0.30 * (basic + da);
    net_sal = basic + da - it;
}

void Employee :: display() {
    compute(basic);
    cout<<"\nEmployee Name : "<<emp_name<<endl;
    cout<<"Employee Number : "<<emp_no<<endl;
    cout<<"Employee's Basic Salary : "<<basic<<endl;
    cout<<"Employee's DA : "<<da<<endl;
    cout<<"Employee's IT : "<<it<<endl;
    cout<<"Employee's Net Salary : "<<net_sal<<endl;
}

int main() {
    Employee emp[10];
    int n;

    cout<<"Enter the number of employees : ";
    cin>>n;

    for(int i=0; i<n; i++) {
        cout<<"\nEnter details of Employee "<<i+1<<" : "<<endl;
        emp[i].getdata();
    }    

    cout<<"Employee Details : "<<endl;
    for(int i=0; i<n; i++) {
        cout<<"\nEmployee "<<i+1<<" : "<<endl;
        emp[i].display();
    }

    return 0;
}