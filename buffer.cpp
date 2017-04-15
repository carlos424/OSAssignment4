#include "buffer.h" 

/* the buffer */ 

buffer_item buffer[BUFFER_SIZE];
int count = 0;
int insert_item(buffer_item item) 
{ 
	/* insert item into buffer return 0 if successful, 
	otherwise return -1 indicating an error condition */
	
	if(count == BUFFER_SIZE)
	{
		return -1;
	}
	
	buffer[count] = item;
	count++;
	return 0;
	


} 

int remove_item(buffer_item *item) 
{ 
	/* remove an object from buffer placing it in item return 0 if successful, 
	otherwise return -1 indicating an error condition */ 
	
	if(count == 0)
	{
		return -1;
	}
	
	buffer[count-1];
	count--;
	return 0;
}


