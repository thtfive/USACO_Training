/*
ID: thtfive
LANG: C++
TASK: ride
*/

#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <string.h>

int main(){
ifstream fin("ride.in");
ofstream fout("ride.out");
char name1[10],name2[10];
fin>>name1>>name2;


int a=0,b=0;
for (int i=0;i<10;i++){if (name1[i]=='\0'){ a=i;break;}}
for (int i=0;i<10;i++){if (name2[i]=='\0'){ b=i;break;}}

int ansa=1,ansb=1;
int tmp=1;
for (int i=0;i<a;i++){tmp=int(name1[i]-'A'+1);ansa*=tmp;}
for (int i=0;i<b;i++)ansb*=int(name2[i]-'A'+1);


if ((ansa%47)==(ansb%47))fout<<"GO"<<"\n";
else fout<<"STAY"<<"\n";


return 0;
}
