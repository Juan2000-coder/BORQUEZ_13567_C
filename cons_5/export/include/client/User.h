#ifndef _USER_H
#define _USER_H
#include <string>
class User{
    public:
        User(int _id): id(_id){}
        int getId() const {return id;}
    private:
        int id;
};
#endif