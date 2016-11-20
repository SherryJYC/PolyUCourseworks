/**
 * Created by natez on 2016/11/15.
 */

public class BinaryExpr implements Expr{

    Expr e1, e2;
    BinaryOp op;

    public BinaryExpr(Expr e1, Expr e2, BinaryOp op) {
        this.e1 = e1;
        this.e2 = e2;
        this.op = op;
    }

    public String toString() {
        String s1 = e1.toString();
        String s2 = e2.toString();
        if (e1 instanceof BinaryExpr)
            s1 = "(" + s1 + ")";
        if (e2 instanceof BinaryExpr)
            s2 = "(" + s2 + ")";
        return s1 + op + s2;

    }

    public Literal evaluate(Environment... env) {
        return new Literal(op.doOperation(e1.evaluate(env).getValue(), e2.evaluate(env).getValue()));
    }
}
