#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class Student
{
public:
    string name;
    double score;
    Student(){};
    Student(string str,double s):name(str),score(s){};
    Student& operator=(const Student& stu)
    {
        name=stu.name;
        score=stu.score;
        return *this;
    }
    friend ostream & operator<<(ostream &os,const Student& stu)
    {
        os<<"Name: "<<stu.name<<endl;
        os<<"Score: "<<stu.score<<endl;
        return os;
    }
};
int main()
{
    Student ch;
    Student by;
    Student zh("Lily",100);
    ch=by=zh;
    cout<<by;
    return 0;
}
