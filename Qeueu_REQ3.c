
#include <stdio.h>
#include <stdlib.h>



#include"Qeueu_REQ3.h"



ERROR createQueue(ST_queueInfo* info, int maxSize)
{

    info->Queue_ = (int*)malloc( maxSize * sizeof(int) ) ;
    info->Head_of_q = 0 ;
    info->Tail_of_q = 0 ;
    info->flag_ = Straight ;
    info->Q_Size = maxSize ;
    return 0;
}

ERROR enqueue(ST_queueInfo *info, int data)
{
    switch (info->flag_)
	{
	case Straight:
	    {
          if(info->Tail_of_q < info-> Q_Size ) //q dose not reach the maximum
          {
            info->Queue_[info->Tail_of_q ] = data;
            info->Tail_of_q ++;
            return OK ;
          }else
          {
            if( (info->Tail_of_q == info-> Q_Size ) &&  info->Head_of_q !=0 )
            {
              info->Tail_of_q=0;
              info->flag_ = Rotated;
            }else
            {
              return FAILED; // q is full
            }

          }
	    }

		break;


	case Rotated:
	    {
          if(info->Tail_of_q < info->Head_of_q ) //q dose not reach the maximum
          {
            info->Queue_[info->Tail_of_q ] = data;
            info->Tail_of_q ++;
            return OK ;
          }else
          {
           return FAILED; // q is full
          }
	    }

		break;

        default:
		break;
	}
return FAILED;
}


ERROR dequeue(ST_queueInfo *info, int* data)
{

    switch (info->flag_)
	{
	case Straight:
	    {
          if(info->Head_of_q < info->Tail_of_q  ) //q dose not reach the maximum
          {
            *data= info->Queue_[info->Head_of_q];
            info->Head_of_q ++;
            return OK ;
          }else
          {
            if( (info->Head_of_q == info->Tail_of_q ) && info->Tail_of_q != 0 )
            {
                *data= info->Queue_[info->Head_of_q];
              info->Tail_of_q=0;
              info->Head_of_q=0;
              info->flag_ = Straight;
              return OK ;
            }else
            {
              return FAILED; // q is empty
            }

          }
	    }

		break;


	case Rotated:
	    {
          if( info->Head_of_q < info-> Q_Size ) //q dose not reach the maximum
          {
            *data= info->Queue_[info->Head_of_q];
            info->Head_of_q ++;
            return OK ;
          }else
          {
              if( info->Head_of_q == info-> Q_Size  )
              {
                  info->Head_of_q=0;
                 *data= info->Queue_[info->Head_of_q];
                 info->flag_ = Straight;
              }else
              {
                return FAILED; // q is empty
              }

          }


	    }

		break;


        default:
		break;
	}
return FAILED;
}
