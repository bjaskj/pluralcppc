//
// Created by Bjarte Skjørestad on 24/02/16.
//

#pragma once

#include <string>
#include "PersonBuilder.h"

class PersonJobBuilder : public PersonBuilder {
    typedef PersonJobBuilder Self;

public:
    explicit PersonJobBuilder(Person& person)
            : PersonBuilder{person} {
    }

    Self& at(std::string company_name) {
        person.company_name = company_name;
        return *this;
    }

    Self& as_a(std::string position) {
        person.position = position;
        return *this;
    }

    Self& earning(int annual_income) {
        person.annual_income = annual_income;
        return *this;
    }
};

