//
// Created by Bjarte Skjørestad on 24/02/16.
//

#include "Person.h"
#include "PersonBuilder.h"

PersonBuilder Person::create() {
    return PersonBuilder();
}
