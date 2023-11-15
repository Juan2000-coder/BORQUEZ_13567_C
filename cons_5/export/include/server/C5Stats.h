#ifndef _C5STATS_H
#define _C5STATS_H

/**
 * @brief Represents statistical information including sum, mean, and count.
 *
 * This class encapsulates statistical information such as sum, mean, and count.
 * It provides methods to set and retrieve these statistical values.
 */
class C5Stats {
public:
    /**
     * @brief Constructor to initialize statistical values.
     *
     * Initializes the Stats object with the provided sum, mean, and count.
     *
     * @param _sum   The sum value for the statistical information.
     * @param _mean  The mean value for the statistical information.
     * @param _count The count value for the statistical information.
     */
    C5Stats(double _sum, double _mean, int _count):sum(_sum), mean(_mean), count(_count){};

    /**
     * @brief Sets the sum value in the statistical information.
     *
     * @param sum The sum value to be set.
     */
    void setSum(double sum);

    /**
     * @brief Sets the mean value in the statistical information.
     *
     * @param mean The mean value to be set.
     */
    void setMean(double mean);

    /**
     * @brief Sets the count value in the statistical information.
     *
     * @param count The count value to be set.
     */
    void setCount(int count);

    /**
     * @brief Retrieves the sum value from the statistical information.
     *
     * @return The sum value.
     */
    double getSum() const;

    /**
     * @brief Retrieves the mean value from the statistical information.
     *
     * @return The mean value.
     */
    double getMean() const;

    /**
     * @brief Retrieves the count value from the statistical information.
     *
     * @return The count value.
     */
    int getCount() const;

private:
    double sum;   ///< The sum value in the statistical information.
    double mean;  ///< The mean value in the statistical information.
    int count;    ///< The count value in the statistical information.
};

#endif
