#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int queue[10];
int front=-1,rear=-1;
void enque(int);
int deque();
void display();
void main()
{
    int choice,n,del;
    system("clear");
    while(1)
    {
        
        printf("Press 1 to enque \n Press 2 to deque \n Press to disp1lay \n Press 4 to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the number to be inserted\n");
            scanf("%d",&n);
            enque(n);
            break;

            case 2: del=deque();
            printf("%d is deleted from the queue\n",del);
            break;

            case 3:printf("The queue is \n");
            display();
            break;

            case 4: exit(0);
            break;

            default: printf("Invalid choice");

        }
        system("clear");
    }
    
}
void enque(int n)
{
    if(front == -1 && rear == -1)
    {
        front=rear=0;
        queue[rear]=n;
    }
    else if ((rear+1) % 10 == front)
    {
        printf("Queue is full");
    }
    else
    {
        rear=(rear+1) % 10;
        queue[rear]=n;
    
    }
}
int deque()
{
    int v;
    if(front==-1 || rear==-1)
    {
        printf("Queue Empty\n");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        v=queue[front];
        front=(front+1) % 10;
    }
    return v;
}
void display()
{
    int i= front-1;
    while (i!=rear)
    {
        i=(i+1) % 10;
        printf(queue[i]);
    }
    printf("\n");
}
