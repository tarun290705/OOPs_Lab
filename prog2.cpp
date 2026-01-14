/*  2. Define a STUDENT class with USN, Name, and Marks in 3 tests of a subject.
    Declare an array of 10 STUDENT objects. Using appropriate functions, find the average of two better marks for each student. Print the USN, Name and the average marks of all the students.
*/

#include<iostream>
#define MAX 10
#define N 3
using namespace std;

class Student {
    private :
        int marks[N];
        string name, usn;

    public :
        void getdata();
        void display();
        float avg(int marks[]);
};

void Student :: getdata() {
    cout<<"Enter Student Name : ";
    cin>>name;
    cout<<"Enter Student USN : ";
    cin>>usn;
    for(int i=0; i<N; i++) {
        cout<<"Enter marks in subject "<<i+1<<" : ";
        cin>>marks[i];
    }
}

void Student :: display() {
    cout<<"Student Name : "<<name<<endl;
    cout<<"Student USN : "<<usn<<endl;
    cout<<"Average Marks : "<<avg(marks)<<endl;
}

float Student :: avg(int marks[]) {
    int sum = 0, min = marks[0];
    for(int i=0; i<N; i++) {
        sum += marks[i];
        if(marks[i] < min)
            min = marks[i];
    }
    return (float)((sum-min)/2.0);
}

int main() {
    Student stud[MAX];
    int n;

    cout<<"Enter the number of students : ";
    cin>>n;

    for(int i=0; i<n; i++) {
        cout<<"\nEnter the details of student "<<i+1<<" : "<<endl;
        stud[i].getdata();
    }

    for(int i=0; i<n; i++) {
        cout<<"\nStudent "<<i+1<<" : "<<endl;
        stud[i].display();
        cout<<endl;
    }

    return 0;
}