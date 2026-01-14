/*  10. Write a C++ program to create a class called QUEUE with member functions to add an element and to delete an element from the queue. 
    Using these member functions, implement a queue of integer and double. 
    Demonstrate the operations by displaying the content of the queue after every operation.
*/

#include<iostream>
#define MAX 100
using namespace std;

template <class t>
class QUEUE {
    private :
        t a[MAX];
        int rear;

    public :
        QUEUE() {
            rear = 0;
        }    
        void add(t ele);
        void del();
        void display();
};

template <class t>
void QUEUE <t>:: add(t ele) {
    a[++rear] = ele;
}

template <class t>
void QUEUE <t>::del() {
    if(rear == 0) {
        cout<<"Queue is empty"<<endl;
        return;
    }
    t ele = a[1];
    for(int i=1; i<=rear; i++)
        a[i] = a[i+1];
    rear--;
    cout<<ele<<" has been deleted from the queue"<<endl;    
}

template <class t>
void QUEUE <t> :: display() {
    cout<<"Queue Status : ";
    if(rear == 0) {
        cout<<"Queue is empty"<<endl;
        return;
    }
    for(int i=1; i<=rear; i++)
        cout<<a[i]<<" ";
    cout<<endl;    
}

int main() {
    QUEUE <int> iq;
    QUEUE <double> dq;
    double ele1;
    int ele, choice, ch;

    cout<<"Enter 1 to implement Queue of integers and 2 to implement Queue of doubles : ";
    cin>>ch;

    cout<<"\nMENU : "<<endl;
    cout<<"1. Add"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Exit"<<endl;

    do {
        cout<<"\nEnter your choice : ";
        cin>>choice;

        switch(choice) {
            case 1 : if(ch == 1) {
                        cout<<"Enter the element (integer) : ";
                        cin>>ele;
                        iq.add(ele);
                        iq.display();
                     } else {
                        cout<<"Enter the element (double) : ";
                        cin>>ele1;
                        dq.add(ele1);
                        dq.display();
                     }
                     break;

            case 2 : if(ch == 1) {
                        iq.del();
                        iq.display();
                     } else {
                        dq.del();
                        dq.display();
                     }
                     break;

            case 3 : if(ch == 1)
                        iq.display();
                     else
                        dq.display();
                     break;   
                     
            case 4 : cout<<"Thank You!"<<endl;
                     break;

            default : cout<<"Invalid choice"<<endl;                  
        }
    } while(choice != 4);
    return 0;
}