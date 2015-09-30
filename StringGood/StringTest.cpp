#include <iostream>
#include <stack>
#include "StringGood.h"
using std::cout;
void printv(const StringGood S)
{
    cout<<S;
}
void printr(const StringGood& S)
{
    std::cout<<S;
}
int main()
{
    StringGood s1,s2("zhang");
    StringGood s3=s1=s2;
    printr(s2);
    StringGood* p(&s1);
    std::cout<<p<<std::endl;

    return 0;
}
