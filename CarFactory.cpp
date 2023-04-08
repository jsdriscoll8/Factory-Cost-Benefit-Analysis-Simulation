#include "CarFactory.h"

CarFactory::CarFactory() : Factory(),
    productionLineCost(5000), sourcedPartsCost(5000){}

CarFactory::CarFactory(double employeeWage, int hoursPerEmployee, int numEmployees, int costOfMarketTransport,
                       int productionLineCost, int sourcedPartsCost) :
                       Factory(employeeWage, hoursPerEmployee, numEmployees, costOfMarketTransport){
    if(productionLineCost < MIN_PROD_PARTS_COST)
        this->productionLineCost = MIN_PROD_PARTS_COST;
    else
        this->productionLineCost = productionLineCost;

    if(sourcedPartsCost < MIN_PROD_PARTS_COST)
        this->sourcedPartsCost = MIN_PROD_PARTS_COST;
    else
        this->sourcedPartsCost = sourcedPartsCost;
}

int CarFactory::getProductionLineCost() {
    return productionLineCost;
}

int CarFactory::getSourcedPartsCost() {
    return sourcedPartsCost;
}

void CarFactory::setProductionLineCost(int plc) {
    if(plc < MIN_PROD_PARTS_COST)
        productionLineCost = MIN_PROD_PARTS_COST;
    else
        productionLineCost = plc;
}

void CarFactory::setSourcedPartsCost(int spc) {
    if(spc < MIN_PROD_PARTS_COST)
        sourcedPartsCost = MIN_PROD_PARTS_COST;
    else
        sourcedPartsCost = spc;
}

int CarFactory::getTotalExpenses() {
    return Factory::getTotalExpenses() + productionLineCost + sourcedPartsCost;
}