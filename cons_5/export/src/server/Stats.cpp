#include "Stats.h"

void Stats::setSum(double sum){
    this->sum = sum;
}

void Stats::setMean(double mean){
    this->mean = mean;
}

void Stats::setCount(int count){
    this->count = count;
}

double Stats::getSum()const{
    return this->sum;
}

double Stats::getMean()const{
    return this->mean;
}

int Stats::getCount()const{
    return this->count;
}