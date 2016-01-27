//
// Created by Bjarte Skjørestad on 27/01/16.
//
#pragma once
#include "Address.h"

class Person {
    static int lifeExpectancy;
protected:
    int ssn;
public:
    const static int female = 0;
    const static int male = 1;
    int age;
    std::string name;
    int sex;
    Address *address;

    Person(int age, std::string name, int sex);
    Person(int age, std::string name, int sex,
           int house_number,
           std::string street_name,
           std::string city);
    Person(const Person& p);
    ~Person();

    virtual void greet();
    static int getLifeExpectancy();
};
