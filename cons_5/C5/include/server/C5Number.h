/**
 * @file  C5NumberEngine.h
 * @brief Implementation of the C5Number class.
 * 
 * @details Declaration of the C5Number class.
 * 
 * @version 1.0
 * @date    2023-11-15
 * @author  Juan Manuel Borquez
 * @contact borquez.juan00@gmail.com
 */

#ifndef _C5NUMBER_H
#define _C5NUMBER_H

#include <string>

/**
 * @brief Template class representing a numeric object.
 * Type would be double or int for "real" or "entero" cases.
 *
 * @tparam Type The data type of the numeric value.
 */

template <class Type> class C5Number {
  public:
    /**
     * @brief Constructor for C5Number class.
     *
     * Initializes a C5Number instance with the provided bounds, ordinal, and timestamp.
     *
     * @param bmin Minimum bound for the numeric value.
     * @param bmax Maximum bound for the numeric value.
     * @param time Timestamp associated with the numeric value.
     */
    C5Number(Type bmin, Type bmax, long time);

    /**
     * @brief Sets the ordinal value for the C5Number instance.
     *
     * @param ordinal The ordinal value to be set.
     */
    void setOrdinal(int ordinal);

    /**
     * @brief Gets the ordinal value of the C5Number instance.
     *
     * @return The ordinal value.
     */
    int getOrdinal() const;

    /**
     * @brief Gets the data type of the C5Number instance.
     *
     * @return The data type as a string.
     */
    std::string getType() const;

    /**
     * @brief Gets the numeric value of the C5Number instance.
     *
     * @return The numeric value.
     */
    Type getValue() const;

    /**
     * @brief Gets the minimum bound of the C5Number instance.
     *
     * @return The minimum bound.
     */
    Type getBmin() const;

    /**
     * @brief Gets the maximum bound of the C5Number instance.
     *
     * @return The maximum bound.
     */
    Type getBmax() const;

    /**
     * @brief Gets the timestamp associated with the instance.
     *
     * @return The timestamp.
     */
    long getTime() const;

  private:
    int ordinal;       ///< Ordinal value of the C5Number.
    std::string type;  ///< Data type of the C5Number ("entero" o "real").
    Type value;        ///< Numeric value of the C5Number.
    Type bmin;         ///< Minimum bound of the C5Number.
    Type bmax;         ///< Maximum bound of the C5Number.
    long time;         ///< Timestamp associated with the C5Number.
};

#include "C5Number.t.hpp"
#endif
