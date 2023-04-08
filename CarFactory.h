#ifndef M2OEP_JSDRISCO_CARFACTORY_H
#define M2OEP_JSDRISCO_CARFACTORY_H
#include "Employee.h"
#include "Factory.h"

class CarFactory : public Factory{
private:
    int productionLineCost;
    int sourcedPartsCost;
public:
    /**
     * Construct a default CarFactory.
     */
    CarFactory();

    /**
     * Construct a defined CarFactory
     * @param employeeWage average employee wage
     * @param hoursPerEmployee hours worked per employee
     * @param numEmployees number of employees in the factory
     * @param costOfMarketTransport cost of market delivery
     * @param productionLineCost cost of production lines
     * @param sourcedPartsCost cost of sourced parts and materials (raw mats, engines, transmissions, etc.)
     */
    explicit CarFactory(double employeeWage, int hoursPerEmployee, int numEmployees, int costOfMarketTransport, int productionLineCost, int sourcedPartsCost);

    /**
     * Get the cost of the production lines
     * @return cost of production lines
     */
    int getProductionLineCost();

    /**
     * Get the cost of sourced parts
     * @return
     */
    int getSourcedPartsCost();

    /**
     * Set a new production line cost
     * @param plc the new production line cost
     */
    void setProductionLineCost(int plc);

    /**
     * Set a new sourced parts cost
     * @param spc the new sourced parts cost
     */
    void setSourcedPartsCost(int spc);

    /**
     * Override: get total costs - labor, production, transport, parts
     * @return
     */
    int getTotalExpenses() override;

    static const int MIN_PROD_PARTS_COST = 1000;
};


#endif //M2OEP_JSDRISCO_CARFACTORY_H