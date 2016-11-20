import java.util.HashMap;

/**
 * Created by natez on 2016/11/15.
 */
public class Variable implements Expr{
    String name;

    public Variable(String name) {
        this.name = name;
    }

    public String toString() {
        return name;
    }

    public Literal evaluate(Environment... env) {
        return env[0].getLiteral(name);
    }
}