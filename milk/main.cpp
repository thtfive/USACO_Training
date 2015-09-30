/*
ID:thtfive
LANG:C++
TASK:milk
*/
#include <iostream>
using namespace std;
#include <fstream>



int main(){
int TotalMilk,FarmerNumber;
int Cal=0;

ifstream filein("milk.in");
ofstream fileout("milk.out");

filein>>TotalMilk>>FarmerNumber;
//Milk=new int(FarmerNumber);
int Milk[FarmerNumber];
int Price[FarmerNumber];
for(int i=0;i<FarmerNumber;i++)
{
    filein>>Price[i];
    filein>>Milk[i];

}

int num=FarmerNumber;
int P_tmp=0,M_tmp=0;
for (int j=0;j<num;j++)
{
    for (int i=1;i<num;i++)
    {
        if (Price[i-1]>Price[i])
        {
            P_tmp=Price[i];Price[i]=Price[i-1];Price[i-1]=P_tmp;
            M_tmp=Milk[i];Milk[i]=Milk[i-1];Milk[i-1]=M_tmp;
        }
    }
}

int counter=0;
int Money=0;
while(Cal<TotalMilk)
{
    Cal+=Milk[counter];
    counter++;
}

Cal=0;
for(int i=0;i<counter-1;i++)
{
    Cal+=Milk[i];
    Money+=Milk[i]*Price[i];
}

int need=TotalMilk-Cal;
Money+=need*Price[counter-1];
fileout<<Money<<"\n";
return 0;
}
