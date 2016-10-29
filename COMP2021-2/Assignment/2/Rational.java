package hk.edu.polyu.comp.comp2021.assignment2;

public class Rational {
    // Task 1: add the missing fields
    private int numerator;
    private int denominator;


    public Rational(int numerator, int denominator){
        // Assume 'denominator' is not 0;
        // Task 2: complete the constructor
        if (numerator == 0)
            denominator = 1;
        else if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        this.numerator = numerator;
        this.denominator = denominator;
        fractionDeduction();
    }

    public Rational add(Rational other){
        // Assume 'other' is not null
        // Task 2: complete the method
        Rational sum = new Rational(numerator * other.denominator + other.numerator * denominator,
                denominator * other.denominator);
        sum.fractionDeduction();//I implemented a private method for help
        return sum;
    }

    public Rational multiply(Rational other){
        // Assume 'other' is not null
        // Task 2: complete the method
        Rational product = new Rational(numerator * other.numerator, denominator * other.denominator);
        product.fractionDeduction();//I implemented a private method for help
        return product;
    }

    public String asString(){
        // Task 2: complete the method
        if (denominator == 1)
            return String.valueOf(numerator);
        else
            return String.valueOf(numerator) + "/" + String.valueOf(denominator);
    }

    public static void main(String[] args){
        // Task 3: create Rational objects, add or multiply them, and
        //         print the results out to check they are correct
        Rational obj1 = new Rational(3, 5);
        Rational obj2 = new Rational(2, 1);
        Rational sum = obj1.add(obj2);
        Rational product = obj1.multiply(obj2);
        System.out.println("The two objects are " + obj1.asString() + " and " + obj2.asString() +
                ".\nTheir sum is " + sum.asString() + " and their product is " + product.asString() +
                ".");
        System.out.println("\nAs there is no clear description for printing style, I defined some rules:\n" +
                "    i. If both numerator and denominator are negative, both negtive sign would be canceled.\n" +
                "   ii. For negative number, negative sign would be shown in the numerator.\n" +
                "  iii. If numerator is 0 or denominator is 1, no denominator would be shown.");
    }

    private void fractionDeduction() {
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        boolean isNegtive = false;
        if (numerator < 0) {
            numerator *= -1;
            isNegtive = true;
        }
        int max, i;
        while (true) {
            max = numerator > denominator ? denominator : numerator;
            i = 2;
            for (; i <= max; i++) {
                if (numerator % i == 0 && denominator % i == 0) {
                    denominator /= i;
                    numerator /= i;
                    break;
                }
            }
            if (i > max)
                break;
        }
        if (isNegtive)
            numerator *= -1;

    }

}
