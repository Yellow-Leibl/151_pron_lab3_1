#include "header.h"

#ifdef _MSC_VER
#define strcasecmp stricmp
#endif

int keycmp(const char * arg, const char * key)
{
    if (arg && key)
        if (*arg == '-' || *arg == '/')
            if (!strcasecmp(arg+1, key))
                return 1;
    return 0;
}

int isHelp(const char * s)
{
    return keycmp(s, "h") + keycmp(s, "help") + keycmp(s, "?");
}