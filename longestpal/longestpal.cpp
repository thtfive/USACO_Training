#define LOCAL
#include<iostream>
#include<fstream>
#include<cstring>

#include<algorithm>
#include<cmath>

using namespace std;
#define maxN 100010
string s;
int N;
int length[maxN];

int solution()
{
    int result=0;
    return result;
}

int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
    cin>>N;
    string str="AAA";
    tolower(str[1]);
    cout<<str<<"\n";
    for(int i=1;i<=N;i++)
    {
        cin>>s;
        int result=0;
        memset(length,0,sizeof(length));
        int slength=s.length();

        cout<<result<<"\n";
    }

    return 0;
}
