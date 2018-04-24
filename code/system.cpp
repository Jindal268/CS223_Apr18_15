#include <bits/stdc++.h>
using namespace std;
#include "database.h"
#include "system.h"
void System::searchdata(string key, int type)
    {
        cout<<"Index | Bibliography"<<endl;
        switch(type)
        {
        case 1:searchname(key);break;
        case 2:searchauth(key);break;
        case 3:searchjournal(key);break;
        case 4:searchdoi(key);break;
        case 5:searchyear(key);break;
        }
    }
void System::searchname(string key)
    {
        bool found=false;
        int l=Database::paperlist.size();
        for(int i=0; i<l; i++)
        {
            if(occurence(Database::paperlist[i].papername, key))
                {cout<<i<<"     |"<<Database::paperlist[i].getBib()<<endl;found=true;}
        }
        if(!found)cout<<"Not found"<<endl;
    }
void System::searchauth(string key)
    {
        bool found=false;
        int l=Database::paperlist.size();
        int n=0;
        int j=0;
        for(int i=0; i<l; i++)
        {
            n=Database::paperlist[i].author.size();
            for(j=0;j<n;j++)
            {
                if(occurence(Database::paperlist[i].author[j], key))
                    {cout<<i<<"     |"<<Database::paperlist[i].getBib()<<endl;found=true;break;}
            }
        }
        if(!found)cout<<"Not found"<<endl;
    }
void System::searchjournal(string key)
    {
        bool found=false;
        int l=Database::paperlist.size();
        for(int i=0; i<l; i++)
        {
            if(occurence(Database::paperlist[i].journal, key))
                {cout<<i<<"     |"<<Database::paperlist[i].getBib()<<endl;found=true;}
        }
        if(!found)cout<<"Not found"<<endl;
    }
void System::searchdoi(string key)
    {
        bool found=false;
        int l=Database::paperlist.size();
        for(int i=0; i<l; i++)
        {
            if (Database::paperlist[i].doi.compare(key)==0)
                {cout<<i<<"     |"<<Database::paperlist[i].getBib()<<endl;found=true;}
        }
        if(!found)cout<<"Not found"<<endl;
    }
void System::searchyear(string key)
    {
        bool found=false;
        int l=Database::paperlist.size();
        for(int i=0; i<l; i++)
        {
            if(Database::paperlist[i].year.compare(key)==0)
                {cout<<i<<"     |"<<Database::paperlist[i].getBib()<<endl;found=true;}
        }
        if(!found)cout<<"Not found"<<endl;
    }
bool System::occurence(string whole, string part)
    {
        transform(whole.begin(), whole.end(), whole.begin(), ::toupper);
        transform(part.begin(), part.end(), part.begin(), ::toupper);
        return (whole.find(part)!=string::npos);
    }
bool System::addPaper(string bib)
    {
        Paper p=Paper::tryPaper(bib);
        if(p.papername.compare("untitled")==0)
        {
            cout<<"Invalid Bibliography, ensure IEEE format"<<endl;
            return false;
        }
        int i=Database::exists(p);
        if(i>=0)
            cout<<"Conflicting entry found"<<endl<<Database::paperlist[i].getBib()<<endl;
        else
            {Database::paperlist.push_back(p);return true;}
        return false;
    }
bool System::deletePaper(int index)
    {
        int l=Database::paperlist.size();
        if(index>=0&&index<l)
            {
                Database::paperlist.erase(Database::paperlist.begin()+index);
                return true;
            }
        else
            cout<<"Index not found"<<endl;
        return false;
    }
bool System::changePaper(string bib, int index)
    {
        int l=Database::paperlist.size();
        if(index>=0&&index<l)
        {
                Paper p=Paper::tryPaper(bib);
                if(p.papername.compare("untitled")==0)
                {
                    cout<<"Invalid Bibliography, ensure IEEE format"<<endl;
                    return false;
                }
            int i=Database::exists(p);
            if(i>=0 && i!=index)
                cout<<"Conflicting entry found"<<endl<<Database::paperlist[i].getBib()<<endl;
            else
                {
                    Database::paperlist[index]=p;
                    return true;
                }
        }
        else cout<<"Index not found"<<endl;
        return false;
    }
