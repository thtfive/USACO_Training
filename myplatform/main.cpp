#include<iostream>

using namespace std;
bool sentment1()
{
    cout<<"google\n";
    return true;
}
bool sentment2()
{
    cout<<"microsoft\n";
    return false;
}
int main()
{
    if (sentment1()&&sentment2())cout<<"facebook\n";

    return 0;

}
