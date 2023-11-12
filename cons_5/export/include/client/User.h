#ifndef _USER_H
#define _USER_H
#include <string>
class User{
    public:
        User(std::string _id): id(_id){}
        std::string getId() const {return id;}
    private:
        std::string id;
};
#endif