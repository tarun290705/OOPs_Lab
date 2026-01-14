/*  5. Write a C++ program to create a template function for Quick sort and demonstrate sorting of integers and doubles.
*/

#include<iostream>
using namespace std;

template <typename t>
void quick(t a[], int low, int high) {
    t key, temp;
    int i, j, flag = 0;
    if(low < high) {
        key = a[low];
        i = low + 1;
        j = high;
        while(!flag) {
            while((a[i]<=key) && (i<high))
                i++;
            while(a[j] > key)
                j--;
            if(i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            } else flag = 1;  
        }
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
        quick <t> (a, low, high-1);
        quick <t> (a, low+1, high);
    }
}

int main() {
    int n, choice, a[30];
    float b[30];

    cout<<"\nMENU : "<<endl;
    cout<<"1. Integers\n2. Doubles"<<endl;

    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice) {
        case 1 : cout<<"Enter the size of the integer array : ";
                 cin>>n;
                 cout<<"Enter integer numbers : ";
                 for(int i=0; i<n; i++)
                    cin>>a[i];
                 quick <int> (a, 0, n-1);
                 cout<<"Sorted Array : ";
                 for(int i=0; i<n; i++)
                    cout<<a[i]<<" ";
                 cout<<endl;
                 break;

        case 2 : cout<<"Enter the size of the doubles array : ";
                 cin>>n;
                 cout<<"Enter floating point numbers : ";
                 for(int i=0; i<n; i++)
                    cin>>b[i];
                 quick <float> (b, 0, n-1);
                 cout<<"Sorted Array : ";
                 for(int i=0; i<n; i++)
                    cout<<b[i]<< "  ";
                 cout<<endl;
                 break;

        default : cout<<"Invalid Choice"<<endl;
    }

    return 0;
}