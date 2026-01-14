/*  12. Define a class Publication which has a title. Derive two classes from it – a class Book which has an accession number and a class Magazine which has volume number.
    With these two as bases,derive the class Journal. Define a function print() in each of these classes.
    Ensure that the derived class function always invokes the base(s) class function.
    In main() create a Journal called IEEEOOP with an accession number 681.3 and a volume number 1. Invoke the print() function for this object.
*/

#include<iostream>
using namespace std;

class Publication {
    protected :
        string title;

    public :
        Publication(string t) : title(t) {} 
        virtual void print() {
            cout<<"Title : "<<title<<endl;
        }   
};

class Book : public Publication {
    private : 
        float accNum;

    public :
        Book(string t, float an) : Publication(t), accNum(an) {}
        void print() override {
            Publication::print();
            cout<<"Accession Number : "<<accNum<<endl;
        }    
};

class Magazine : public Publication {
    private :
        int volNum;

    public :
        Magazine(string t, int vn) : Publication(t), volNum(vn) {}
        void print() override {
            Publication::print();
            cout<<"Volume Number : "<<volNum<<endl;
        }    
};

class Journal : public Book, public Magazine {
    public :
        Journal(string t, float an, int vn) : Book(t, an), Magazine(t, vn) {}
        void print() override {
            Book::print();
            Magazine::print();
        }
};

int main()
{
    Journal obj("IEEE OOP", 681.3, 1);
    obj.print();
    return 0;
}