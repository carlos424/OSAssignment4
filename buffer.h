#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
using namespace std;
/* buffer.h */ 
#include <pthread.h>
typedef int buffer_item; 
#define BUFFER_SIZE 5


int insert_item(buffer_item item);
int remove_item(buffer_item *item);

#endif
