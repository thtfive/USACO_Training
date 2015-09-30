/*
ID:thtfive
LANG:C++
TASK:gift1
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main(){
  ifstream fin;
  ofstream fout;
  fin.open("gift1.in");
  fout.open("gift1.out");

  int NP;
  fin>>NP;
  char name[10][14];
  char nametmp[14];
  int account[10];
  for(int i=0;i<10;i++)account[i]=0;
  int money=0,num=0,left=0,PerGet=0;
  for (int i=0;i<NP;i++)fin>>name[i];

  while(fin>>nametmp){
    fin>>money>>num;
    if (num!=0){
    PerGet=money/num;
    left=money%num;}
    else {money=0;left=0;PerGet=0;}
    for (int i=0;i<NP;i++)if (strcmp(nametmp,name[i])==0){account[i]-=(money-left);}
    for (int i=0;i<num;i++){
        fin>>nametmp;
        int place=0;
        for (int j=0;j<NP;j++)if (strcmp(nametmp,name[j])==0){place=j;break;}
 //       cout<<place<<" "<<PerGet<<" ";
        account[place]+=PerGet;
    }
  }

  for (int i=0;i<NP;i++)fout<<name[i]<<" "<<account[i]<<"\n";





return 0;
}
