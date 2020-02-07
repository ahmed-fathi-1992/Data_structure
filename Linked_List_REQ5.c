#include <stdio.h>
#include <stdlib.h>


#include"Linked_List_REQ5.h"

#include"STACK_.h"


void createList(ST_list *list_ptr)
{
    list_ptr->header = NULL ;
    list_ptr->counter=0;
}


ERROR Insert_node_at_First( ST_list *list_ptr, int new_data)
{
    ST_node *new_node = (ST_node*) malloc(sizeof(ST_node));
    if(new_node == NULL)
    {
        return FAILED ;
    }
    new_node->data=new_data;
    new_node->next = list_ptr->header;
	 list_ptr->header = new_node;
     return OK ;

}

ERROR Insert_node_at_last( ST_list *list_ptr ,int new_data)
{
      ST_node *Temp_ptr=NULL;
      ST_node *new_node = (ST_node*) malloc(sizeof(ST_node));
       if(new_node == NULL)
      {
        return FAILED ;
      }
      new_node->data=new_data;
      new_node->next=NULL;
      if(list_ptr->header==NULL)
      {
        list_ptr->header = new_node;
      }else
      {
          Temp_ptr=list_ptr->header;
        while (Temp_ptr->next != NULL)
		{Temp_ptr = Temp_ptr->next;}
		Temp_ptr->next = new_node;
      }
return OK ;
}

ERROR insertToList(ST_list *list_ptr,unsigned char position,  int new_data)
{
      unsigned char position_index=0;
      ST_node *Temp_ptr=NULL;
      ST_node *new_node = (ST_node*) malloc(sizeof(ST_node));
      if(new_node == NULL)
      {
        return FAILED ;
      }
      new_node->data=new_data;
      new_node->next=NULL;
      if( list_ptr->counter < position)
      {
        return FAILED ;
      }else
      {
          if(list_ptr->header==NULL)
          {
             list_ptr->header = new_node;
          }else
          {
            Temp_ptr=list_ptr->header;

            for(position_index=0; position_index < position; position_index++ )
		    {Temp_ptr = Temp_ptr->next;}

             new_node->next = Temp_ptr->next ;
		     Temp_ptr = new_node;
          }

      }

return OK ;
}

ERROR deleteFromList(ST_list *list_ptr,unsigned char position)
{
      unsigned char position_index=0;
      ST_node *Temp_ptr=NULL;
     if( list_ptr->counter < position || list_ptr->header==NULL)
      {
        return FAILED ;
      }else
      {
            Temp_ptr=list_ptr->header;

            for(position_index=0; position_index < position; position_index++ )
		    {Temp_ptr = Temp_ptr->next;}

             Temp_ptr = Temp_ptr->next ;
		     free(Temp_ptr);
      }

return OK ;
}

ST_node* searchIntoList(ST_list *list_ptr, int data)
{
           unsigned int position_index=0;
            ST_node *Temp_ptr=NULL;
            Temp_ptr=list_ptr->header;

            while(Temp_ptr->data != data)
            {
              Temp_ptr = Temp_ptr->next;
              position_index++;
            }
return Temp_ptr;

}
