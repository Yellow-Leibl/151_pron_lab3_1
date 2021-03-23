#include "header.h"

int main(int argc, char ** argv)
{
    uint start_time = clock();
    time_t sT = time(0);
    int dFlag = 0;
    int vFlag = 0;
    int only6 = 0;

    for (int i = 1; i < argc; i++)
    {
        if (isHelp(argv[i]))
        {
            printf("a.exe [-?] [-v] [-d] [-8]\n");
            exit(1);
        }
        else if (keycmp(argv[i], "v"))
            vFlag = 1;
        else if (keycmp(argv[i], "d"))
            dFlag = 1;
        else if (keycmp(argv[i + 1], "6"))
            only6 = 6;
        else if (keycmp(argv[i + 1], "8"))
            only6 = 0;
    }
    
    rectangle * r = new rectangle();
    
    char buf[BUFSZ + 1] = {0};
    char * nLine = 0;
    coor2 * a = 0;
    while (fgets(buf, BUFSZ, stdin))
    {
        nLine = (char *)memchr(buf, '\n', BUFSZ);
        if (nLine)
            *nLine = 0;
        nLine = (char *)memchr(buf, '#', BUFSZ);
        if (nLine)
            *nLine = 0;
        
        a = new coor2(buf);
        if (a->wellFormed != OK)
        {
            if (vFlag)
                fprintf(stderr, "Error '%s'\n", buf);
        }
        else
            r->expande(*a);
        
        delete a;
        a = 0;
    }
    
    cout << r->print(only6);
    delete r; r = 0;

    if (vFlag)
    {
        time_t eT = time(0);
        fprintf(stderr, "%f secs\t- working time (clock)\n",
                (double)(clock() - start_time)/CLOCKS_PER_SEC);
        fprintf(stderr, "%f secs\t\t- working time (time)\n",
                difftime(eT, sT));
    }
}