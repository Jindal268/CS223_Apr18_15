#include <bits/stdc++.h>
using namespace std;
#include "user.h"
#include "system.h"
void User::userOptions()
{
		do
		{
			int iquery=0;
			cout<<"Enter the index number of query you want to execute \n";
            cout<<"1.Search  \n2.Get Stat\n3.Print News\n4.Logout session \n";
            userop:
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
                case 4:cout<<"Guest session terminated"<<endl;return;break;
                default:cout<<"Invalid Response, please try again\n";
                            goto userop;
            }
		}while(true);
}

void User::usearch()
{
	int isearch=0;
	string temp="";
	cout<< "Enter the search method \n";
	cout<<"1.By Paper Title\n2.By author name\n3.By Journal title\n4.By DOI\n5.By year\n6.Back\n";
	usear:
    cin>>isearch;
	if(cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			isearch = 0;
		}
    switch(isearch)
        {
            case 1: cout<<"Enter Paper title \n";
					break;
            case 2: cout<<"Enter author name \n";
                    break;
            case 3: cout<<"Enter Journal title \n";
                    break;
            case 4: cout<<"Enter DOI \n";
					break;
            case 5: cout<<"Enter year \n";
                    break;
            case 6: return;
            default: cout<<"Invalid response, please try again\n";
                        goto usear;
         }
    cin.get();
    getline(cin,temp);
	System::searchdata(temp,isearch);
}

void User::uStat()
{
    cout<<"1.Group by author\n2.Group by year\n3.Back"<<endl;
    int ch;
    statop:
    cin>>ch;
    if(cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			ch= 0;
		}
    if(ch==3)return;
    if(ch==2 || ch==1)
        System::getStat(ch);
    else
    {
        cout<<"Invalid response, please try again"<<endl;
        goto statop;
    }
    return;
}

void User::uNews()
{
	System::printNews();
}
