/**
 * Created by natez on 2016/11/16.
 */
interface  Expr {
    String toString();
    Literal evaluate(Environment... env);
}
