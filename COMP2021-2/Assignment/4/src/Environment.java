import java.util.HashMap;
import java.util.concurrent.atomic.DoubleAccumulator;

/**
 * Created by natez on 2016/11/15.
 */
public class Environment {
    HashMap<String, Literal> variables;

    public Environment() {
        variables = new HashMap<>();
    }

    public void addVariable(String s, Double i) {
        variables.put(s, new Literal(i.intValue()));
    }

    Literal getLiteral(String name) {
        return variables.get(name);
    }
}
