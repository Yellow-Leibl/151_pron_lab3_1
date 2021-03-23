#include "header.h"

int isDouble(const char * str)
{
    if (!str || !*str) return 0;

    int i = (*str == '+' || *str == '-') ? 1 : 0;
    
    if (i && !isdigit(str[i])) return 0;

    int dot = 1;
    
    for (; str[i]; i++)
        if (!isdigit(str[i]))
        {
            if (str[i] == '.' && dot && i && isdigit(str[i+1]))
                dot = 0;
            else
                return 0;
        }

    return 1;
}