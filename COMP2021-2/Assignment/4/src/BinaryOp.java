/**
 * Created by natez on 2016/11/16.
 */

enum BinaryOp {
    ADD,
    MINUS,
    MULTIPLY,
    DIVIDE;
    public String toString() {
        switch (this) {
            case ADD:
                return " + ";
            case MINUS:
                return " - ";
            case MULTIPLY:
                return " * ";
            case DIVIDE:
                return " / ";
        }
        return null;
    }

    public Integer doOperation(Integer i1, Integer i2) {
        switch (this) {
            case ADD:
                return i1 + i2;
            case MINUS:
                return i1 - i2;
            case MULTIPLY:
                return i1 * i2;
            case DIVIDE:
                return i1 / i2;
        }
        return null;
    }
}
