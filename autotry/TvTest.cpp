#include <iostream>
#include <algorithm>
#include "Tv.h"
#include <cstdlib>
using namespace std;

class person
{
private:
    string name;
    long long id;

public:
    person(string s,long long i):name(s),id(i){}
}Obj("zhang",232312);

class badperson:public person
{
private:
    int inprisontime;
public:
};


int main()
{
    int n;
    while(cin>>n,n!=-1)
    {
        if(n==0)
            abort();
        else
            cout<<n<<endl;
    }
    return 0;
}
