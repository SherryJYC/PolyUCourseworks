package hk.edu.polyu.comp.comp2021.assignment3;

/**
 * A manager in a company.
 */
public class Manager extends Employee{
    private double bonusRate;

    /**
     * Initialize a manager object.
     *
     * @param name Name of the manager.
     * @param level Salary level of the manager.
     * @param bonusRate Bonus rate of the manager.
     */
    public Manager(String name, SalaryLevel level, double bonusRate){
        // Task 5: add your code here.
        super(name, level);
        this.bonusRate = bonusRate;

    }

    // override method Employee.salary to calculate the salary of a manager.
    // The salary of a manager is computed as the multiplication
    // of his/her regular salary as an employee and his/her bonusRate plus 1.
    // E.g., the salary of an EXECUTIVE level manager with bonus rate 0.5
    // is 2000 * 2 * (0.5 + 1) = 6000.

    // Task 6: add the overriding method here
    @Override
    public double salary(){
        return BASE_SALARY * getSalaryLevel().getScale() * (1 + bonusRate);
    }


    //            REQUIREMENT
    // The main method should print out the following two lines:
    //   Tom:2000.0
    //   Bob:6000.0
    public static void main(String[] args){
        Employee[] employees = new Employee[2];
        employees[0] = new Employee("Tom", SalaryLevel.ENTRY);
        employees[1] = new Manager ("Bob", SalaryLevel.EXECUTIVE, 0.5);
        for(Employee e: employees){
            System.out.println(e.getName() + ":" + e.salary());
        }
    }

}
