/*
ID:thtfive
LANG:C++
TASK:namenum
*/
#include<iostream>
using namespace std;
#include<fstream>
#include<queue>

int main(){
    ifstream fin("namenum.in");
    ifstream dictionary("dict.txt");
    ofstream fout("namenum.out");
   // stack a;
    int number;
    string str_store;
    fin>>number;
    queue <string> dict;
    while(dictionary>>str_store){dict.push(str_store);}
    while(!dict.empty()){cout<<dict.front()<<endl;dict.pop();}

return 0;
}
