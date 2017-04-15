#include <stdlib.h> 
/* required for rand() */ 
#include <pthread.h>
#include "buffer.h" 
#include <iostream>
#include <unistd.h>

using namespace std;

void *producer(void *param) 
{ 
	buffer_item item; 
	while (true) 
	{ 
		/* sleep for a random period of time */ 
		sleep(rand()); 
		/* generate a random number */ 
		
		item = rand(); 
		if (insert_item(item))
		{
			cout << "Report error condition" << endl;
		}	
		
		else cout << "Producer produced %d\n " << item << endl; 
	} 
}
void *consumer(void *param) 
{ 
	buffer_item item; 
	while (true) 
	{ 
		/* sleep for a random period of time */ 
		sleep(rand()); 
		
		if (remove_item(&item)) 
		{
			cout << "Report error condition" << endl; 
		}
		
		else cout << "Consumer consumed %d\n " << item << endl;
	}

}
