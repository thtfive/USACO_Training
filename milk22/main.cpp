/*
ID: thtfive
LANG: C++
TASK: milk2
*/
#include <iostream>
using namespace std;
#include <fstream>
///this source code is dedicated in solving the milking problem
///It construct a new struct called ST
///every time a new number of the time of a farmer's milking is get, the value is stored in st
/// a serial of function is followed to sovle the problem

struct ST{
    int begin_time[5000];
    int end_time[5000];
    int number;
};

ST st;

ST &insert_time(ST &st,int &begin_time,int &end_time){
    int num=st.number;
    st.begin_time[num]=begin_time;st.end_time[num]=end_time;
    st.number=num+1;
    return st;
}

ST &reorder(ST &st){
    int num=st.number;
    int tmp1=st.begin_time[num-1];
    int tmp2=st.end_time[num-1];
    int tmp=tmp1;
    for (int i=0;i<num;i++){
        if (tmp<st.begin_time[i]){
            for (int j=num-1;j>i;j--){
                st.begin_time[j]=st.begin_time[j-1];
                st.end_time[j]=st.end_time[j-1];
            }
            st.begin_time[i]=tmp1;
            st.end_time[i]=tmp2;
            break;
        }

    }
    return st;
}

ST &shorten(ST &st){
    int num=st.number;
    int flag=1;
    while(flag==1){
        flag=0;
        for(int i=0;i<num-1;i++){
            if (st.end_time[i]>=st.begin_time[i+1]){
                flag=1;
                st.end_time[i]=(st.end_time[i]>st.end_time[i+1]) ? st.end_time[i] : st.end_time[i+1];
                num--;
                for (int j=i+1;j<num;j++){
                    st.begin_time[j]=st.begin_time[j+1];
                    st.end_time[j]=st.end_time[j+1];
                }
            }
        }

    }
    st.number=num;
    return st;
}

///return the max time which at least one farmer is milking
int max_time1(ST &st){
    int num=st.number;
    int tmp_max=0;
    for (int i=0;i<num;i++)
        if ((st.end_time[i]-st.begin_time[i])>tmp_max)
            tmp_max=st.end_time[i]-st.begin_time[i];
    return tmp_max;
}

///return the max time which no farmer is milking
int max_time2(ST &st){
    int num=st.number;
    int tmp_max=0;
    for (int i=0;i<num-1;i++)
        if ((st.begin_time[i+1]-st.end_time[i])>tmp_max)
            tmp_max=st.begin_time[i+1]-st.end_time[i];
    return tmp_max;
}



int main(){
ofstream fout("milk2.out");
ifstream fin("milk2.in");
int N=0;
fin>>N;


int begin_tmp,end_tmp;

for (int i=0;i<N;i++){
    fin>>begin_tmp>>end_tmp;
    st=insert_time(st,begin_tmp,end_tmp);
    st=reorder(st);
    st=shorten(st);
}

int ans1=max_time1(st);
int ans2=max_time2(st);

fout<<ans1<<" "<<ans2<<'\n';
return 0;

}
