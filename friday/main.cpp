/*
ID:thtfive
LANG:C++
TASK:friday
*/
#include<iostream>
#include<fstream>
using namespace std;

int main(){
  ifstream fin;
  ofstream fout;
  fin.open("friday.in");
  fout.open("friday.out");

  int N;
  int leap=0;
  int total=0;
  int arr[7];
  for (int i=0;i<7;i++)arr[i]=0;
  arr[0]=1;

  int year=1900;
  int day=0;
  fin>>N;

  for (year=1900;year<1900+N;year++){
    if ((year%4==0&&year%100!=0)||year%400==0)leap=1;
    else leap=0;
    for (int month=1;month<13;month++){
     if ((year==1900+N-1)&&month==12)break;
     if (month==1||month==3||month==5||month==7||month==8||month==10||month==12){day=31;}
     if (month==2&&leap==0){day=28;}
     if (month==2&&leap==1){day=29;}
     if (month==4||month==6||month==9||month==11){day=30;}
     total+=day;
     total=total%7;

     switch(total){
     case 0: arr[0]++;break;
     case 1: arr[1]++;break;
     case 2: arr[2]++;break;
     case 3: arr[3]++;break;
     case 4: arr[4]++;break;
     case 5: arr[5]++;break;
     default: arr[6]++;break;
     }

    }
  }
    for (int i=0;i<6;i++)fout<<arr[i]<<" ";
    fout<<arr[6]<<"\n";


  return 0;
}
