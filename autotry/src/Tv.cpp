#include "Tv.h"

void Tv::volup()
{
    if(volume!=volumeMax)
        volume++;
}
void Tv::voldown()
{
    if(volume)volume--;
}
