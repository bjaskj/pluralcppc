#pragma once

#include <iostream>
#include <string>

class PersonBuilder;

class Person {
    // address
    std::string street_address, post_code, city;

    // employment
    std::string company_name, position;
    int annual_income = 0;

public:
    static PersonBuilder create();

    Person() { }

    friend class PersonBuilder;
    friend class PersonAddressBuilder;
    friend class PersonJobBuilder;

    Person(Person &&other)
            : street_address(std::move(other.street_address)),
              post_code(std::move(other.post_code)),
              city(std::move(other.city)),
              company_name(std::move(other.company_name)),
              position(std::move(other.position)),
              annual_income(other.annual_income) { }

    Person &operator=(Person &&other) {
        if (this == &other) {
            return *this;
        }

        street_address = std::move(other.street_address);
        post_code = std::move(other.post_code);
        city = std::move(other.city);
        company_name = std::move(other.company_name);
        position = std::move(other.position);
        annual_income = other.annual_income;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& obj) {
        return os
                << "street_address: " << obj.street_address
                << " post_code: " << obj.post_code
                << " city: " << obj.city
                << " company_name: " << obj.company_name
                << " position: " << obj.position
                << " annual_income: " << obj.annual_income
                ;
    }
};
