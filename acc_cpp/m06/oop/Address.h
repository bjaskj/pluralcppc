//
// Created by Bjarte Skjørestad on 27/01/16.
//
#pragma once

#include <string>

class Address {
public:
    int house_number;
    std::string street_name;
    std::string city;

    Address(int house_number,
            std::string const &street_name,
            std::string const &city) :
            house_number(house_number),
            street_name(street_name),
            city(city) {

    }
};
