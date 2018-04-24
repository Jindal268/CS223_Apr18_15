#include <bits/stdc++.h>
using namespace std;
#include "admin.h"
#include "database.h"
#include "system.h"
Admin::Admin(string profile)
{
    int l=profile.length();
    string temp="";
    int i=0;
    char c=profile[i];
    while(c!=',')
    {
        temp=temp+c;
        i++;
        c=profile[i];
    }
    username=temp;
    i+=2;
    c=profile[i];
    temp="";
    while(i<l)
    {
        temp=temp+c;
        i++;
        c=profile[i];
    }
    password=temp;
}
bool Admin::trylogin(string name, string pass)
{
    if(name.compare(username)==0 && pass.compare(password)==0)
    {
        login=true;
        return true;
    }
    else return false;
}
void Admin::adminOptions()
{

	if(this->login)
		do
		{
			int iquery=0;
			cout<<"Enter the index number of query you want to execute \n";
            cout<<"1.Search \n2.Get Stat\n3.Print News\n4.Edit \n5.Save \n6.Roll back unsaved changes\n7.Logout\n";
            adminop:
            cin>>iquery;
            if(cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				iquery = 0;
			}
            switch(iquery)
            {
                case 1:usearch();break;
                case 2:uStat();break;
                case 3:uNews();break;
                case 4:edit();break;
                case 5:Database::saveData();break;
                case 6:rollBack();break;
				case 7:logout();return;break;
                default:cout<<"Invalid Response, please try again\n";
                            goto adminop;
            }
	}while(true);
	else
	{
		cout<<"Not logged in"<<endl;
		userOptions();return ;
	}
}
void Admin::edit()
{
    cout<<"To edit or delete a paper, first get its index by using search"<<endl;
    cout<<"To proceed, press y. To return to previous menu press any other key"<<endl;
    char c;cin>>c;
    char p;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        c='n';
    }
    if(c!='y')return;
    else
    {
        bool success=false;
        int ch=0;
        string temp="";
        string buff="";
        int x;
        byconfirm:
        cout<<"1.Add paper\n2.Delete paper\n3.Change paper\n4.Back"<<endl;
        adminedt:
        cin>>ch;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            ch=0;
        }
        int papl=Database::paperlist.size();
        switch(ch)
        {
            case 1:cout<<"Enter bibliography in IEEE format"<<endl;
            cin.get();
            getline(cin,temp);
            success=System::addPaper(temp);
            break;

            case 2:cout<<"Enter index of paper to be deleted"<<endl;
            cin>>x;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                x=-1;
            }
            if(x>=0&&x<papl)
            {
                buff=Database::paperlist[x].getBib();
                cout<<"Are you sure you want to delete this paper?"<<endl<<buff<<endl<<"Enter y to confirm, any other key to return to edit menu"<<endl;
                cin>>p;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    p='n';
                }
                if(p=='y')
                    success=System::deletePaper(x);
                else goto byconfirm;
            }
            else cout<<"Index not found"<<endl;
            break;

            case 3:cout<<"Enter index of paper to be changed"<<endl;
            cin>>x;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                x=-1;
            }
            if(x>=0&&papl)
            {
                buff=Database::paperlist[x].getBib();
                cout<<"Are you sure you want to modify this paper?"<<endl<<buff<<endl<<"Enter y to confirm, any other key to return to edit menu"<<endl;
                cin>>p;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    p='n';
                }
                if(p=='y')
                {
                    cout<<"Enter new bibliography in IEEE format"<<endl;
                    cin.get();
                    getline(cin,temp);
                    success=System::changePaper(temp,x);
                }
                else goto byconfirm;
            }
            else cout<<"Index not found"<<endl;;
            break;

            case 4:return;break;

            default:cout<<"Invalid Response, please try again\n";
                        goto adminedt;
        }
        if(success)
        {
            System::writeLog(temp,buff,this->username,ch);
            cout<<"Records updated"<<endl;
            Database::pending=true;
        }
        else cout<<"no changes made"<<endl;
    }
    return;
}
void Admin::rollBack()
{
    cout<<"Do you want to discard all unsaved changes? Enter y to confirm"<<endl;
    char p; cin>>p;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        p='n';
    }
    if(p!='y') return;
    Database::paperlist.clear();
    Database::loadData();
    cout<<"Database reloaded, unsaved changes lost"<<endl;
}
void Admin::logout()
{
    cout<<"Do you want to save any unsaved changes made to database? Enter y to save"<<endl;
    char c; cin>>c;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    if(c=='y')Database::saveData();
    else
        rollBack();
    login=false;
    cout<<username<<" logged out successfully"<<endl;
    return;
}
