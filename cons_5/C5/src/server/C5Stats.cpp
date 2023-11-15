/**
 * @file     C5Stats.cpp
 * @brief    Implementation of the C5Stats class.
 * 
 * @details  Implements the methods of the C5Stats class.
 * 
 * @version  1.0
 * @date     2023-11-15
 * @author   Juan Manuel Borquez
 * @contact  borquez.juan00@gmail.com
 */

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