#ifndef COOR
#define COOR

#include <malloc.h>
#include <string.h>
#include <iostream>

#ifdef MEMWATCH
#include "memwatch.h"
#endif
#define SEPAR " \t"

extern int isDouble(const char * str);

extern int dFlag;

enum code_t
{
    WRONG = -1,
    EMPTY,
    OK
};

class coor2
{
    public:
    code_t wellFormed = EMPTY;
    double x;
    double y;
    coor2();
    coor2(double lat, double lot);
    coor2(const char * lat, const char * lot);
    coor2(const char * str);
    ~coor2();
};
#endif