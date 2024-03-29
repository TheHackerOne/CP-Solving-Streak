#include <iostream>
using namespace std;

class Example {
    int i;
    int j;

public:

    Example() {
        i = 27;
        j = 78;
        cout << "Default Constructor" << endl;
    }

    Example(int k) {
        i = k;
        cout << "Parameterised Constructor 1" << endl;
    }

    Example(Example &s) {
        cout << "compy Constructor" << endl;
        this -> i = s.i;
        this -> j = s.j;
    }

    void print() {
        cout << "i = " << i << endl;
        cout << "j = " << j << endl;
    }

    ~Example() {
        cout << "Destructor" << endl;
    }

};

int main() {
    Example e1; // Default Constructor
    e1.print();

    Example e2(4); // Parameterised Constructor
    e2.print();

    Example e3(e2); // Copy Constructor
    e3.print();

    e1 = e2; // Copy Assignment Operator

    Example e4 = e3; // resolved in a Copy Constructor
    e4.print();

    // In this case destructor will not be called automatically and we have to
    // delete this object manually because it is in the heap area
    Example *p = new Example; // Dynamic memory allocation in heap
    (*p) = e1;
    (*p).print();
    delete p;

    return 0;
}
