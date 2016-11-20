/**
 * Created by natez on 2016/11/17.
 */
public class Main {
    public static void main(String[] args) throws RuntimeException{
        Literal l1 = new Literal(1);
        Literal l2 = new Literal(3);
        Literal l3 = new Literal(5);
        System.out.println(l2);                   // print out: 3.0
        System.out.println(l2.evaluate());        // print out: 3.0
        BinaryExpr b1 = new BinaryExpr(l2, l1, BinaryOp.DIVIDE);
        System.out.println(b1);                   // print out: 3.0 / 1.0
        BinaryExpr b2 = new BinaryExpr(b1, l3, BinaryOp.ADD);
        System.out.println(b2);                   // print out: (3.0 / 1.0) + 5.0
        System.out.println(b2.evaluate());        // print out: 8.0
        BinaryExpr b3 = new BinaryExpr(b1, b2, BinaryOp.MULTIPLY);
        System.out.println(b3.evaluate());        // print out: 24.0

        Variable v1 = new Variable("a");          // Each variable has a single character as its name
        Expr b4 = new BinaryExpr(b2, v1, BinaryOp.DIVIDE);
        System.out.println(b4);                   // print out: ((3.0 / 1.0) + 5.0) / a
        Environment env = new Environment();
        env.addVariable("a", 2.0);                // variable “a“ has value 2.0 in env
        try {
            System.out.println(b4.evaluate());        // throws RuntimeException
        } catch (RuntimeException e) {
            System.out.println("Error Message: No environment assigned!!!");
        }
        System.out.println(b4.evaluate(env));     // print out: 4.0
    }
}
