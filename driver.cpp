#include "buffer.h" 
#include <pthread.h>
#include "sync.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{ 

	/* 1. Get command line arguments argv[1],argv[2],argv[3] */ 
	int sleepTime = *argv[1] - 48;
	int numProducer = *argv[2] - 48;
	int numConsumer = *argv[3] - 48;

		
	/* 2. Initialize buffer */ 
	buffer_item buffer[BUFFER_SIZE];

	/* 3. Create producer thread(s) */ 
	pthread_t producers[numProducer];

	for(int i = 0 ; i< numProducer; i++)
	{
		pthread_mutex_t mxq;
		pthread_mutex_init(&mxq,NULL);
		pthread_mutex_lock(&mxq);
		
		int rc;
		void *p;
		rc = pthread_create(&producers[i],NULL, producer,p);
		
		if(rc)
		{
			cout << "The pthread was not created properly!" << endl;
			return -1;
		}
		
		pthread_mutex_unlock(&mxq);
		pthread_join(producers[i],NULL);

	}

	/* 4. Create consumer thread(s) */ 
	pthread_t consumers[numConsumer];
	for(int i = 0 ; i< numConsumer; i++)
	{
		pthread_mutex_t mxq;
		pthread_mutex_init(&mxq,NULL);
		pthread_mutex_lock(&mxq);
		
		int rc;
		long *p;
		rc = pthread_create(&consumers[i],NULL, consumer,p);
		
		if(rc)
		{
			cout << "The pthread was not created properly!" << endl;
			return -1;
		}
		
		pthread_mutex_unlock(&mxq);
		pthread_join(consumers[i],NULL);
		
	}


	/* 5. Sleep */
	cout << "I'm sleeping for: "<< sleepTime << endl;
	sleep(sleepTime);
	
	cout << "All done! Naisu!" << endl;
	/* 6. Exit */ 
	return 0;
}

