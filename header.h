/* Lab 3.1
** Прямокутник, що містить трек
** Copyright (C) 2020 - 2021 Pron Egor
** All rights reserved.
** Version 1.01
** 
****************************************
** 
** ОПИС:
** 
** Ця програма вираховує мінімальні
** координати прямокутника, який буде
** містити весь трек.
** 
****************************************
*/

#ifndef LAB3_1
#define LAB3_1

#include <stdio.h>
#include <ctime>
#include <time.h>
#include <iostream>
#include <malloc.h>
#include <string.h>

#ifdef MEMWATCH
#include "memwatch.h"
#endif

#define BUFSZ 1024

using std::cout;
using std::endl;
using std::exit;

extern int keycmp(const char * arg, const char * key);
extern int isHelp(const char * s);

#if 1
//  підтримка c++ для memwatch (також у mematch.h: 
//  #if 0 /* 980317: disabled C++ */ #if
// і у memwatch.c: #if 0 /* 980317: disabled C++ */ 0 замінити на 1
#ifdef MEMWATCH
#define new mwNew
#define delete mwDelete
#endif
#endif

#endif