#include <stdlib.h> 
/* required for rand() */ 
#include <pthread.h>
#include "buffer.h" 
void *producer(void *param) 
{ 
	buffer item item; 
	while (true) 
	{ 
		/* sleep for a random period of time */ 
		sleep(...); /* generate a random number */ 
		
		item = rand(); 
		if (insert item(item)) 
		{
			fprintf("Report error condition");
		}	
		
		else printf("Producer produced %d\n",item); 
	} 
}
void *consumer(void *param) 
{ 
	buffer item item; 
	while (true) 
	{ 
		/* sleep for a random period of time */ 
		sleep(...); 
		
		if (remove item(&item)) 
		{
			fprintf("Report error condition"); 
		}
		
		else printf("Consumer consumed %d\n",item);
	}

}