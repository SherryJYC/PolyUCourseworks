/**
 * Created by natez on 2016/11/15.
 */
public class Literal implements Expr{
    Integer value;

    public Literal(Integer i) {
        value = i;
    }

    public String toString() {
        return getValue() + ".0";
    }

    Integer getValue() {
        return value;
    }

    public Literal evaluate(Environment... env) {
        return this;
    }
}
