#ifndef M2OEP_JSDRISCO_FACTORY_H
#define M2OEP_JSDRISCO_FACTORY_H
#include "Employee.h"
#include <vector>
using namespace std;

class Factory{
protected:
    vector<Employee> employees;
    int costOfMarketTransport;
public:
    /**
     * Construct a default factory of 100 default employees.
     */
    Factory();

    /**
     * Construct a defined factory
     * @param employeeWage average employee earnings per hour
     * @param hoursPerEmployee average hours worked per employee
     * @param numEmployees number of Factory employees
     * @param costOfMarketTransport weekly cost of transport to markets
     */
    explicit Factory(double employeeWage, int hoursPerEmployee, int numEmployees, int costOfMarketTransport);

    /**
     * Get the vector of Factory employees
     * @return Factory employee vector
     */
    vector<Employee> getEmployees();

    /**
     * Get the total employee expenses
     * @return the total expenses
     */
    int getLaborExpenses();

      /**
       * Get the cost of market transport per week.
       * @return cost of market transport
       */
       int getCostOfMarketTransport();

       /**
        * Set a new vector of employees
        * @param newEmployees the new vector of employees
        */
       void setEmployees(vector<Employee> &newEmployees);

       /**
        * Set a new average employee wage
        * @param newEmployeeWage the new employee wage
        */
       void setEmployeeWage(double newEmployeeWage);

       /**
        * Set the new number of hours per employee
        * @param numHoursPerEmployee the new average number of hours
        */
       void setHoursPerEmployee(int newHoursPerEmployee);

       /**
        * Set a new number of employees
        * @param newNumEmployees the new number of employees
        */
       void setNumEmployees(int newNumEmployees);

       /**
        * Set a new weekly cost of market transport
        * @param newCostOfMarketTransport set a new cost of market transport
        */
       void setCostOfMarketTransport(int newCostOfMarketTransport);

       /**
        * Method to be overridden - returns labor expenses and cost of transport
        * @return total expenses, i.e. labor expenses
        */
       virtual int getTotalExpenses();

       const static int MAX_NUM_EMPLOYEES = 5000;
       const static int MIN_NUM_EMPLOYEES = 20;
       const static int MIN_COST_TRANSPORT = 500;
};


#endif //M2OEP_JSDRISCO_FACTORY_H
