#include "rectangle.h"

rectangle::rectangle()
{
    leftBottom = coor2();
    rightTop = coor2();
}

void rectangle::expande(coor2& nextPoint)
{
    if (leftBottom.wellFormed == EMPTY)
    {
        leftBottom = nextPoint;
        rightTop = leftBottom;
    }
    if (nextPoint.x > rightTop.x)
        rightTop.x = nextPoint.x;
    if (nextPoint.x < leftBottom.x)
        leftBottom.x = nextPoint.x;
    if (nextPoint.y > rightTop.y)
        rightTop.y = nextPoint.y;
    if (nextPoint.y < leftBottom.y)
        leftBottom.y = nextPoint.y;
}

char rectangle::buf[RECBUF] = {0};
char * rectangle::print(const int only6)
{
    if (only6)
        sprintf(buf, "leftBottom(%.6f; %.6f),\nrightTop(%.6f; %.6f)\n",
                leftBottom.x, leftBottom.y, rightTop.x, rightTop.y);
    else
        sprintf(buf, "leftBottom(%.8f; %.8f),\nrightTop(%.8f; %.8f)\n",
                leftBottom.x, leftBottom.y, rightTop.x, rightTop.y);
    
    return buf;
}

rectangle::~rectangle()
{
    if (dFlag)
        fprintf(stderr, "Destructor rectangle() is here\n");
}