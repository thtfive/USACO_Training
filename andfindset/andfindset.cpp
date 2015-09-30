#define LOCAL
#include<iostream>
#include<map>
#include<fstream>
#include<algorithm>
using namespace std;

map <string,string>relation;
int N;

string findboss(string name)
{
    return relation[name]==name?name:relation[name]=findboss(relation[name]);
}
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
    int op;
    cin>>N;
    string name1,name2;
    for(int i=0;i<N;i++)
    {
        cin>>op>>name1>>name2;
        if(relation[name1]=="")relation[name1]=name1;
        if(relation[name2]=="")relation[name2]=name2;
        string boss1=findboss(name1);
        string boss2=findboss(name2);
        if(op==0)
        {
            relation[boss1]=boss2;
        }
        else
        {
            if(boss1==boss2)cout<<"yes\n";
            else cout<<"no\n";
        }
    }
}
