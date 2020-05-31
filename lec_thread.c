#include <stdio.h>
#include <pthread.h>

void thread(void *vargp) {
	printf("hello world\n");
}

int main() 
{
	pthread_t tid;
	pthread_create(&tid, NULL, (*thread)(void*), NULL);
	pthread_join(tid, NULL);
	exit(0);
}


