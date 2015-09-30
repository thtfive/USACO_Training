#include<iostream>
#include<cstring>
using namespace std;
extern int dfs;
static int global;
int local;
void remote_access()
{
    cout<<"remote_access() reports the address:\n";
    cout<<"&dfs="<<&dfs<<", &global="<<&global<<", &local="<<&local<<"\n";
    return;
}
