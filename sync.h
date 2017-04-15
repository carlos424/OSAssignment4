#ifndef SYNC_H
#define SYNC_H

#include <stdlib.h> 
/* required for rand() */ 
#include <pthread.h>
#include "buffer.h" 
#include <iostream>
#include <unistd.h>

using namespace std;

void *producer0(void *param) ;

void *consumer0(void *param) ;
#endif

