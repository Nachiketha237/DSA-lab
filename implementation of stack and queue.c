#include<stdio.h>
#include<stdlib.h>

struct node{
int value;
struct node *next;
};


typedef struct node *NODE;

//For allocating memory space-

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));

    if(temp==NULL)
    {
        printf("Memory could not be allocated.");
    }

    return(temp);

}


//Inserting values at the beginning-

NODE insert_beg(NODE first,int item)
{
    NODE temp;
    temp=getnode();

    temp->value=item;
    temp->next=NULL;

    if(first==NULL)
        return temp;
    else
    {
        temp->next=first;
        first=temp;
        return first;
    }

}

//Inserting at the end-

NODE insert_end(NODE first,int item)
{
    NODE New,last;
    New=getnode();
    New->value=item;
    New->next=NULL;

    if(first==NULL)
        return New;
   
    if(first->next==NULL)
    {
    first->next=New;
    return first;
    }
  
    last=getnode();
    last=first;

    while(last->next!=NULL)
        last=last->next;
    
    last->next=New;



    return first;

}


//For deleting at the beginning-

NODE delete_beg(NODE first)
{
    NODE temp;
    // temp=getnode();

    if(first==NULL)
    {
        printf("There is nothing to delete");
        return NULL;
    }

    temp=first;
    temp=temp->next;

    printf("Item has been deleted:%d\n",first->value);
    free(first);

    return(temp);
}

//For deleting at the end-


NODE delete_end(NODE first)
{
    NODE prev,curr;

    if(first==NULL)
    {
        printf("Nothing to delete");
        return NULL;
    }

    // prev=getnode();
    // curr=getnode();

    prev=NULL;
    curr=first;

    while(curr->next!=NULL)
    {   
        prev=curr;
        curr=curr->next;
    }

    prev->next=NULL;
    free(curr);
    return(first);
}



NODE insert_at_any_position(int item, int pos, NODE first)
{
    NODE curr,newnode,prev;
    int count=1;

    newnode=getnode();
    newnode->value=item;
    newnode->next=NULL;


    if((first==NULL)&&(pos==1))
        return newnode;

    prev=NULL;
    curr=first;

    while((count!=pos)&&(curr!=NULL))
    {
        prev=curr;
        curr=curr->next;
        count++;

    }

    if(count==pos)
    {
        prev->next=newnode;
        newnode->next=curr;
        return first;
    }

    if(curr==NULL)
    {
        printf("Position not found");
        return first;
    }



}


NODE del_specific(NODE first,int key)
{
    NODE prev,curr;

    if(first==NULL)
    {    printf("Nothing to delete");
         return NULL;
    }

    curr=first;
    prev=NULL;

    if(curr->value==key)
    {
        printf("Item deleted:%d",curr->value);
        first=first->next;
        free(curr);
        return(first);
    }

    while((curr->value!=key)&&(curr!=NULL))
    {
        prev=curr;
        curr=curr->next;
    }

    if(curr->value==key)
    {
        prev->next=curr->next;
        printf("Item deleted:%d",curr->value);
        free(curr);
        return first;
    }

    if(curr==NULL)
    {
        printf("End of list reached but item wasnt found.");
        return first;
    }
}


//For displaying-

void display(NODE first)
{
    NODE temp;
    // temp=getnode();
    temp=first;

    while(temp!=NULL)
    {
        printf("%d",temp->value);
        temp=temp->next;
    }
}


int main()
{
    int choice,choice1, item, x,pos;
    NODE stack= NULL;
     NODE queue = NULL;
    while (1)
    {
        printf("\n\nMenu\n-----------------------------------------\n1)stack\n2)queue \n3)Exit\n-----------------------------------------\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:while (1)
                   {
                   printf("\n\nStack\n-----------------------------------------\n1)push\n2)pop\n3)display\n4)Exit\n-----------------------------------------\nEnter your choice : ");
                   scanf("%d", &choice1);
                   switch (choice1)
                   {
                     case 1: printf("Enter the element to be pushed into the stack:");
                             scanf(" %d",&item);
                             stack=insert_beg(stack,item);
                             break;
                    case 2: 
                             stack=delete_beg(stack);
                             printf("Element deleted successfully");
                             break;
                     case 3: printf("Items are:");
                             display(stack);
                             break;
                   
                   
                   default:printf("Enter valid choice\n");
                    break;
                   }
                  }
             case 2:while (1)
                   {
                   printf("\n\nQueue\n-----------------------------------------\n1)enqueue\n2)dequeue\n3)display\n4)Exit\n-----------------------------------------\nEnter your choice : ");
                   scanf("%d", &choice1);
                   switch (choice1)
                   {
                     case 1: printf("Enter the element to be pushed into the queue:");
                             scanf(" %d",&item);
                             queue=insert_beg(queue,item);
                             break;
                    case 2: 
                             queue=delete_end(queue);
                             printf("Element deleted successfully");
                             break;
                     case 3: printf("Items are:");
                             display(queue);
                             break;
                   
                   
                   default:printf("Enter valid choice\n");
                    break;
                   }
                  }
            case 3:exit(0);
                   break;
            default:printf("Enter the valid input\n");
        }
    }
    return 0;
}
