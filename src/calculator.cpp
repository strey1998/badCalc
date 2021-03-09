#include <math.h>

#include "calculator.h"

Calculator::Calculator() :
    num(0),
    reg(0),
    place(0),
    decimal(false),
    newlyQueuedOp(false),
    queuedOp(Operation::None)
{ }

double Calculator::typeDigit(int digit) {
    if (newlyQueuedOp) {
        num = 0;
        place = 0;
        newlyQueuedOp = false;
    }

    if(decimal) num += digit*pow(10,--place);
    else {
        num *= 10;
        num += digit;
    }
    return num;
}

bool Calculator::typeDecimal() {
    if(decimal) return false;

    decimal = true;
    return true;
}

bool Calculator::queueOperation(Operation op) {
    if (newlyQueuedOp) {
        queuedOp = op;
        return true;
    }

    switch (queuedOp) {
    case Operation::Add:
        reg += num;
        break;
    case Operation::Subtract:
        reg -= num;
        break;
    case Operation::Multiply:
        reg *= num;
        break;
    case Operation::Divide:
        reg /= num;
        break;
    case Operation::Negate:
        num = -num;
        break;
    case Operation::None:
        reg = num;
        break;
    }

    newlyQueuedOp = true;
    queuedOp = op;
    return true;
}

void Calculator::equals() {
    queueOperation(Operation::None);
    num = reg;
}

double Calculator::getNum() {
    return num;
}

bool Calculator::clear() {
    if(num==0) return true;
    num = 0;
    return false;
}

void Calculator::fortytwo() {
    num = 0;
    place = 0;
    typeDigit(4);
    typeDigit(2);
}
