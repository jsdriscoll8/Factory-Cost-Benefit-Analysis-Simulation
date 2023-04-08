#include "Employee.h"
#include "Factory.h"
#include "CarFactory.h"
#include "ChipFactory.h"
#include <iostream>
using namespace std;

bool testEmployee();
bool testFactory();
bool testCarFactory();
bool testChipFactory();


int main(){
    testEmployee();
    testFactory();
    testCarFactory();
    testChipFactory();

    return 0;
}

/**
 * Test the Employee class functionality
 * @return true if all method cases work; false otherwise
 */
bool testEmployee(){
    bool passed = true;
    Employee e;
    e.setWage(20.0);
    e.setNumHours(40);

    // Test initial values
    if(e.getWage() != 20.0) {
        passed = false;
        cout << "FAILED GETWAGE 1" << endl;
    }
    if(e.getNumHours() != 40) {
        passed = false;
        cout << "FAILED GETNUMHOURS 1" << endl;
    }

    // Test values below minimums
    e.setWage(7.00);
    e.setNumHours(-1);
    if(e.getWage() != 7.25) {
        passed = false;
        cout << "FAILED GETWAGE 2" << endl;
    }
    if(e.getNumHours() != 1) {
        passed = false;
        cout << "FAILED GETNUMHOURS 2" << endl;
    }

    // Test values above maximums
    e.setWage(40.00);
    e.setNumHours(65);
    if(e.getWage() != 35.00) {
        passed = false;
        cout << "FAILED GETWAGE 3" << endl;
    }
    if(e.getNumHours() != 60) {
        passed = false;
        cout << "FAILED GETNUMHOURS 3" << endl;
    }

    return passed;
}

/**
 * Test the Factory class functionality
 * @return true if Factory method cases work; false otherwise
 */
bool testFactory(){
    bool passed = true;
    Factory f;


    // Test initial values
    f.setEmployeeWage(25);
    f.setHoursPerEmployee(30);
    f.setNumEmployees(50);
    f.setCostOfMarketTransport(1000);

    if(f.getCostOfMarketTransport() != 1000){
        passed = false;
        cout << "FAILED MARKET 1" << endl;
    }

    // Cost should be 25*30*50 = 37500
    if(f.getLaborExpenses() != 37500){
        passed = false;
        cout << "FAILED LABOR 1" << endl;
    }

    // Test low values
    f.setEmployeeWage(7.00);
    f.setHoursPerEmployee(0);
    f.setNumEmployees(10);
    f.setCostOfMarketTransport(0);

    if(f.getCostOfMarketTransport() != 500){
        passed = false;
        cout << "FAILED MARKET 2" << endl;
    }

    // Should be 7.25 (MIN WAGE) * 1 (MIN HOURS) * 20 (MIN EMPLOYEES) = 145
    if(f.getLaborExpenses() != 145){
        passed = false;
        cout << "FAILED LABOR 2" << endl;
    }

    // Test high Factory value - transport cost has no maximum
    f.setEmployeeWage(40.00);
    f.setHoursPerEmployee(65);
    f.setNumEmployees(5001);

    // Should be 35 (MAX WAGE) * 60 (MAX HOURS) * 5000 (MAX EMPLOYEES) = 10,500,000
    if(f.getLaborExpenses() != 10500000){
        passed = false;
        cout << "FAILED LABOR 3" << endl;
    }

    return passed;
}

/**
 * Test CarFactory functionality
 * @return true if all cases pass; false otherwise
 */
bool testCarFactory(){
    bool passed = true;
    CarFactory c;

    // Test initial values
    c.setSourcedPartsCost(5000);
    c.setProductionLineCost(10000);

    if(c.getSourcedPartsCost() != 5000){
        passed = false;
        cout << "FAILED PARTS 1" << endl;
    }
    if(c.getProductionLineCost() != 10000){
        passed = false;
        cout << "FAILED LINE 1" << endl;
    }

    // Should be 10 (default wage) * 40 (default hours) * 100 (default num employees) + 3000 (default transport) + 5000 + 10,000 = 58,000
    if(c.getTotalExpenses() != 58000){
        passed = false;
        cout << "FAILED CAR TOTAL 1" << endl;
    }

    // Test minimum values
    c.setSourcedPartsCost(500);
    c.setProductionLineCost(300);

    if(c.getSourcedPartsCost() != 1000){
        passed = false;
        cout << "FAILED PARTS 2" << endl;
    }
    if(c.getProductionLineCost() != 1000){
        passed = false;
        cout << "FAILED LINE 2" << endl;
    }

    // Should be 10 (default wage) * 40 (default hours) * 100 (default num employees) + 3000 (default transport) + 1000 + 1000 = 45,000
    if(c.getTotalExpenses() != 45000){
        passed = false;
        cout << "FAILED CAR TOTAL 2" << endl;
    }

    return passed;
}

/**
 * Test ChipFactory functionality
 * @return true if all cases pass; false otherwise
 */
bool testChipFactory(){
    bool passed = true;
    ChipFactory c;

    // Test initial values
    c.setDefectCost(5000);
    c.setDieCost(10000);

    if(c.getDefectCost() != 5000){
        passed = false;
        cout << "FAILED DEFECT 1" << endl;
    }
    if(c.getDieCost() != 10000){
        passed = false;
        cout << "FAILED DIE 1" << endl;
    }

    // Should be 10 (default wage) * 40 (default hours) * 100 (default num employees) + 3000 (default transport) + 5000 + 10,000 = 58,000
    if(c.getTotalExpenses() != 58000){
        passed = false;
        cout << "FAILED CHIP TOTAL 1" << endl;
    }

    // Test minimum values
    c.setDefectCost(500);
    c.setDieCost(300);

    if(c.getDefectCost() != 2500){
        passed = false;
        cout << "FAILED DEFECT 2" << endl;
    }
    if(c.getDieCost() != 4000){
        passed = false;
        cout << "FAILED DIE 2" << endl;
    }

    // Should be 10 (default wage) * 40 (default hours) * 100 (default num employees) + 3000 (default transport) + 2500 + 4000 = 49,500
    if(c.getTotalExpenses() != 49500){
        passed = false;
        cout << "FAILED CHIP TOTAL 2" << endl;
    }

    return passed;
}