#ifndef _USER_H
#define _USER_H

#include <string>

/**
 * @brief Represents a user.
 *
 * This class stores information about a user.
 */
class C5User {
public:
    /**
     * @brief Constructor for C5User.
     *
     * Initializes a C5User with the provided user ID.
     *
     * @param _id The ID of the user.
     */
    C5User(int _id) : id(_id) {}

    /**
     * @brief Gets the user ID.
     *
     * Retrieves the ID of the user.
     *
     * @return The ID of the user.
     */
    int getId() const { return id; }

private:
    int id; /**< The ID of the user. */
};

#endif
