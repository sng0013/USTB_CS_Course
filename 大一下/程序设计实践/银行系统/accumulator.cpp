#include "accumulator.h"

Accumulator::Accumulator(const Date& date, double value): lastDate(date), value(value), sum(0) { }

double Accumulator::getSum(const Date& date) const {
    return sum + value * (date - lastDate);
}

void Accumulator::change(const Date& date, double value) {
    sum = getSum(date);
    lastDate = date;
    this->value = value;
}

void Accumulator::reset(const Date& date, double value) {
    lastDate = date;
    this->value = value;
    sum = 0;
}
