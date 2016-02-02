//
// Created by Bjarte Skjørestad on 27/01/16.
//

#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(int age, std::string name, int sex) :
        age(age), name(name), sex(sex)
{
    address = nullptr;
}

Person::Person(int age, std::string name, int sex,
               int house_number,
               std::string street_name,
               std::string city) :
        Person(age, name, sex)
{
    if (address != nullptr) {
        delete address;
    }

    address = new Address(house_number, street_name, city);
}

void Person::greet() {
    cout << "My name is " <<
            this->name << " and I am " <<
            this->age << " years old." <<
            endl;

    if (address) {
        cout << "I live at " << address->house_number <<
                " " << address->street_name <<
                ", " << address->city << endl;
    }
}

int Person::getLifeExpectancy() {
    return lifeExpectancy;
}

int Person::lifeExpectancy = 80;

Person::~Person() {
    if (address != nullptr) {
        delete address;
        address = nullptr;
    }
}

Person::Person(const Person &p) :
        age(p.age),
        name(p.name),
        sex(p.sex) {
    auto* a = p.address;
    address = new Address(
            a->house_number,
            a->street_name,
            a->city
    );
}
