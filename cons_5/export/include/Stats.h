#ifndef _STATS_H
#define _STATS_H

class Stats{
    public:
        Stats(double _sum, double _mean, int _count):sum(_sum), mean(_mean), count(_count){};
        void setSum(double sum);
        void setMean(double mean);
        void setCount(int count);

        double getSum() const;
        double getMean() const;
        int getCount() const;
        
    private:
        double sum;
        double mean;
        int count;
};
#endif