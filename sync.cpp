
#include "sync.h"

using namespace std;

void *producer(void *param) 
{ 
	buffer_item item; 
	bool cont = true;
	while (cont) 
	{ 
		/* sleep for a random period of time */ 
		sleep(rand()%5); 
		/* generate a random number */ 
		
		item = rand(); 
		if (insert_item(item))
		{
			cout << "The buffer is full, Naisu!" << endl;
			cont = false;
		}	
		
		else cout << "Producer produced: " << item << endl; 
	} 
}
void *consumer(void *param) 
{ 
	buffer_item item; 
	bool cont = true;
	while (cont) 
	{ 
		/* sleep for a random period of time */ 
		sleep(rand()%5); 
		item = rand(); 
		if (remove_item(&item)) 
		{
			cout << "The buffer is empty, Naisu!" << endl;
			cont = false;
		}
		
		else cout << "Consumer consumed: " << item << endl;
	}

}
