package hk.edu.polyu.comp.comp2021.assignment3;

/**
 * An employee in a company.
 */
public class Employee{
    /**
     * Name of the employee.
     */
    private final String name;

    /**
     * Level of salary of the employee.
     */
    private SalaryLevel salaryLevel;

    /**
     * Return the name of the employee.
     *
     * @return Name of the emplyee.
     */
    public String getName(){
        return name;
    }

    /**
     * Return the salary level of the employee.
     *
     * @return Salary level of the employee.
     */
    public SalaryLevel getSalaryLevel(){
        return salaryLevel;
    }

    /**
     * Set the salary level.
     *
     * @param salaryLevel New salary level.
     */
    public void setSalaryLevel(SalaryLevel salaryLevel){
        this.salaryLevel = salaryLevel;
    }

    /**
     * Initialize an employee object.
     *
     * @param name Name of the employee.
     * @param level Salary level of the employee.
     */
    public Employee(String name, SalaryLevel level){
        // Task 3: add your code here
        this.name = name;
        this.salaryLevel = level;


    }

    /**
     * Return the salary of the employee.
     *
     * @return Salary of the employee.
     */
    public double salary(){
        // The salary of an employee is computed as the multiplication
        // of the base salary (2000.0) and the scale of the employee's salary level.
        // E.g., the salary of an employee at ENTRY level is 2000 * 1 = 2000.

        // Task 4: add your code here
        return BASE_SALARY * salaryLevel.getScale();
        
        
    }

    /**
     * Base salary of all employees.
     */
    public static final double BASE_SALARY = 2000.0;

}
