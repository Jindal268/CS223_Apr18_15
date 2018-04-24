#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
class System
{
    private:
    static void searchname(string);
    static void searchauth(string);
    static void searchjournal(string key);
    static void searchdoi(string);
    static void searchyear(string);
    static bool occurence(string, string);
    public:
    static void searchdata(string, int);
    static bool addPaper(string bib);
    static bool deletePaper(int);
    static bool changePaper(string, int);
    static int adminLogin(string, string);
    static void getStat(int);
    static void printNews();
    static void writeLog(string, string, string, int);
    static void start();
};


#endif // SYSTEM_H_INCLUDED
