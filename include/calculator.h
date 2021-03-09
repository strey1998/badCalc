#ifndef CALCULATOR_H
#define CALCULATOR_H

enum class Operation {
    None = 0,
    Add,
    Subtract,
    Multiply,
    Divide,
    Negate
};

class Calculator
{
private:
    double num;
    double reg;
    int place;
    bool decimal;
    bool newlyQueuedOp;
    Operation queuedOp;
public:
    Calculator();
    double typeDigit(int digit);
    bool typeDecimal();
    bool queueOperation(Operation op);
    void equals();
    double getNum();
    bool clear();
    void fortytwo();
};

#endif // CALCULATOR_H
