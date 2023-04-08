#include "Factory.h"
#include "Employee.h"
#include <vector>
#include <iostream>
using namespace std;

Factory::Factory() : costOfMarketTransport(3000) {
    Employee e;
    for(int i = 0; i < 100; i++){
        employees.push_back(e);
    }
}

Factory::Factory(double employeeWage, int hoursPerEmployee, int numEmployees, int costOfMarketTransport) {
    Employee e(employeeWage, hoursPerEmployee);
    int i;

    if(numEmployees < MIN_NUM_EMPLOYEES){
        for(i = 0; i < MIN_NUM_EMPLOYEES; i++)
            employees.push_back(e);
    }
    else if(numEmployees > MAX_NUM_EMPLOYEES){
        for(i = 0; i < MAX_NUM_EMPLOYEES; i++)
            employees.push_back(e);
    }
    else {
        for (i = 0; i < numEmployees; i++)
            employees.push_back(e);
    }

    if(costOfMarketTransport < MIN_COST_TRANSPORT)
        costOfMarketTransport = MIN_COST_TRANSPORT;
    else
        this->costOfMarketTransport = costOfMarketTransport;
}

vector<Employee> Factory::getEmployees(){
    return employees;
}

int Factory::getLaborExpenses() {
    return employees.at(0).getWage() * employees.at(0).getNumHours() * employees.size();
}

int Factory::getCostOfMarketTransport() {
    return costOfMarketTransport;
}

void Factory::setEmployees(vector<Employee> &newEmployees) {
    employees = newEmployees;
}

void Factory::setEmployeeWage(double newEmployeeWage) {
    for(int i = 0; i < employees.size(); i++)
        employees.at(i).setWage(newEmployeeWage);
}

void Factory::setHoursPerEmployee(int newHoursPerEmployee) {
    for(int i = 0; i < employees.size(); i++)
        employees.at(i).setNumHours(newHoursPerEmployee);
}

void Factory::setNumEmployees(int newNumEmployees) {
    Employee e = employees.at(0);
    int difference = newNumEmployees - int(employees.size());
    int maxDifference = MAX_NUM_EMPLOYEES - int(employees.size());
    int i;

    if(newNumEmployees > MAX_NUM_EMPLOYEES || newNumEmployees < MIN_NUM_EMPLOYEES){
        if(newNumEmployees > MAX_NUM_EMPLOYEES){
            for(i = 0; i < maxDifference; i++)
                employees.push_back(e);
        }
        else{
            employees.clear();
            for(i = 0; i < MIN_NUM_EMPLOYEES; i++)
                employees.push_back(e);
        }
    }
    else if(difference > 0){
        for(i = 0; i < difference; i++)
            employees.push_back(e);
    }
    else if(difference < 0){
        for(i = 0; i < abs(difference); i++)
            employees.pop_back();
    }
}

void Factory::setCostOfMarketTransport(int newCostOfMarketTransport) {
    if(newCostOfMarketTransport < MIN_COST_TRANSPORT)
        costOfMarketTransport = MIN_COST_TRANSPORT;
    else
        costOfMarketTransport = newCostOfMarketTransport;
}

int Factory::getTotalExpenses() {
    return getLaborExpenses() + costOfMarketTransport;
}