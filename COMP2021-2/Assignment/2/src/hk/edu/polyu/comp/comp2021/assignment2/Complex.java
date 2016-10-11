package hk.edu.polyu.comp.comp2021.assignment2;

import java.awt.*;

public class Complex {

    // Task 4: add the missing fields
    Rational real;
    Rational imag;


    public Complex(Rational real, Rational imag){
        // Assume 'real' and 'imag' are not null
        // Task 5: complete the constructor
        this.real = real;
        this.imag = imag;
    }

    public Complex add(Complex other){
        // Assume 'other' is not null
        // Task 5: complete the method
        return new Complex(real.add(other.real), imag.add(other.imag));
    }

    public Complex multiply(Complex other){
        // Assume 'other' is not null
        // Task 5: complete the method
        return new Complex(real.multiply(other.real).add(imag.multiply(other.imag).multiply(new Rational(-1, 1))),
                real.multiply(other.imag).add(imag.multiply(other.real)));
    }

    public String asString(){
        // Task 5: complete the method
        return  real.asString() + " + " + "(" + imag.asString() + "i)";
    }

    public static void main(String[] args){
        // Task 6: create Complex objects, add or multiply them, and
        //         print the results out to check they are correct
        Rational real1 = new Rational(4, 2);
        Rational imag1 = new Rational(-3, 5);
        Rational real2 = new Rational(8, 4);
        Rational imag2 = new Rational(3, 5);
        Complex obj1 = new Complex(real1, imag1);
        Complex obj2 = new Complex(real2, imag2);
        Complex sum = obj1.add(obj2);
        Complex product = obj1.multiply(obj2);
        System.out.println("\nThe two complex numbers are " + obj1.asString() + " and " + obj2.asString() +
                ".\nTheir sum is " + sum.asString() + " and their product is " + product.asString() +
                ".");
        System.out.println("\nAs there is no clear description for printing style, I defined some rules:\n" +
                "    i. If both numerator and denominator are negative, both negtive sign would be canceled.\n" +
                "   ii. For negative number, negative sign would be shown in the numerator.\n" +
                "  iii. If numerator is 0 or denominator is 1, no denominator would be shown.");
    }
}
