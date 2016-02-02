//
// Created by Bjarte Skjørestad on 27/01/16.
//

#include <iostream>
#include "Employee.h"

using namespace std;

void Employee::greet() {
    Person::greet();
    cout << "By the way, I work in " << department << endl;
}