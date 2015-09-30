/*
ID:thtfive
LANG:C++
TASK:spin
*/
#include<iostream>
#include<fstream>
using namespace std;


int main()
{
    ifstream fin("spin.in");
    ofstream fout("spin.out");
    int mark[5][360];
    for (int i=0;i<5;i++)
        for (int j=0;j<360;j++)
            mark[i][j]=0;

    int speed[5];
    int Dplace[5];
    for (int i=0;i<5;i++)Dplace[i]=0;

    for (int i=0;i<5;i++)
    {
        fin>>speed[i];
        int num;
        fin>>num;
        while(num>0)
        {
            num--;
            int start;
            int length;
            fin>>start>>length;
            for (int k=start;k<=start+length;k++)
            {
                mark[i][k%360]=1;
            }
        }
    }


//    for (int j=0;j<60;j++)
//    {
//        if(mark[4][j]==1)cout<<j<<endl;
//    }


    bool isfind=false;
    int step=0;
    int wedge[360];

    while(1)
    {
        for (int j=0;j<360;j++)
        {
            wedge[j]=mark[0][(j+360-Dplace[0])%360]+mark[1][(j+360-Dplace[1])%360];
            wedge[j]+=mark[2][(j+360-Dplace[2])%360];
            wedge[j]+=mark[3][(j+360-Dplace[3])%360];
            wedge[j]+=mark[4][(j+360-Dplace[4])%360];

            if(wedge[j]==5)
            {
                isfind=true;
                break;
//                cout<<"j:"<<j<<endl;
            }
        }
//        cout<<endl;
//        cout<<"step:"<<step<<"\n";
//        for (int k=0;k<360;k+=30)
//            cout<<mark[3][(k+360-Dplace[3])%360]<<" ";
//        cout<<endl;
        for (int i=0;i<5;i++)
        {
            Dplace[i]=(Dplace[i]+speed[i])%360;
        }
//        for (int i=0;i<5;i++)
//        {
//            cout<<Dplace[i]<<" "<<speed[i]<<endl;
//        }
//        cout<<endl;


        if(Dplace[0]==0&&Dplace[1]==0&&Dplace[2]==0&&Dplace[3]==0&&Dplace[4]==0)break;
        if(isfind)break;
        step++;
    }

    if (isfind)cout<<step<<"\n";
    else cout<<"none\n";

    if (isfind)fout<<step<<"\n";
    else fout<<"none\n";



    return 0;
}
