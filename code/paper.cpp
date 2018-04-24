#include <bits/stdc++.h>
using namespace std;
#include "paper.h"
Paper::Paper()
{
    papername="untitled";
    author={};
    journal="";
    doi="";
    year="";
    vol=0;
    issue=0;
    page[0]="0";
    page[1]="0";
}
Paper::Paper(string name, vector<string> auth, string journ, string id, string yr, int v, int n, string p1, string p2)
{
    papername=name;
    journal=journ;
    doi=id;
    year=yr;
    vol=v;
    issue=n;
    page[0]=p1;
    page[1]=p2;
    int l=auth.size();
    for(int i=0;i<l;i++)
    {
        author.push_back(auth[i]);
    }
}
Paper Paper:: tryPaper(string bib)
{
    string name="";//parameter 1
    vector<string> auth={};//parameter 2
    string journ="";//parameter 3
    string id="";//parameter 4
    string yr="";//parameter 5
    int v=0;
    int n=0;
    string p1="";
    string p2="";
    int i=0;
    char c=bib[i];
    int l=bib.length();
    string temp="";
    while(c!='"')
    {
        if(c!=',')
        {
            if(c==' '&&bib[i+1]=='a'&&bib[i+2]=='n'&&bib[i+3]=='d'&&bib[i+4]==' ')
            {
                i=i+4;
                c=bib[i];
                auth.push_back(temp);
                temp="";
            }
            else
            {
                temp=temp+c;
            }
        }
        else
        {
            auth.push_back(temp);
            temp="";
        }
        i++;
        if(c==',')i++;
        if(i>=l)
        {
            return Paper();
        }
        c=bib[i];
    }
    i++;
    if(i>=l)
    {
        return Paper();
    }
    c=bib[i];
    temp="";
    while(!(c==','&&bib[i+1]=='"'))
    {
        temp=temp+c;
        i++;
        if(i>=l)
        {
            return Paper();
        }
        c=bib[i];
    }
    name=temp;
    temp="";
    i+=2;
    if(i>=l)
    {
        return Paper();
    }
    c=bib[i];
    if(c==' '){i++;c=bib[i];}
    while(c!=',')
    {
        temp=temp+c;
        i++;
        if(i>=l)
        {
            return Paper();
        }
        c=bib[i];
    }
    journ=temp;
    i=i+6;
    if(i>=l)
    {
        return Paper();
    }
    c=bib[i];
    while(c!=',')
    {
        if(c>'9' || c<'0')
            return Paper();
        v=v*10+(int)(c-48);
        i++;
        c=bib[i];
    }
    i=i+5;
    if(i>=l)
    {
        return Paper();
    }
    c=bib[i];
    while(c!=',')
    {
        if(c>'9' || c<'0')
            return Paper();
        n=n*10+(int)(c-48);
        i++;
        if(i>=l)
        {
            return Paper();
        }
        c=bib[i];
    }
    i=i+5;
    if(i>=l)
    {
        return Paper();
    }
    c=bib[i];
    temp="";
    while(c!='-')
    {
        temp=temp+c;
        i++;
        if(i>=l)
        {
            return Paper();
        }
        c=bib[i];
    }
    i++;
    if(i>=l)
    {
        return Paper();
    }
    p1=temp;
    c=bib[i];
    temp="";
    while(c!=',')
    {
        temp=temp+c;
        i++;
        if(i>=l)
        {
            return Paper();
        }
        c=bib[i];
    }
    p2=temp;
    i=i+2;
    if(i>=l)
    {
        return Paper();
    }
    c=bib[i];
    temp="";
    while(c!='.'&&i<l)
    {
        temp=temp+c;
        i++;
        if(i>=l)
        {
            return Paper();
        }
        c=bib[i];
    }
    yr=temp;
    temp="";
    i=i+6;
    if(i>=l)
    {
        return Paper();
    }
    c=bib[i];
    if(c==' '){i++;c=bib[i];}
    while(i<l)
    {
        temp=temp+c;
        i++;
        c=bib[i];
    }
    id=temp;
    return Paper(name, auth, journ, id, yr, v, n, p1, p2);
}
string Paper::getBib()
{
    string bib;
    string auth="";
    int n=author.size();
    if(n>2)
    {
        auth=author[0];
        for(int i=1;i<n-1;i++)
        {
            auth=auth+", "+author[i];
        }
        auth=auth+" and "+author[n-1];
    }
    else
    {
        if(n==1)auth=author[0];
        if(n==2)auth=author[0]+" and "+author[1];
    }
    bib=auth+", \""+papername+",\" "+journal+", vol."+to_string(vol)+", no."+to_string(issue)+", pp."+page[0]+"-"+page[1]+", "+year+".";
    if(doi.length()!=0)
        bib=bib+" doi:"+doi;
    return bib;
}
