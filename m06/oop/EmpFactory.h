//
// Created by Bjarte Skjørestad on 27/01/16.
//
#pragma once

#include "Employee.h"

class EmpFactory {
public:
    Employee makeEmployee(int taxId) {
        Employee emp;
        emp.taxId = taxId;
        return emp;
    }
};
