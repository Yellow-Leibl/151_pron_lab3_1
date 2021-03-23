#ifndef RECTANGLE
#define RECTANGLE

#include "coor.h"

#ifdef MEMWATCH
#include "memwatch.h"
#endif

#define RECBUF 128

class rectangle
{
    public:
    coor2 leftBottom;
    coor2 rightTop;
    static char buf[RECBUF];

    rectangle();
    
    void expande(coor2& nextPoint);
    char * print(const int only6);
    ~rectangle();
};
#endif