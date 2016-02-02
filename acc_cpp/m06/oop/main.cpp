#include <iostream>
#include "Person.h"
#include "Employee.h"

void virtualMembers();

using namespace std;


void basics() {
    Person p(30, "Jane", Person::female);
    p.greet();

    Person *p2 = new Person(25, "John", Person::male);
    p2->greet();
    delete p2;

    auto le = Person::getLifeExpectancy();
    cout << le << endl;

    // const and destructors
    Person *p3 = new Person(44, "Jack", Person::male);
    auto *address = new Address(12, "Oxford Street", "London");
    p3->address = address;
    p3->greet();

    // copying
    Person p4(*p3);
    p3->address->city = "Exeter";
    cout << p4.address->city << endl;

    // clean up
    delete p3;
}

void inheritance() {
    Employee e(33, "Chris", Person::male, "Mechanic");

    auto u = [](const Person &p) {
        cout << p.name << endl;
    };

    u(e);

    Person &pr = e;
    Employee &er = static_cast<Employee&>(pr);
    cout << er.department << endl;

    // how not to do stuff
    Person p(30, "Jane", Person::female);
    Person &pr2 = p;
    Employee &er2 = static_cast<Employee&>(pr2);
    cout << er2.department << endl; // makes error
}

void virtualMembers() {
    Employee e(33, "Chris", Person::male, "Mechanic");
    e.greet();

    Person p(30, "Jane", Person::female);
    Person &pr2 = p;

    try {
        Employee &er2 = dynamic_cast<Employee &>(pr2); // will cause error
        cout << er2.department << endl;
    }
    catch (const bad_cast &e) {
        cout << "Cannot cast this!" << endl;
    }


    Person* pp = &p;
    Employee *ep = dynamic_cast<Employee*>(pp);

    if (ep) {
        cout << e.department << endl;
    } else {
        cout << "Failed to cast pointer.";
    }
}

int main() {
    virtualMembers();
    return 0;
}