#include <bits/stdc++.h>
using namespace std;
#include "database.h"
#include "paper.h"

vector<Paper> Database::paperlist={};
vector<Admin> Database::adminlist={};
vector<string> Database::authlist={};
vector<string> Database::yearlist={};
vector<int> Database::authstat={};
vector<int> Database::yearstat={};
bool Database::pending=true;
void Database::loadData()
{
    ifstream dr("data/data.txt");
    string dem="";
    while(getline(dr,dem))
        {paperlist.push_back(Paper::tryPaper(dem));}
    clearCache();
}
void Database::loadAdmins()
{
    string dem="";
    ifstream ar("data/admin.txt");
    while(getline(ar,dem))
        {adminlist.push_back(Admin(dem));}
    return;
}
void Database::generateList()
{
    if(!pending)return;
    authlist.clear();
    yearlist.clear();
    int l=paperlist.size();
    int i=0; int j=0; int m=0;
    vector<string>::iterator t=authlist.begin();
    for(i=0;i<l;i++)
    {
        m=paperlist[i].author.size();
        for(j=0;j<m;j++)
        {
            t=find(authlist.begin(),authlist.end(),paperlist[i].author[j]);
            if(t!=authlist.end())
            {
                ++authstat[t-authlist.begin()+0];
            }
            else
            {
                authlist.push_back(paperlist[i].author[j]);
                authstat.push_back(1);
            }
        }
        t=find(yearlist.begin(),yearlist.end(),paperlist[i].year);
        if(t!=yearlist.end())
        {
            ++yearstat[t-yearlist.begin()+0];
        }
        else
        {
            yearlist.push_back(paperlist[i].year);
            yearstat.push_back(1);
        }
    }
    int as=authlist.size();
    int ys=yearlist.size();
    string temp="";
    int x=0;
    for(i=0;i<as;i++)
    {
        for(j=0;j<as-i-1;j++)
        {
            if(authlist[j].compare(authlist[j+1])>0)
            {
                temp=authlist[j];x=authstat[j];
                authlist[j]=authlist[j+1];authstat[j]=authstat[j+1];
                authlist[j+1]=temp;authstat[j+1]=x;
            }
        }
    }
    for(i=0;i<ys;i++)
    {
        for(j=0;j<ys-i-1;j++)
        {
            if(yearlist[j].compare(yearlist[j+1])>0)
            {
                temp=yearlist[j];x=yearstat[j];
                yearlist[j]=yearlist[j+1];yearstat[j]=yearstat[j+1];
                yearlist[j+1]=temp;yearstat[j+1]=x;
            }
        }
    }
    pending=false;
}
int Database::exists(Paper p)
{
    int l=paperlist.size();
    for(int i=0;i<l;i++)
    {
        if(p.papername.compare(paperlist[i].papername)==0)return i;
        if(p.doi.compare(paperlist[i].doi)==0&&p.doi.length()!=0)return i;
        if(p.journal.compare(paperlist[i].journal)==0 && (p.page[0].compare(paperlist[i].page[0])==0 && p.page[1].compare(paperlist[i].page[1])))return i;
    }
    return -1;
}
void Database::saveData()
{
    ofstream dw("data/data.txt");
    int l=paperlist.size();
    for(int i=0;i<l;i++)
    {
        dw<<paperlist[i].getBib()<<endl;
    }
    dw.close();
    fstream log("data/activitylog.txt", ios::app);
    ifstream ts("data/tempfile.txt");
    string act="";
    while(getline(ts,act))
    {
        log<<act<<endl;
    }
    log.close();
    ts.close();
    generateList();
    clearCache();
    cout<<"Database saved"<<endl;
}
void Database::clearCache()
{
    ofstream del("data/tempfile.txt");
    del<<"";
    del.close();
}
