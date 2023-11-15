/**
 * @file    C5Requirement.h
 * @brief   Header file for the C5Requirement class.
 * 
 * @details This file declares the C5Requirement class.
 * 
 * @version 1.0
 * @date    2023-11-15
 * @author  Juan Manuel Borquez
 * @contact borquez.juan00@gmail.com
 */

#ifndef _C5REQUIREMENT_H
#define _C5REQUIREMENT_H

#include "C5Number.h"
#include "C5Stats.h"
#include <vector>
#include <variant>
#include <string>
#include <chrono>

/**
 * @brief Represents a user requirement for generating and managing numbers.
 *
 * This class encapsulates user-specific requirements for generating and managing
 * numbers. It includes methods for setting and retrieving user-related information,
 * appending numbers to the requirement, and obtaining statistical information.
 */
class C5Requirement {
  public:
    /**
     * @brief Default constructor for C5Requirement.
     */
    C5Requirement();

    /**
     * @brief Constructor for C5Requirement with a specified user ID.
     * @param userId The ID of the user associated with the requirement.
     */
    C5Requirement(int userId);

    /**
     * @brief Sets the user ID associated with the requirement.
     * @param id The user ID to be set.
     */
    void setUserId(int id);

    /**
     * @brief Appends a number of the specified Type to the requirement
     * using the boundaries used for the last number generated of this Type.
     * @tparam Type The type of the number to be appended.
     */
    template <typename Type>
    void appendNumber();

    /**
     * @brief Appends a number with specified boundaries to the requirement.
     * @tparam Type The type of the number to be appended.
     * @param bmin The minimum boundary for the number.
     * @param bmax The maximum boundary for the number.
     */
    template <typename Type>
    void appendNumber(Type bmin, Type bmax);

    /**
     * @brief Gets the user ID associated with the requirement.
     * @return The user ID.
     */
    int getUserId() const;

    /**
     * @brief Gets the initial time when the requirement was created.
     * @return The initial time as a chrono time point.
     */
    std::chrono::_V2::system_clock::time_point getInitialTime() const;

    /**
     * @brief Gets the current time stamp.
     * @return The current time stamp.
     */
    long getCurrentStamp() const;

    /**
     * @brief Gets the count of numbers associated with the requirement.
     * @return The count of numbers.
     */
    int getNumbersCount() const;

    /**
     * @brief Gets the statistical information about the numbers associated with the requirement.
     * @return The statistical information.
     */
    C5Stats getStats() const;

    /**
     * @brief Gets a specific number from the requirement by ordinal.
     * @tparam Type The type of the number to be retrieved.
     * @param ordinal The ordinal position of the number.
     * @return The C5Number object.
     */
    template<typename Type>
    const C5Number<Type> &getNumber(int ordinal) const;

    /**
     * @brief Gets the last number generated if matches the Type
     * or throws and exception if there's no match in the Type.
     *
     * @tparam Type The type of the number to be retrieved.
     * @return The C5Number object.
     */
    template<typename Type>
    const C5Number<Type> &getNumber() const;

    /**
     * @brief Gets the most recently appended number of the Type from the requirement.
     * @tparam Type The type of the number to be retrieved.
     * @return The C5Number object.
     */
    template<typename Type>
    const C5Number<Type> &getRecent() const;

  private:
    int userId; ///< The user ID associated with the requirement.
    std::chrono::_V2::system_clock::time_point initialTime; ///< The initial time when the requirement was created.
    std::vector<std::variant<C5Number<int>, C5Number<double>>> numbers; ///< Vector to store both "real" and "integer" numbers.
};

#include "C5Requirement.t.hpp"
#endif
