#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int number[14];
void pokervalue(string str)
{
    char ch=str[0];
    if(ch=='A')number[1]++;
    if(ch=='2')number[2]++;
    if(ch=='3')number[3]++;
    if(ch=='4')number[4]++;
    if(ch=='5')number[5]++;
    if(ch=='6')number[6]++;
    if(ch=='7')number[7]++;
    if(ch=='8')number[8]++;
    if(ch=='9')number[9]++;
    if(ch=='T')number[10]++;
    if(ch=='J')number[11]++;
    if(ch=='Q')number[12]++;
    if(ch=='K')number[13]++;
}



int main()
{

    int Test;
    ifstream fin("poker.in");
    fin>>Test;

    for (int T=1;T<=Test;T++)
    {
        for(int i=1;i<=13;i++)
            number[i]=0;
        int N;
        fin>>N;
        string strtmp;
        for(int i=0;i<N;i++)
        {
            fin>>strtmp;
            pokervalue(strtmp);
        }
        uint64_t result=1;
        uint64_t counter=0;
        int usednum[14];

        for(int i=1;i<=13;i++)
            usednum[i]=0;

        for(int k=1;k<=4;k++)
        {
            for(int i=1;i<14;i++)
            {
                if(number[i]>=1)
                {
                    counter++;
                    if(counter-2*usednum[i]<=0)
                        result=0;
                    else
                        result*=(counter-2*usednum[i]);
                    number[i]--;
                    usednum[i]++;
                }
            }
        }
        cout<<"Case #"<<T<<":"<<result<<"\n";
    }
    return 0;
}
