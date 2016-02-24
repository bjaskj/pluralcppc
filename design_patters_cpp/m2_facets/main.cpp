#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

using namespace std;

int main() {
    Person p = Person::create()
            .lives().at("123 London Road").with_postcode("SW 1GB").in("London")
            .works().at("PragmaSoft").as_a("Consultant").earning(10e6);

    cout << p << endl;

    return 0;
}