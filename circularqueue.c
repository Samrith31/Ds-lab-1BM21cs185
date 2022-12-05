#include<stdio.h>
#include<stdlib.h>
int front =-1 , rear=-1 , MAX=3;
void insert(int q[])
{
    int e;
    printf("\nEnter the element to be inerted: ");
    scanf("%d",&e);
    if((front==-1)&&(rear==-1))
    {
        q[++front]=e;
        rear++;
    }
    else if(((rear==MAX-1)&&(front == 0))||(front == rear+1))
    {
        printf("\nOverflow\n");
    }
    else if((rear==MAX-1)&&(front!=0))
    {
        rear = 0;
        q[rear] = e;
    }
    else
    {
        q[++rear]=e;
    }
}

void delete(int q[])
{
    int e;
    if((rear==-1))
    {
        printf("\nUnderflow\n");
    }
    else
    {
        e=q[front];
        printf("\nElement removed: %d",e);
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            if(front==MAX-1)
                front=0;
            else
                front++;
        }
    }
}
void display(int q[])
{
    int i;
    if(front==-1)
        printf("\nQueue is empty\n");
    else
    {
        printf("\nQueue elements are: ");
        if((rear>=front)&&(rear<MAX))
        {
            for(i=front;i<=rear;i++)
                printf("%d\t",q[i]);
        }
        else
        {
            for(i=front;i<=MAX-1;i++)
                printf("%d\t",q[i]);
            for(i=0;i<front;i++)
                printf("%d\t",q[i]);
        }
    }
}
int main()
{
    int q[100],choice,e;
    do
    {
        printf("\nEnter the choice for the options in the queue.\n1. Insert option\n2. Delete option\n3. Display option\n4. Exit the process\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(q);
                    break;
            case 2: delete(q);
                    break;
            case 3: display(q);
                    break;
            case 4: printf("\nExiting the program!");
                    exit(0);
                    break;
            default: printf("Invalid Choice!");
                     break;
        }
    } while (1);

}





