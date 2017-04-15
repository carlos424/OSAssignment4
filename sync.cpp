
#include "sync.h"

using namespace std;

void *producer0(void *param) 
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
void *consumer0(void *param) 
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
