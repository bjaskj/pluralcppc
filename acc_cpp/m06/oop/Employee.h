//
// Created by Bjarte Skjørestad on 27/01/16.
//
#pragma once

#include "Person.h"

using namespace std;

class Employee : public Person {
    friend class EmpFactory;
    int taxId;
public:
    Employee(int age, string const& name, int sex, string department = string()) :
            Person(age, name, sex), department(department) {
        ssn = 0;
    }

    void greet() override;

    string department;
};
