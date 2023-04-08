#ifndef M2OEP_JSDRISCO_CHIPFACTORY_H
#define M2OEP_JSDRISCO_CHIPFACTORY_H
#include "Employee.h"
#include "Factory.h"

class ChipFactory : public Factory{
private:
    int dieCost;
    int defectCost;
public:
    /**
     * Construct a default CarFactory.
     */
    ChipFactory();

    /**
     * Construct a defined CarFactory
     * @param employeeWage average employee wage
     * @param hoursPerEmployee hours worked per employee
     * @param numEmployees number of employees in the factory
     * @param costOfMarketTransport cost of market delivery
     * @param productionLineCost cost of production lines
     * @param sourcedPartsCost cost of sourced parts and materials (raw mats, engines, transmissions, etc.)
     */
    explicit ChipFactory(double employeeWage, int hoursPerEmployee, int numEmployees, int costOfMarketTransport, int dieCost, int defectCost);

    /**
     * Get the cost of the production lines
     * @return cost of production lines
     */
    int getDieCost();

    /**
     * Get the cost of sourced parts
     * @return
     */
    int getDefectCost();

    /**
     * Set a new production line cost
     * @param plc the new production line cost
     */
    void setDieCost(int dc);

    /**
     * Set a new sourced parts cost
     * @param spc the new sourced parts cost
     */
    void setDefectCost(int dfc);

    /**
     * Override: get labor, transport, die, and defect costs.
     * @return total labor costs
     */
    int getTotalExpenses() override;

    static const int MIN_DEFECT_COST = 2500;
    static const int MIN_DIE_COST = 4000;
};

#endif //M2OEP_JSDRISCO_CHIPFACTORY_H
