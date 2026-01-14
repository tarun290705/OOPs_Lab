/*  11. Write a C++ program to create a class called DLIST (Doubly Linked List) with member functions to insert a node at a specified position and delete a node from a specified position of the list. 
    Demonstrate the operations by displaying the content of the list after every operation.
*/

#include<iostream>
using namespace std;

struct list {
    int data;
    struct list *llink, *rlink;
};

typedef struct list node; 

class DLIST {
    private:
        node *first, *last;
        int count, ele;

    public:
        DLIST() {
            first = last = NULL;
            count = 0;
        }    
        void insertFirst(int data);
        void insertNode(int data, int pos);
        void deleteNode(int pos);
        void display();
};

void DLIST :: insertFirst(int data) {
    first = last = new node;
    first->data = data;
    first->llink = first->rlink = NULL;
    count++;
    cout<<data<<" has been inserted at the position 1"<<endl;
}

void DLIST :: insertNode(int data, int pos) {
    if(pos > count+1) {
        cout<<"Invalid Position"<<endl;
        return;
    }

    node *newNode = new node;
    newNode->data = data;

    if(pos == 1) {
        newNode->llink = NULL;
        newNode->rlink = first;
        first->llink = newNode;
        first = newNode;
    } else if(pos == count+1) {
        newNode->rlink = NULL;
        newNode->llink = last;
        last->rlink = newNode;
        last = newNode;
    } else {
        node *temp = first;
        for(int i=1; i<=count; i++) {
            if(i == pos) {
                node *prev = temp->llink;
                newNode->llink = prev;
                newNode->rlink = temp;
                prev->rlink = newNode;
                temp->llink = newNode;
            }
            temp = temp->rlink;
        }
    }
    count++;
    cout<<data<<" has been inserted in the position "<<pos<<endl;
}

void DLIST :: deleteNode(int pos) {
    if(first == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    if(pos > count) {
        cout<<"Invalid Position"<<endl;
        return;
    }
    
    if(pos==1 && first==last) {
        ele = first->data;
        delete first;
        first = last = NULL;
    } else if(pos == count) {
        node *temp = last;
        ele = temp->data;
        last = temp->llink;
        last->rlink = NULL;
        delete temp;
    } else if(pos == 1) {
        node *temp = first;
        ele = temp->data;
        first = temp->rlink;
        first->llink = NULL;
        delete temp;
    } else {
        node *temp = first;
        for(int i=1; i<=count; i++) {
            if(i == pos) {
                ele = temp->data;
                node *prev = temp->llink;
                node *next = temp->rlink;
                prev->rlink = next;
                next->llink = prev;
                delete temp;
            }
            temp = temp->rlink;
        }
    }
    count--;
    cout<<ele<<" has been deleted from the position "<<pos<<endl;
}

void DLIST :: display() {
    cout<<"List Status : "<<endl;
    if(first == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    node *temp = first;
    cout<<"Number of nodes in the list : "<<count<<endl;
    cout<<"List Contents : ";
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->rlink;
    }
    cout<<endl;
}

int main() {
    DLIST list;
    int flag = 0, ele, pos, choice;

    cout<<"\nMENU : "<<endl;
    cout<<"1. Insert a node"<<endl;
    cout<<"2. Delete a node"<<endl;
    cout<<"3. Display Status"<<endl;
    cout<<"4. Exit"<<endl;

    do {
        cout<<"\nEnter your choice : ";
        cin>>choice;

        switch(choice) {
            case 1 : cout<<"Enter the data to be inserted : ";
                     cin>>ele;
                     if(flag == 0) {
                        list.insertFirst(ele);
                        flag = 1;
                     } else {
                        cout<<"Enter the position : ";
                        cin>>pos;
                        list.insertNode(ele, pos);
                     }
                     list.display();
                     break;

            case 2 : cout<<"Enter the position : ";
                     cin>>pos;
                     list.deleteNode(pos);
                     list.display();
                     break;

            case 3 : list.display();
                     break;

            case 4 : cout<<"Thank You!"<<endl;
                     break;

            default : cout<<"Invalid Choice"<<endl;                                    
        }
    } while(choice != 4);
    return 0;
}