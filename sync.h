#ifndef SYNC_H
#define SYNC_H

#include <stdlib.h> 
/* required for rand() */ 
#include <pthread.h>
#include "buffer.h" 
#include <iostream>
#include <unistd.h>

using namespace std;

void *producer(void *param);

void *consumer(void *param);

#endif

