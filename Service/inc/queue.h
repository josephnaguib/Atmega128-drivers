#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 100
#define QueueEntry char

typedef struct queue{
	QueueEntry Entry[MAXQUEUE];
	int First;
	int Rear;
	int Size;
}Queue;

void CreateQueue(Queue *pq);
void append (QueueEntry e, Queue *pq);
void serve  (QueueEntry *e, Queue *pq);
int QueueEmpty(Queue *pq);
int QueueFull(Queue *pq);
int QueueSize(Queue *pq);
void QueueClear(Queue *pq);


#endif // QUEUE_H_INCLUDED
