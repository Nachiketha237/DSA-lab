#include <stdio.h>
#include<stdlib.h>
# define SIZE 10

int count=0;
void enqueue(int,int [],int*,int*);
int dequeue(int [],int*,int*);
void display(int [],int*,int*);



int main()
{

int ch,ele,queue[SIZE];
int front=0;
int rear=-1;
    while (1)
    {   printf("\n--MENU--\n");
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            printf("Enter the element to be inserted:");
            scanf("%d",&ele);
            enqueue(ele,queue,&front,&rear);
            break;
            case 2:
            dequeue(queue,&front,&rear);
            printf("\nElement has been removed from the queue.");
            break;
            case 3:
            display(queue,&front,&rear);
            break;
            case 4:
            exit(0);
            default:
            printf("Incorrect choice \n");
        }
    }
    return 0;



}


void enqueue(int E,int q[],int *f,int *r)
{
    if(count==SIZE)
    {
        printf("\nQueue is gonna overflowing");

    }
    else
    {   (*r)=((*r))%SIZE;
        (*r)++;
        q[(*r)]=(E);
        count++;
    }


}


int dequeue(int q[],int *f,int *r)
{
    int del_item;
    if(count==0)
    {
        printf("\nQueue does not have any element yet!");

    }
    else
    {
        del_item=q[(*f)];
        (*f)=((*f))%SIZE;
        (*f)++;
        count--;
        return(del_item);
    }





}

void display(int q[],int *f,int *r)
{
    int i,temp;
    temp=(*f);
    for(i=0;i<count;i++)
    {
        printf("%d ",q[temp]);
        temp=(temp)%SIZE;
        temp++;


    }



}
