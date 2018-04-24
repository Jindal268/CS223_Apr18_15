#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
#include "paper.h"
#include "admin.h"
class Database
{
    public:
    static vector<string> authlist;
    static vector<int> authstat;
    static vector<string> yearlist;
    static vector<int> yearstat;
    static vector<Paper> paperlist;
    static vector<Admin> adminlist;
    static bool pending;
    static void loadData();
    static void loadAdmins();
    static void saveData();
    static void clearCache();
    static void generateList();
    static int exists(Paper p);
};

#endif // DATABASE_H_INCLUDED
