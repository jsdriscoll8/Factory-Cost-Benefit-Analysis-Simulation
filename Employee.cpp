#include "Employee.h"

Employee::Employee() : wage(10), numHours(40) {}

Employee::Employee(double wage, int numHours) {
    if(wage < MIN_WAGE)
        this->wage = MIN_WAGE;
    else if(wage > MAX_WAGE)
        this->wage = MAX_WAGE;
    else
        this->wage = wage;

    if(numHours < MIN_HOURS)
        this->numHours = MIN_HOURS;
    else if(numHours > MAX_HOURS)
        this->numHours = MAX_HOURS;
    else
        this->numHours = numHours;
}

double Employee::getWage() {
    return wage;
}

int Employee::getNumHours() {
    return numHours;
}

void Employee::setWage(double newWage) {
    if(newWage < MIN_WAGE)
        wage = MIN_WAGE;
    else if(newWage > MAX_WAGE)
        wage = MAX_WAGE;
    else
        wage = newWage;
}

void Employee::setNumHours(int newNumHours) {
    if(newNumHours < MIN_HOURS)
        numHours = MIN_HOURS;
    else if(newNumHours > MAX_HOURS)
        numHours = MAX_HOURS;
    else
        numHours = newNumHours;
}