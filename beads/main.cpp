/*
ID: thtfive
LANG: C++
TASK: beads
*/

#include <iostream>
using namespace std;
#include <fstream>

void f(int num,char beads[],int *counter);
int maxn(int num,int counter[]);

int main (){
  ofstream fout("beads.out");
  ifstream fin("beads.in");
  int num=0;
  fin>>num;
  char *beads;
  int  *counter;
  counter=new int[num];
  beads=new char[num];

  for(int i=0;i<num;i++)counter[i]=0;
  fin>>beads;
  f(num,beads,counter);//返回连续的珠子的数量

  //for(int i=0;i<num;i++)cout<<counter[i]<<endl;
  int ans=maxn(num,counter);
  fout<<ans<<"\n";
  //cout<<ans;
  delete []counter;
  delete []beads;

  return 0;
}



void f(int num,char beads[],int *counter){

int place=0,i,j;
char left='w',right='w';
while(place<num){
  for (i=place;(beads[i]==right||beads[i]=='w')||right=='w';i=(i+1)%num){
    if (beads[i]!='w' && right=='w')right=beads[i];//decide the right value
    counter[place]++;//count the right-side beads' number
    if (counter[place]>num){counter[place]=num;break;}//if the number is over-big,exit
    }

   for (j=(place+num-1)%num;beads[j]==left||beads[j]=='w'||left=='w';j=(j+num-1)%num){
    if (beads[j]!='w'&&left=='w')left=beads[j];
    counter[place]++;
    if (counter[place]>num){counter[place]=num;break;}

  }

  if (counter[place]>num){counter[place]=num;break;}
  left='w',right='w';
  place++;
}


}


int maxn(int num,int counter[]){
int maxnum=counter[0];
for (int i=1;i<num;i++)
  if (maxnum<counter[i])maxnum=counter[i];
return maxnum;
}
