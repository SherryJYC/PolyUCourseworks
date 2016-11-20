package hk.edu.polyu.comp.comp2021.assignment3;

// Task 1 and 2:
// add necessary code to enum SalaryLevel and its method getScale, so that
// ENTRY.getScale() returns 1, JUNIOR.getScale() returns 1.3, and so on.

/**
 * Levels of salary.
 */
enum SalaryLevel {
    ENTRY(1), JUNIOR(1.3), SENIOR(1.6), EXECUTIVE(2);

    // Task 1: add your code here
    private double level;

    SalaryLevel(double level) {
        this.level = level;
    }
    

    /**
     * Return the scale of the level.
     *
     * @return Scale of the salary level.
     */
    public double getScale(){
        // Task 2: add your code here
        return level;
    }

}