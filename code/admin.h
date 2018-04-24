#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
/*#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED*/
#include <bits/stdc++.h>
using namespace std;
#include "user.h"
class Admin:public User
{
    private: string password;
    public: string username;
    Admin(string);
    bool login=false;
    void edit();
    void adminOptions();
    void logout();
    void rollBack();
    bool trylogin(string, string);
};

//#endif // ADMIN_H_INCLUDED
#endif
