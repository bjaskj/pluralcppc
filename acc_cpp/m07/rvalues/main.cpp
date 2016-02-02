#include <iostream>
#include <memory>

using namespace std;

class Address {
public:
    string city;
    Address() {}
    Address(string const &city) : city(city) {
        cout << city << " created" << endl;
    }

    ~Address() {
        cout << city << " destroyed" << endl;
    }
};

void inc(int &x) { x++; }
int meaningOfLife() { return 42; }

void move_rvalue() {
    int a = 0;
    inc(a);
    // inc(1); <- NOPE!
    // int &x = meaningOfLife(); <- NOPE!
    int&& y = meaningOfLife();
    cout << y << endl;


    Address book[100];
    book[55] = move(Address("Paris"));

    auto swap = [](int &a, int &b) {
        int tmp{a};
        a = b;
        b = tmp;
    };

    int x = 2, z = 5;
    swap(x, z);

    // move memory
    auto betterSwap = [](int &a, int &b) {
        int tmp(move(a));
        a = move(b);
        b = move(tmp);
    };

    int e = 2, f = 5;
    betterSwap(e, f);
}

// ===============================

unique_ptr<Address> create_address(string const &city) {
    return unique_ptr<Address>(new Address(city));
}

void unique_pointers() {
    auto a = create_address("Paris");
    cout << a->city << endl;
}

// =============================== shared pointer

class Person3 {
public:
    shared_ptr<Address> address;

    Person3(string const &city) {
        address = make_shared<Address>(city);
        cout << "Created person" << endl;
    }

    ~Person3() {
        cout << "Destroyed person" << endl;
    }
};

unique_ptr<Address> create_address2(string const &city) {
    return make_unique<Address>(city);
}

void shared_pointers() {
    // how to keep hold of address
    shared_ptr<Address> a;
    {
        Person3 p("Moscow");
        a = p.address;
    }

    cout << a->city << endl;
}

int main() {
    shared_pointers();
    return 0;
}