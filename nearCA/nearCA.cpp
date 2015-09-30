/*
ID:thtfive
TASK:cowxor
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
#define maxnum 100000+10
//ifstream fin("input.txt");

int N;
int M;
bool flag;
string result;

map<string,string>father;

class person
{
public:
    string name;
    person *father;
    person(){father=NULL;}
    person(string Name,person *Father):name(Name),father(Father){}
}people[101];

void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        string fathertmp,sontmp;
        cin>>fathertmp>>sontmp;
        father[sontmp]=fathertmp;
    }
}

void output()
{
   // cout<<result<<"\n";
   if(flag)
   {
       cout<<result<<"\n";
   }
   else
   {
       cout<<-1<<"\n";
   }
}

void solve()
{
    cin>>M;
    for(int i=0;i<M;i++)
    {
        string name1,name2;
        cin>>name1>>name2;
      //  cout<<name1<<" "<<name2<<"\n";
        flag=false;
        map <string,int>vis;
        while(name1!="")
        {
            vis[name1]=1;
            name1=father[name1];
        }
        while(name2!="")
        {
            if(vis[name2]==1)
            {
                flag=true;
                result=name2;
                break;
            }
            name2=father[name2];
        }
        output();
    }
}

int main()
{
    input();
    solve();
    return 0;
}
