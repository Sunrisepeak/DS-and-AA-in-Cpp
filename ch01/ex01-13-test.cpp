#include <iostream>
//#include <string>
#include "ex1-13.h" //Collection of resize-Array

using namespace std;

int main()
{
    Collection<int> c;
    Collection<int> c2{c}; //test move constructor

    for (int i = 0; i < 10; i++)
    {
        c.insert(i);
        cout << c[i] << " "; //test operator[]
    }
    cout << endl;

    if (c2.isEmpty()) { //test isEmpty()
        cout << "c2 is created c move constructor" << endl;
    }

    c2 = c; // test copy operator=

    cout << "c2: ";
    for (int i = 0; i < c2.getSize(); i++) {    //test getSize()
        c2[i] *= 2;     //test operator= return left-value reference
        cout << c2[i] << " ";
        c.insert(i, c2[i]); // test insert(index, object)
    }
    cout << endl;

    cout << "c: ";
    for (int i = 0; i < c.getSize(); i++) {
        cout << c[i] << " ";
    }

    cout << endl << "rmoved(for c): ";
    for (int i = 0; i < 30; i++) {
        if (i % 2 == 0 && c.contains(i)) {  //test contains()
            c.remove(i);    //test remove()
            cout << i << " ";
        }
    }

    cout << endl << "c: ";
    for (int i = 0; i < c.getSize(); i++) {
        cout << c[i] << " ";
    }

    cout << endl;
    c.makeEmpty();  // test makeEmpty()

    if (c.isEmpty()) {
        cout << "is empty" << endl;
    }
    return 0;
}