#ifndef PAPER_H_INCLUDED
#define PAPER_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
class Paper
{
    public:
    string papername;//parameter 1
    vector<string> author;//parameter 2
    string journal;//parameter 3
    string doi;//parameter 4
    string year;//parameter 5
    int vol=0;
    int issue=0;
    string page[2]={"",""};
    Paper();
    Paper(string, vector<string>, string, string, string, int, int, string, string);
    static Paper tryPaper(string);
    string getBib();
};


#endif // PAPER_H_INCLUDED
