#ifndef _C5NUMBERENGINE_H
#define _C5NUMBERENGINE_H

#include "C5Requirement.h"
#include "C5Number.h"
#include "Stats.h"
#include <string>
#include <vector>
#include <fstream>

/**
 * @brief The C5NumberEngine class manages the generation of the numbers,
 *        user validation, and retrieval of statistical information.
 */
class C5NumberEngine {
public:
    /**
     * @brief Default constructor for C5NumberEngine.
     */
    C5NumberEngine();

    /**
     * @brief Validates a user based on their user ID.
     *
     * @param userId The user ID to validate.
     * @return True if the user is valid; otherwise, false.
     */
    bool userValidate(int userId);

    /**
     * @brief Generates a random integer within the specified range.
     *
     * @param bmin The minimum value of the range.
     * @param bmax The maximum value of the range.
     * @return A randomly generated integer.
     */
    int getInt(int bmin, int bmax);

    /**
     * @brief Generates a random integer when no boundary is specified.

     * If there is a previous number of the same kind, it takes the boundaries of that number
     * to generate the new number; otherwise, it throws an exception.
     * @return A randomly generated integer.
     */
    int getInt();

    /**
     * @brief Generates a random real number within the specified range.
     *
     * @param bmin The minimum value of the range.
     * @param bmax The maximum value of the range.
     * @return A randomly generated real number.
     */
    double getReal(double bmin, double bmax);

    /**
     * @brief Generates a random real number.

     * If there is a previous number of the same kind, it takes the boundaries of that number
     * to generate the new number; otherwise, it throws an exception.
     * @return A randomly generated real number.
     */
    double getReal();

    /**
     * @brief Retrieves an old C5Number object based on its ordinal.
     *
     * @tparam Type The type of the C5Number object (int or double).
     * @param ordinal The ordinal of the C5Number object to retrieve.
     * @return A constant reference to the retrieved C5Number object.
     */
    template <typename Type>
    const C5Number<Type> &getNumberOld(int ordinal) const;

    /**
     * @brief Retrieves basic statistical information containing
     * the number of numbers generated for a specified requirement
     * the sum of the numbers and the mean of the numbers.
     *
     * @return A Stats object containing statistical information.
     */
    Stats getStat() const;

    /**
     * @brief Retrieves the list of numbers for a requirement.
     *
     * @return A constant reference to the C5Requirement object representing a requirement.
     */
    const C5Requirement &getNumberList() const;

private:
    std::vector<C5Requirement> requirements; ///< Vector to store requirements.
    std::string validUsersFile; ///< File path for storing valid user information.
    int requirementIndex; ///< Index to keep track the current requirement.
};

#include "C5NumberEngine.t.hpp"
#endif
