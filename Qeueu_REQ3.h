#ifndef QEUEU_REQ3_H_INCLUDED
#define QEUEU_REQ3_H_INCLUDED

#include"STACK_.h"

typedef enum Rotate_Flag{
	Straight,
	Rotated
}Rotate_Flag;

typedef struct ST_queueInfo{
int  Q_Size ;
int *Queue_ ;
int Head_of_q;
int Tail_of_q;
Rotate_Flag flag_;

}ST_queueInfo;


ERROR createQueue(ST_queueInfo* info, int maxSize);
ERROR enqueue(ST_queueInfo *info, int data);
ERROR dequeue(ST_queueInfo *info, int* data);


#endif // QEUEU_REQ3_H_INCLUDED
