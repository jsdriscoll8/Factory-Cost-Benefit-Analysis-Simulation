#include "ChipFactory.h"

ChipFactory::ChipFactory() : Factory(),
                           dieCost(5000), defectCost(5000){}

ChipFactory::ChipFactory(double employeeWage, int hoursPerEmployee, int numEmployees, int costOfMarketTransport,
                       int dieCost, int defectCost) :
        Factory(employeeWage, hoursPerEmployee, numEmployees, costOfMarketTransport){
    if(dieCost < MIN_DEFECT_COST)
        this->dieCost = MIN_DIE_COST;
    else
        this->dieCost = dieCost;

    if(defectCost < MIN_DEFECT_COST)
        this->defectCost = MIN_DEFECT_COST;
    else
        this->defectCost = defectCost;
}

int ChipFactory::getDieCost() {
    return dieCost;
}

int ChipFactory::getDefectCost() {
    return defectCost;
}

void ChipFactory::setDieCost(int dc) {
    if(dc < MIN_DIE_COST)
        dieCost = MIN_DIE_COST;
    else
        dieCost = dc;
}

void ChipFactory::setDefectCost(int dfc) {
    if(dfc < MIN_DEFECT_COST)
        defectCost = MIN_DEFECT_COST;
    else
        defectCost = dfc;
}

int ChipFactory::getTotalExpenses() {
    return Factory::getTotalExpenses() + defectCost + dieCost;
}