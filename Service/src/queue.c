#ifndef QUEUE_C_INCLUDED
#define QUEUE_C_INCLUDED
#include"queue.h"

void CreateQueue(Queue *pq){
	pq->First=0;
	pq->Rear=-1;
	pq->Size=0;
}

void append (QueueEntry e, Queue *pq){
	pq->Rear=++(pq->Rear)%MAXQUEUE;
	pq->Entry[pq->Rear]=e;
	pq->Size++;
}

void serve  (QueueEntry *e, Queue *pq){
	*e=pq->Entry[pq->First];
	pq->First=(++pq->First)%MAXQUEUE;
	pq->Size--;
}

int QueueEmpty(Queue *pq){
	return !(pq->Size);

}
int QueueFull(Queue *pq){
	if(pq->Size<MAXQUEUE)
	return 0;
	else
	return 1;

}

int QueueSize(Queue *pq){
	return pq->Size;
}
void QueueClear(Queue *pq){
	pq->First=0;
	pq->Rear=-1;
	pq->Size=0;
}

#endif // QUEUE_C_INCLUDED
