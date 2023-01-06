#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int value;
    struct NODE *next;
};
typedef struct NODE *node;

node insert_at_beginning(int item, node first)
{
    node temp = (node)malloc(sizeof(struct NODE));
    if (temp == NULL)
    {
        printf("\nMemory not allocated!");
    }
    (temp->value) = item;
    (temp->next) = NULL;
    if (first == NULL)
    {
        return temp;
    }
    else
    {
        temp->next = first;
        first = temp;
        return first;
    }
}

node insert_at_end(int item, node first)
{
    node temp = (node)malloc(sizeof(struct NODE));
    if (temp == NULL)
    {
        printf("\nMemory not allocated!");
    }
    (temp->value) = item;
    (temp->next) = NULL;
    if ((first->next) == NULL)
    {
        (first->next) = temp;
        return first;
    }
    else
    {
        node last = first;
        while ((last->next) != NULL)
        {
            last = (last->next);
        }
        (last->next) = temp;
        return first;
    }
}

node insert_at_any_position(int item, int position, node first)
{
    node new, curr, prev;
    new = malloc(sizeof(struct NODE));
    int i = 1;
    (new->value) = item;
    (new->next) = NULL;
    if (first == NULL && position == 1)
    {
        return new;
    }
    else
    {
        prev = NULL;
        curr = first;
        while ((i != position) && (curr != NULL))
        {
            prev = curr;
            curr = (curr->next);
            i++;
        }
        if (i == position)
        {
            prev->next = new;
            new->next = curr;
            return first;
        }
        else if (curr == NULL)
        {
            printf("\nPosition not found!");
            return first;
        }
        else if (first != NULL && position == 1)
        {
            return insert_at_beginning(item, first);
        }
    }
}

node delete_at_the_beginning(node first)
{
    if (first == NULL)
    {
        printf("\nCannot delete, the Linked List is empty");
        return NULL;
    }
    else
    {
        node temp;
        temp = first;
        first = (first->next);
        free(temp);
        return first;
    }
}

node delete_at_the_end(node first)
{
    if (first == NULL)
    {
        printf("\nCannot delete, the Linked List is empty");
        return NULL;
    }
    else
    {
        node prev, curr;
        prev = NULL;
        curr = first;
        while ((curr->next) != NULL)
        {
            prev = curr;
            curr = (curr->next);
        }
        (prev->next) = NULL;
        free(curr);
        return first;
    }
}

node sort(node first)
{
    int temp;
    node curr = first;
    if (first == NULL)
    {
        printf("Linked list is empty!");
        return NULL;
    }
    else
    {
        while (curr->next != NULL)
        {
            node check = curr->next;
            while (check != NULL)
            {
                if (curr->value > check->value)
                {
                    temp = curr->value;
                    curr->value = check->value;
                    check->value = temp;
                }
                check = check->next;
            }
            curr = curr->next;
        }
        return first;
    }
}



node concatenate(node f1, node f2)
{
    if (f1 == NULL && f2 == NULL)
    {
        printf("The linked lists are empty!");
        return NULL;
    }
    else if (f1 != NULL && f2 == NULL)
        return f1;
    else if (f1 == NULL && f2 != NULL)
        return f2;
    else
    {
        node last = f1;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = f2;
        return f1;
    }
}


node reverse(node first)
{
    node nxt,prev=NULL;
    node curr=first;
    if(curr==NULL)
      return NULL;
    else{
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
}

node delete_at_any_position(int pos, node first)
{
    if (first == NULL){
        printf("The linked list is empty!");
        return NULL;
    }
    else if (first->next == NULL)
    {
        if (pos == 1)
            return NULL;
        else{
            printf("Position not found!");
            return NULL;
        }
    }
    else
    {
        int count = 0;
        node prev = NULL, curr = first;
        while ((count != pos) && (curr != NULL))
        {
            prev = curr;
            curr = (curr->next);
            count++;
        }
        if (count == pos)
        {
            prev->next = curr->next;
            free(curr);
            return first;
        }
        else
        {
            printf("\nPosition not found!");
            return first;
        }
    }
}

void display(node first)
{
    node temp;
    temp = first;
    if (temp == NULL)
    {
        printf("\nThe Linked list is empty!");
    }
    else
    {
        printf("The elements in the node are : ");
        while (temp != NULL)
        {
            printf("%d\t", (temp->value));
            temp = (temp->next);
        }
    }
}

int main()
{
    int choice, pos, item, x,val,i;
    node first = NULL,f1=NULL,f2=NULL;
    while (1)
    {
        printf("\n\nMenu\n-----------------------------------------\n1) Insert at beginning\n2) Insert at end\n3) Insert at any position\n4) Delete at beginning\n5) Delete at end\n6) Delete at any position\n7) Display8)Reverse\n9)Sort\n10)Concatenate\n-----------------------------------------\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &x);
            first = insert_at_beginning(x, first);
            break;
        case 2:
            printf("Enter the element to be inserted : ");
            scanf("%d", &x);
            first = insert_at_end(x, first);
            break;
        case 3:
            printf("Enter the position : ");
            scanf("%d", &pos);
            printf("Enter the element to be inserted : ");
            scanf("%d", &x);
            first = insert_at_any_position(x, pos, first);
            break;
        case 4:
            first = delete_at_the_beginning(first);
            break;
        case 5:
            first = delete_at_the_end(first);
            break;
        case 6:
            printf("Enter the position where the element is to be deleted : ");
            scanf("%d", &pos);
            first = delete_at_any_position(pos, first);
            break;
        case 9:
            display(first);
            break;
        case 8:
            printf("Reversing list \n");
            first=reverse(first);
            break;
        case 10: 
            printf("Enter the number of fields for linked list 1 : ");
            scanf("%d", &n);
            printf("Enter %d entries : ", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &val);
                f1 = insert_at_beginning(val, f1);
            }
            printf("Enter the number of fields for linked list 2 : ");
            scanf("%d", &n);
            printf("Enter %d entries : ", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &val);
                f2 = insert_at_beginning(val, f2);
            }
            printf("The concatenated linked list is : ");
            f1 = concatenate(f1, f2);
            display(f1);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}


