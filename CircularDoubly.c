#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *start;
void addatbeg(int n)
{
    struct Node *p,*t;
    p=(struct Node *)malloc(sizeof(struct Node));
    if(start==NULL)
    {
        p->data=n;
        p->next=p;
        p->prev=p;
        start=p;
    }
    else
    {
        t=start;
        while(t->next!=start)
        {
            t=t->next;
        }
        t->next=p;
        p->prev=t;
        t->next=start;
        start->prev=p;
        p->data=n;
        start=p;
    }
}
void addatend(int n)
{
    struct Node *p,*t;
    p=(struct Node *)malloc(sizeof(struct Node));
    if(start==NULL)
    {
        p->data=n;
        p->next=p;
        p->prev=p;
    }
    else
    {
        t=start;
        while(t->next!=start)
        {
            t=t->next;
        }
        p->prev=t;
        p->next=start;
        t->next=p;
        start->prev=p;
    }
}
void delfrombeg()
{
    struct Node *p,*t;
    t=start;
    p=start;
    if(start!=NULL)
    {
        while(t->next!=start)
        {
        t=t->next;
        }
        start=start->next;
        t->next=start;
        start->prev=t;
        free(p);
    }
    else
    {
        printf("Not Possible");
    }
}
void delfromend()
{
    struct Node *p,*t;
    t=start;
    if(start!=NULL)
    {
        while(t->next->next!=start)
        {
            t=t->next;
        }
        p=t->next;
        t->next=start;
        start->prev=t;
        free(p);
    }
    else
    {
        printf("Not Possible");
    }
}
void display()
{
    struct Node *t;
    t=start;
    if(start!=NULL)
    {
        while(t!=start)
        {
            printf("%d",t->data);
            t=t->next;
        } 
        printf("\n");
    }
    else
    {
        printf("Not Possible");
    }
}
void main()
{
    int choice,n;
    while(1)
    {
        printf("1. ADD DATA AT BEGINNING\n");
        printf("2. ADD DATA AT END\n");
        printf("3. DELETE DATA DROM BEGINNING\n");
        printf("4. DELETE DATA FROM END\n");
        printf("5. DISPLAY DATA\n");
        printf("6. EXIT\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter a number");
            scanf("%d",&n);
            addatbeg(n);
            break;

            case 2:printf("Enter a number");
            scanf("%d",&n);
            addatend(n);
            break;

            case 3:delfrombeg();
            break;

            case 4:delfromend();
            break;

            case 5:display();
            break;

            case 6:exit(0);
            break;

            default:printf("Invalid Input");
        }
    }
}
