#ifndef TV_H
#define TV_H

class Tv
{
public:
    Tv():volume(0){}
    void volup();
    void voldown();
protected:
private:
    const int volumeMax=100;
    int volume;
};

#endif // TV_H
