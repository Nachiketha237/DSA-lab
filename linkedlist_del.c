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
        printf(" %d",temp->value);
        temp=temp->next;
    }
}


int main()
{
    int choice, item, x,pos;
    NODE first = NULL;
    while (1)
    {
        printf("\n\nMenu\n-----------------------------------------\n1) Insert at beginning\n2) Insert at end\n3) Display\n4) Delete at Beginning\n5) Delete at the end\n6) Insert at any Position\n7) Delete a specific Value\n8) Exit\n-----------------------------------------\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &x);
            first = insert_beg(first,x);
            break;
        case 2:
            printf("Enter the element to be inserted : ");
            scanf("%d", &x);
            first = insert_end(first,x);
            break;
        case 3:printf("/nThe items are:");
            display(first);
            break;
        case 4:
            first = delete_beg(first);
            printf("Item has been removed from the first NODE");
            break;
        case 5:
            first = delete_end(first);
            printf("Item has been removed from the last node.");
            break;
        case 6:
            printf("Enter the position to be inserted : ");
            scanf("%d",&pos);
            printf("Enter the element to be inserted : ");
            scanf("%d", &x);
            insert_at_any_position(x,pos,first);
            break;
        case 7:
            printf("Enter the value to be deleted-");
            scanf("%d",&x);
            first=del_specific(first,x);
            printf("\nItem has been removed from the list.");
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Please enter the correct value.");
        }
    }
    return 0;
}
