#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
int numTri[110][110];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>numTri[i][j];
        }
    }

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            numTri[i][j]+=numTri[i-1][j]>numTri[i-1][j-1]?numTri[i-1][j]:numTri[i-1][j-1];
        }
    }
    int result=0;
    for(int j=1;j<=n;j++)
        result=max(result,numTri[n][j]);
    cout<<result<<"\n";

    return 0;
}
