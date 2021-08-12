#include<bits/stdc++.h>
using namespace std;

class Student {
public:
	char *name;
private:
	int age;

public:
	// The moment we define any user created constructor, we can no longer access the default constructor
	Student(int age) {
		cout << "default constructor is called\n";
		this -> age = age;
	}

	//Getter function to access private member
	// what is the logic of making a property as private when the user can still get or set it from outside the class?
	// because if we let the user get or set the value of an attribute through a function, we can filter out the data which the user is sending
	int getAge(string password) {
		if (password != "yash") return -1;
		return age;
	}

	// default copy constructor do shallow copy
	// for deep copy do something like this
	Student(Student const &s) {
		this -> age = s.age;
		this -> name = new char[strlen(s.name) + 1]; // +1 for null character
		strcpy(this -> name, s.name);
	}

	// &age is an alias to the original age variable, which have issues because we can accidentally change the value of
	// age through its alias, to avoid that we use "const" keyword to make an alias such that it can only read from the original value
	void setAge(int const &age , string password) { // int const &age -> constant reference (read only)
		if (password != "yash") return;
		this -> age = age;
	}

	~Student() {
		cout << "bye bye ...." << age << endl;
	}
};

int main() {
	Student s(983);
	cout << s.getAge("yash") << endl; // with right password
	cout << s.getAge("avail") << endl; // with wrong password

	s.setAge(65, "yash");
	s.setAge(65, "avail");

	// for dynamically allocated objects
	Student *s2 = new Student(489);
	cout << s2->getAge("yash") << endl;

	cout << s.getAge("yash") << endl; // with right password
	cout << s.getAge("avail") << endl; // with wrong password

	delete s2;

	// copy constructor
	// copy constructor can onyl be called during initialisation of object
	Student s1(s); // OR
	// Student s1 = s; also copy constructor syntax -> resolved as Student s1(s)
	cout << s1.getAge("yash") << endl;

	Student s3(1234);
	Student s4(4321);

	cout << s3.getAge("yash") << endl;
	// Alternative of a copy constructor, because once initialised, the object can not call copy constructor,
	// so instead of copy const., we use "=" operator which equals the values of the object with other object
	s4 = s3;
	cout << s4.getAge("yash") << endl;

	return 0;
}