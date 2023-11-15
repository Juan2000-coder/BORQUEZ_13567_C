#include "C5Stats.h"

// Setters
void C5Stats::setSum(double sum){
    this->sum = sum;
}

void C5Stats::setMean(double mean){
    this->mean = mean;
}

void C5Stats::setCount(int count){
    this->count = count;
}

// Getters
double C5Stats::getSum()const{
    return this->sum;
}

double C5Stats::getMean()const{
    return this->mean;
}

int C5Stats::getCount()const{
    return this->count;
}