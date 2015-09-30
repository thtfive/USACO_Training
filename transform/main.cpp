/*
ID:thtfive
LANG:C++
TASK:transform
*/
#include<iostream>
#include<fstream>
using namespace std;
int check(char **a,char **b,int N);
void trans0(char **a,char **b,int N);
void trans1(char **a,char **b,int N);
void trans2(char **a,char **b,int N);
void trans3(char **a,char **b,int N);
void trans4(char **a,char **b,int N);
int main(){
  ifstream fin("transform.in");
  ofstream fout("transform.out");
  int N;
  int ans=7;
  char **origin,**reflect,**tmp;
  fin>>N;
  origin=new char*[N];
  reflect=new char*[N];
  tmp=new char*[N];
  for (int i=0;i<N;i++){origin[i]=new char[N];reflect[i]=new char[N];tmp[i]=new char[N];}
  for (int i=0;i<N;i++)
    for (int j=0;j<N;j++)
      fin>>origin[i][j];
  for (int i=0;i<N;i++)
    for (int j=0;j<N;j++)
      fin>>reflect[i][j];



  trans1(origin,tmp,N);///�����Ƿ��ǵ�1�����
  if (check(tmp,reflect,N)){ans=1;goto L0;}

  trans2(origin,tmp,N);///�����Ƿ��ǵ�2�����
  if (check(tmp,reflect,N)){ans=2;goto L0;}

  trans3(origin,tmp,N);///�����Ƿ��ǵ�3�����
  if (check(tmp,reflect,N)){ans=3;goto L0;}

  trans4(origin,tmp,N);///�����Ƿ��ǵ�4�����
  if (check(tmp,reflect,N)){ans=4;goto L0;}

  trans1(tmp,origin,N);///�����Ƿ��ǵ�5�����
  if (check(origin,reflect,N)){ans=5;goto L0;}
  trans1(origin,tmp,N);
  if (check(tmp,reflect,N)){ans=5;goto L0;}
  trans1(tmp,origin,N);
  if (check(origin,reflect,N)){ans=5;goto L0;}

  trans0(origin,tmp,N);///�����Ƿ��ǵ�6�����
  if (check(tmp,reflect,N)){ans=6;goto L0;}


L0:fout<<ans<<"\n";
  return 0;
}

int check(char **a,char **b,int N){
  int answer=1;
  for (int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      if (a[i][j]!=b[i][j]){answer=0;goto L1;}
L1:return answer;
}
void trans0(char **a,char **b,int N){
  for (int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      b[i][j]=a[i][j];
}
void trans1(char **a,char **b,int N){
  for (int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      b[j][N-1-i]=a[i][j];
}
void trans2(char **a,char **b,int N){
for (int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      b[N-1-i][N-1-j]=a[i][j];
}
void trans3(char **a,char **b,int N){
for (int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      b[N-1-j][i]=a[i][j];
}
void trans4(char **a,char **b,int N){
for (int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      b[i][N-1-j]=a[i][j];
}
