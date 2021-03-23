#include "coor.h"

coor2::coor2() : coor2(0.0, 0.0) { wellFormed = EMPTY; }

coor2::coor2(double lat, double lot) : x(lat), y(lot) { wellFormed = OK; }

coor2::coor2(const char * lat, const char * lot)
{
    if (isDouble(lat) && isDouble(lot))
    {
        x = atof(lat);
        y = atof(lot);
        wellFormed = OK;
    }
    else
    {
        wellFormed = WRONG;
        x = 0.0;
        y = 0.0;
    }
}

coor2::coor2(const char * str)
{
    if (str)
    {
        char * t = (char *)malloc(strlen(str) + 1);
        strcpy(t, str);
        char * xStr = strtok(t, SEPAR);
        char * yStr = strtok(0, SEPAR);
        if (isDouble(xStr) && isDouble(yStr))
        {
            x = atof(xStr);
            y = atof(yStr);
            wellFormed = OK;
        }
        else
        {
            x = 0.0;
            y = 0.0;
            wellFormed = WRONG;
        }
        free(t); t = 0;
        xStr = 0; yStr = 0;
    }
    else
    {
        wellFormed = WRONG;
        x = 0.0;
        y = 0.0;
    }
}

coor2::~coor2()
{
    fprintf(stderr, "Destructor coor2(%f; %f) is here\n", x, y);
}