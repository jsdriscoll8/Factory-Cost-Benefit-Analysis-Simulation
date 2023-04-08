#ifndef M2OEP_JSDRISCO_EMPLOYEE_H
#define M2OEP_JSDRISCO_EMPLOYEE_H

class Employee{
private:
    double wage;
    int numHours;
public:
    /**
     * Construct a default Employee
     */
    Employee();

    /**
     * Construct a defined Employee
     * @param wage the Employee's hourly wage
     * @param numHours the number of hours worked per week by the Employee
     */
    explicit Employee(double wage, int numHours);

    /**
     * Get the wage of an Employee
     * @return the Employee's wage
     */
    double getWage();

    /**
     * Get the number of weekly worked Employee hours
     * @return the number of hours
     */
    int getNumHours();

    /**
     * Set a new Employee wage
     * @param newWage the new wage
     */
    void setWage(double newWage);

    /**
     * Set a new number of weekly hours
     * @param newNumHours new weekly hours
     */
    void setNumHours(int newNumHours);


    // Constants defining max, min hours and wage values
    static constexpr double MAX_WAGE = 35.0;
    static constexpr double MIN_WAGE = 7.25;
    static const int MAX_HOURS = 60;
    static const int MIN_HOURS = 1;
};

#endif //M2OEP_JSDRISCO_EMPLOYEE_H