/*
ID: thtfive
LANG: C++
TASK: milk2
*/
#include <iostream>
using namespace std;
#include <fstream>

ST &insert_time(ST &st,int &begin_tmp,int &end_time);

int main(){
ofstream fout("milk2.out");
ifstream fin("milk2.in");
int N=0;
fin>>N;
struct ST{
    int begin_time[5000];
    int end_time[5000];
    int number=0;
};

ST st;

int begin_tmp,end_tmp;

for (int i=0;i<N;i++){
    fin>>begin_tmp>>end_tmp;
    st=insert_time(st,begin_tmp,end_tmp);
}

return 0;

}

ST &insert_time(ST &st,int &begin_tmp,int &end_time){
    int num=st.number;
    st.begin_time[num]=begin_tmp;st.end_time[num]=end_time;
    st.number=num+1;
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
        }

    }
}

ST &shorten(ST &st){
    num=st.number;
    int flag=1;
    while(flag==1){
        flag=0;
        for(int i=0;i<num-1;i++){
            flag=1;
            if (st.end_time[i]>st.begin_time[i+1]){
                st.end_time[i]=(st.end_time[i]>st.end_time[i+1]) ? st.end_time[i] : st.end_time[i+1];
            }
            num--;
            for (int j=i+1;j<num;j++){
                st.begin_time[j]=st.begin_time[j+1];
                st.end_time[j]=st.end_time[j+1];
            }
        }

    }
}

///return the max time which at least one farmer is milking
int max_time1(ST &st){
    int num=st.number;
    tmp_max=0;
    for (int i=0;i<num;i++)
        if ((end_time[i]-begin_time[i])>tmp_max)
            tmp_max=end_time[i]-begin_time[i];
    return tmp_max;
}

///return the max time which no farmer is milking
int max_time2(ST &st){
    int num=st.number;
    tmp_max=0;
    for (int i=0;i<num-1;i++)
        if (begin_time[i+1]-end_time[i])>tmp_max)
            tmp_max=begin_time[i+1]-end_time[i];
    return tmp_max;
}
