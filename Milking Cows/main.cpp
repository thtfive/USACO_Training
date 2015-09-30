/*
ID:thtfive
LANG:C++
TASK:milk2
*/
#include<iostream>
#include<fstream>
using namespace std;

void addinlist(int *list1,int *list2,int &num,int Begin,int End);
void order(int *list1,int *list2,int &num);
void together(int *list1,int *list2,int &num);
int main(){
  ifstream filein;
  ofstream fileout;
  filein.open("milk2.in");
  fileout.open("milk2.out");

  int N,num=0;
  int *BeginTime,*EndTime;
  int *list1,*list2;
  int milktime=0,unmilktime=0;
  filein>>N;
  BeginTime=new int[N];
  EndTime=new int[N];
  list1=new int[N];
  list2=new int[N];
  for (int i=0;i<N;i++)filein>>BeginTime[i]>>EndTime[i];

 // for (int i=0;i<N;i++)cout<<BeginTime[i]<<" ";
  list1[0]=BeginTime[0];list2[0]=EndTime[0];
  num++;

  for (int i=1;i<N;i++){


    addinlist(list1,list2,num,BeginTime[i],EndTime[i]);
       order(list1,list2,num);
    together(list1,list2,num);
  }


  for(int i=0;i<num-1;i++){
    unmilktime=(list1[i+1]-list2[i])>unmilktime ? (list1[i+1]-list2[i]) : unmilktime;
  }
  for (int i=0;i<num;i++)milktime=(list2[i]-list1[i])>milktime ? (list2[i]-list1[i]) : milktime;
  fileout<<milktime<<" "<<unmilktime<<"\n";
return 0;
}






///***************************************************************************************///
///***************************************************************************************///
void addinlist(int *list1,int *list2,int &num,int Begin,int End)
{
  for (int i=0;i<num;i++){
    if (((Begin<=list1[i])&&(End>=list1[i]))||((Begin>=list1[i]&&Begin<=list2[i]&&End>=list2[i]))){
        list1[i]=list1[i]<Begin ? list1[i]: Begin;
        list2[i]=list2[i]>End ? list2[i]: End;
        break;
    }
    if (i==num-1){list1[num]=Begin;list2[num]=End;num++;}
  }
}

void order(int *list1,int *list2,int &num){
  int tmp1,tmp2;
  for (int i=0;i<num;i++){
    tmp1=list1[0];tmp2=list2[0];
    for (int k=1;k<num-i;k++){
        if(list1[k]<tmp1){
          list1[k-1]=list1[k];list1[k]=tmp1;
          list2[k-1]=list2[k];list2[k]=tmp2;
        }
        tmp1=list1[k];
        tmp2=list2[k];
    }

  }

}

void together(int *list1,int *list2,int &num){
  int time=num;
  while(time){
    for (int i=1;i<num;i++){
      if (list2[i-1]>=list1[i]){
        list2[i-1]=list2[i-1]>list2[i] ? list2[i-1]: list2[i];
        for (int j=i;j<num-1;j++){list1[j]=list1[j+1];list2[j]=list2[j+1];}
        num--;
      }
    }
    time--;
  }
}


