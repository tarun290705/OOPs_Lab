/*  4. Write a C++ program to create a class called LIST (linked list) with member functions to insert an element at the front as well as to delete an element from the front of the list.
    Demonstrate all the functions after creating a list object.
*/

#include<iostream>
using namespace std;

struct list {
    int data;
    struct list *link;
};

typedef struct list NODE;

class LIST {
    private :
        NODE *head;

    public :
        LIST() {
            head = NULL;
        }    
        void insert_node(int ele);
        void delete_node();
        void display();
};

void LIST :: insert_node(int ele) {
    NODE *newnode = new NODE;
    newnode->data = ele;
    newnode->link = head;
    head = newnode;
}

void LIST :: delete_node() {
    NODE *temp = head;
    if(head == NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    cout<<"The deleted element is "<<temp->data<<endl;
    head = head->link;
    delete temp;
}

void LIST :: display() {
    NODE *temp = head;
    if(head == NULL) {
        cout<<"The list is empty"<<endl;
        return;
    }
    
    cout<<"The elements in the list are : "<<endl;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}

int main() {
    int ele, choice;
    LIST obj;

    cout<<"MENU : "<<endl;
    cout<<"1. Insertion\n2. Deletion\n3. Display\n4. Exit"<<endl;

    do {
        cout<<"\nEnter your choice : ";
        cin>>choice;

        switch(choice) {
            case 1 : cout<<"Enter the element to be inserted : ";
                     cin>>ele;
                     obj.insert_node(ele);
                     break;

            case 2 : obj.delete_node();
                     break;

            case 3 : obj.display();
                     break;

            case 4 : cout<<"Thank You!"<<endl;
                     break;

            default : cout<<"Invalid Choice"<<endl;                                    
        }
    } while(choice != 4);
    
    return 0;
}