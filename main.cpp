#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include "CarFactory.h"
#include "ChipFactory.h"
using namespace std;

void analyzeProfits(string filename);
void analyzeProfits();

/**
 * Run through the profit analysis
 * @return 0 if successful
 */
int main(){
    string choice = "";
    cout << "Would you like to read in data from Factories.txt, or manually?" << endl;
    while(choice != "f" && choice != "m" && choice != "F" && choice != "M"){
        cout << "Input 'f' for file, or 'm' for manual input: ";
        getline(cin, choice);
    }

    if(choice == "f") {
        analyzeProfits("Factories.txt");
    }
    else{
        analyzeProfits();
    }

    return 0;
}

/**
 * Analyze the profitability of a Factory subclass from Factories.txt
 * @param filename the file name
 */
void analyzeProfits(string filename){
    ifstream inFile("../" + filename);
    string type, newline;
    int i = 1;
    double wage;
    int hours, numEmployees, costTransport, expenditure1, expenditure2, revenues;
    if(inFile){
        while(inFile){
            getline(inFile, type);
            inFile >> wage;
            inFile >> hours;
            inFile >> numEmployees;
            inFile >> costTransport;
            inFile >> expenditure1;
            inFile >> expenditure2;
            inFile >> revenues;

            if(type == "Car"){
                CarFactory c(wage, hours, numEmployees, costTransport, expenditure1, expenditure2);
                if(revenues > c.getTotalExpenses())
                    cout << "Factory " << i << " is profitable!" << endl;
                else
                    cout << "Factory " << i << " is unprofitable!" << endl;
            }
            else if(type == "Chip"){
                ChipFactory c(wage, hours, numEmployees, costTransport, expenditure1, expenditure2);
                if(revenues > c.getTotalExpenses())
                    cout << "Factory " << i << " is profitable!" << endl;
                else
                    cout << "Factory " << i << " is unprofitable!" << endl;
            }
            getline(inFile, newline);
            i++;
        }
    }
}

/**
 * Analyze Factory viability using user-inputted data.
 */
void analyzeProfits(){
    string choice = "";
    double wage;
    bool good = false;
    int hours, numEmployees, costTransport, expenditure1, expenditure2, revenues;
    cout << "Is this a Car, or a Chip factory?" << endl;
    while(choice != "car" && choice != "chip") {
        cout << "Enter car for a Car factory, or chip for a chip factory: ";
        getline(cin, choice);
        std::transform(choice.begin(),choice.end(),choice.begin(), ::tolower);
    }

    if(choice == "car"){
        while(!good){
            cout << "What is the wage of the Employees? ";
            cin >> wage;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        good = false;

        while(!good){
            cout << "How many hours do the employees work? ";
            cin >> hours;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        good = false;

        while(!good){
            cout << "How many employees work at the factory? ";
            cin >> numEmployees;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        good = false;

        while(!good){
            cout << "What is the cost of weekly transport to markets? ";
            cin >> costTransport;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        good = false;

        while(!good){
            cout << "What is the weekly cost of the production lines? ";
            cin >> expenditure1;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        good = false;

        while(!good){
            cout << "What is the weekly cost of raw materials? ";
            cin >> expenditure2;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        good = false;

        while(!good){
            cout << "What are your weekly revenues? ";
            cin >> revenues;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        CarFactory c(wage, hours, numEmployees, costTransport, expenditure1, expenditure2);


        if(revenues > c.getTotalExpenses())
            cout << "Your car factory is profitable!" << endl;
        else
            cout << "Your car factory is unprofitable!" << endl;
    }

    else{
        while(!good){
            cout << "What is the wage of the Employees? ";
            cin >> wage;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        good = false;

        while(!good){
            cout << "How many hours do the employees work? ";
            cin >> hours;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        good = false;

        while(!good){
            cout << "How many employees work at the factory? ";
            cin >> numEmployees;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        good = false;

        while(!good){
            cout << "What is the cost of weekly transport to markets? ";
            cin >> costTransport;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        good = false;

        while(!good){
            cout << "What is the weekly cost of dies? ";
            cin >> expenditure1;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        good = false;

        while(!good){
            cout << "What is the weekly cost of defects? ";
            cin >> expenditure2;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        good = false;

        while(!good){
            cout << "What are your weekly revenues? ";
            cin >> revenues;
            if(cin.fail()){
                cin.clear();
            }
            else{
                good = true;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        ChipFactory c(wage, hours, numEmployees, costTransport, expenditure1, expenditure2);


        if(revenues > c.getTotalExpenses())
            cout << "Your chip factory is profitable!" << endl;
        else
            cout << "Your chip factory is unprofitable!" << endl;
    }
}