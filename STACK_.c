#include <stdio.h>
#include <stdlib.h>

#include"STACK_.h"


ST_stackInfo* createStack(int size)
{
    ST_stackInfo *stack_struct;
    stack_struct = (ST_stackInfo*)malloc( sizeof(ST_stackInfo) );
    stack_struct->arr_stack = (int*)malloc( size * sizeof(int) );
    stack_struct->stack_ize = size;
    stack_struct->top_of_stack = -1;
    return stack_struct;
}

ERROR push(ST_stackInfo *info, int data)
{
   if(  (info)->top_of_stack < ( (info)->stack_ize ) -1  )
   {
       (info)->top_of_stack++;
     (info)->arr_stack[ (info)->top_of_stack ]= data;
     return OK;
   }else
   {
       return FAILED;
   }
}

ERROR pop (ST_stackInfo *info, int* data)
{
    if( (info)->top_of_stack >= STACK_BOTTOM )
    {
       *data =(info)->arr_stack[(info)->top_of_stack];
       (info)->top_of_stack--;
       return OK;
    }else
    {
      return FAILED;
    }

}


ERROR checkForBalancedParantheses(char* String)
{
    ST_stackInfo *Temp_Stack;
    char *String_ptr= String;
    int DATA=0;
    unsigned int String_Size=0;

    while((*String_ptr) != 0)
    {
        String_Size++ ;
        String_ptr++ ;
        printf("S1 Hello S1\n");
    }

   String_ptr=String;

    Temp_Stack = createStack(String_Size);

    while((*String_ptr) != 0)
    {
       if((*String_ptr) != ')' && (*String_ptr) != ']'  && (*String_ptr) != '}' )
       {
              push(Temp_Stack, (*String_ptr));
               String_ptr++;
               printf("S2 Hello S2\n");

       }else
       {

          do
         {
           pop(Temp_Stack, &DATA);
           printf("S3 Hello %c S3\n",DATA);
         }while(  DATA != '(' && DATA != '[' && DATA != '{'  ); //   (())[[]
            printf("S4 Hello %c S4\n",(*String_ptr));
            if((*String_ptr)== ')'  && DATA != '(')
            {return FAILED ;}
            if((*String_ptr)== ']'  && DATA != '[')
            {return FAILED ;}
            if((*String_ptr)== '}'  && DATA != '{')
            {return FAILED ;}

           String_ptr++;

       }


    }

if(Temp_Stack-> top_of_stack >= 0)
 return FAILED;
 else
 {
   return OK;
 }

}
