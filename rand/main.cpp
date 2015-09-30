#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int random();
int main()
{srand(unsigned(time(0)));

 //   srand(unsigned(time(0)));
    for(int i = 0; i != 100; ++i)
      cout << random()<< endl;

    return 0;
}

int random(){

//srand(unsigned(time(0)));

      return rand()%100;;


}
