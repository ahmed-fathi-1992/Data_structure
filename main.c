#include <stdio.h>
#include <stdlib.h>

#include"STACK_.h"
#include"Qeueu_REQ3.h"

int main()
{
//    ST_stackInfo *Test;
    ST_queueInfo q_test;
    ERROR E_RROR=OK;
    int DATA=0;
/*
    Test = createStack(10);
    push(Test, 6);
    push(Test, 7);
        push(Test, 6);
    push(Test, 7);
        push(Test, 6);
    push(Test, 7);
        push(Test, 6);
    push(Test, 7);
        push(Test, 6);
      //  push(Test, 6);
//push(Test, 6);
  //  pop (Test, &DATA);
//printf("Hello fathi \n");
   // if(pop (Test, &DATA) == FAILED)
   if(push(Test, 6) == FAILED)
    {
      printf("Hello Failed \n");
    }else
    {
       printf("Hello ok %d\n",DATA);
    }
printf("EN \n");
    if(checkForBalancedParantheses("(())[[]]{}") == OK)
         printf("Hello okkk \n");
    else
       printf("Hello nooo \n");

printf("OUT \n");
*/
printf("S1 Hello S1\n");
E_RROR = createQueue(&q_test, 5);
E_RROR = enqueue(&q_test, 2);
E_RROR = enqueue(&q_test, 3);
E_RROR = enqueue(&q_test, 4);
E_RROR = enqueue(&q_test, 5);
//E_RROR = enqueue(&q_test, 6);
//E_RROR = enqueue(&q_test, 7);

E_RROR = dequeue(&q_test, &DATA);
//E_RROR = dequeue(&q_test, &DATA);
E_RROR = enqueue(&q_test, 6);
E_RROR = enqueue(&q_test, 7);
//E_RROR = OK;
if(E_RROR == OK)
printf("S2 %d Hello %d S2\n",q_test.Queue_[4],DATA);
else
{
printf("Hello nooo \n");
}
  while(1);
    return 0;
}
