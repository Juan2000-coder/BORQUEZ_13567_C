#ifndef _USER_H
#define _USER_H
#include <string>
class C5User{
    public:
        C5User(int _id): id(_id){}
        int getId() const {return id;}
    private:
        int id;
};
#endif