#include <iostream>

using namespace std;

class Address {
public:
    string city;
    Address(string const &city) : city(city) {
        cout << "Address created" << endl;
    }

    ~Address() {
        cout << "Address destroyed" << endl;
    }
};

class Person {
public:
    Address *address;

    Person(string const &city) {
        address = new Address(city);
        cout << "Person created" << endl;
    }

    ~Person() {
        delete address;
        cout << "Person destroyed" << endl;
    }
};

// old school way
class Person2 {
    Person2() {}
    Person2(const Person2& _) {}
    ~Person2(){}

    int ref_count;
public:
    static Person2* create() {
        auto *p = new Person2;
        p->ref_count = 1;
        return p;
    }

    void add_ref() {ref_count++;}
    void release() {
        if (--ref_count == 0) {
            delete this;
        }
    }
};

void basic_pointer_ownership() {
    Address *a;

    {
        Person p("Moscow");
        a = p.address;
    }

    cout << a->city << endl; // should have failed, but don't, hmm!
}

int main() {
    basic_pointer_ownership();
    return 0;
}