int System::adminLogin(string name, string pass)
    {
        int l=Database::adminlist.size();
        for(int i=0;i<l;i++)
        {
            if(Database::adminlist[i].trylogin(name, pass))
            {
                cout<<"Logged in as: "<<name<<endl;
                return i;
            }
        }
        cout<<"Admin Login failed"<<endl;
        return -1;
    }

void System::getStat(int type)
    {
        int l=0;
        switch(type)
        {
            case 1:l=Database::authlist.size();
            for(int i=0;i<l;i++)
            {
                cout<<Database::authlist[i]<<"------"<<Database::authstat[i]<<endl;
            }
            break;
            case 2:l=Database::yearlist.size();
            for(int i=0;i<l;i++)
            {
                cout<<Database::yearlist[i]<<"------"<<Database::yearstat[i]<<endl;
            }
            break;
            default:return;
        }
        cout<<"Total records: "<<Database::paperlist.size()<<endl;
        return;
    }

void System::printNews()
    {
        ifstream nr("data/activitylog.txt");
        string temp="";
        while(getline(nr,temp))
        {
            cout<<temp<<endl;
        }
    }
void System::writeLog(string bib, string bib2, string editor, int type)
    {
        fstream lw("data/tempfile.txt", ios::app);
        time_t now=time(0);
        string systime=ctime(&now);
        switch(type)
        {
            case 1:lw<<systime<<": "<<editor<<" added paper- "<<bib<<endl;break;
            case 2:lw<<systime<<": "<<editor<<" deleted paper- "<<bib2<<endl;break;
            case 3:lw<<systime<<": "<<editor<<" changed paper- "<<bib2<<" to "<<bib<<endl;break;
        }
        lw<<endl;
        lw.close();
    }

void System::start()
    {
        cout<<"~~~~~~~Welcome to Publication Management~~~~~~~"<<endl;
        cout<<"Loading database..."<<endl;
        Database::loadData();
        Database::loadAdmins();
        Database::generateList();
        time_t now=time(0);
        string systime=ctime(&now);
        cout<<"Program started: "<<systime;
        cout<<"IEEE format used:\n<author list separated by ',' & 'and'>, \"<Paper title>,\" <Journal title>, vol.<volume>, no.<issue>, pp.<page start>-<page end>, <year>. doi:<DOI>"<<endl;
        char c='0';
        string cls="";
        int loginstatus=0;
        do{
        cout<<"Do you want to login as admin? Press y to login, any other key to continue as guest"<<endl;
        cin>>c;
        cin.clear();
		cin.ignore(INT_MAX,'\n');
        loginstatus=-1;
        do
        {
            if(c!='y')break;
            if(c=='y')
            {
                cout<<"Enter username (case sensitive)"<<endl;
                string un="";
                getline(cin,un);
                cout<<"Enter password (case sensitive)"<<endl;
                string ps="";
                getline(cin,ps);
                loginstatus=adminLogin(un,ps);
            }
            if(loginstatus<0 && c=='y')
            {
                cout<<"Press y to try login again, any other key to continue as guest"<<endl;
                cin>>c;
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                loginstatus=-1;
            }
        }while(loginstatus<0);

        if(loginstatus<0)
		{
		    cout<<"Logged in as guest\n";
			User guest;
			guest.userOptions();
		}
		else
		{
			Database::adminlist[loginstatus].adminOptions();
		}
		cout<<"Press x to exit, any other key to continue"<<endl;
        cin>>c;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        if(c=='x')exit(0);

		cout<<"Enter CLS to clear the screen, any other key to continue"<<endl;
        cin>>cls;
        transform(cls.begin(), cls.end(), cls.begin(), ::toupper);
        if(cls.compare("CLS")==0)
            {
                system("cls");
                cout<<"Screen cleared"<<endl;
                cout<<"~~~~~~~Welcome to Publication Management~~~~~~~"<<endl;
                systime=ctime(&now);
                cout<<"Screen cleared at: "<<systime;
                cout<<"IEEE format used:\n<author list separated by ',' & 'and'>, \"<Paper title>,\" <Journal title>, vol.<volume>, no.<issue>, pp.<page start>-<page end>, <year>. doi:<DOI>"<<endl;
            }
        }while(true);
    }
