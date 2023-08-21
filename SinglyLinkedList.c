#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *start;
void addatbeg(int n)
{
    struct Node *newnode;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    if(start==NULL)
    {
        newnode->data=n;
        newnode->next=NULL;
        start=newnode;
    } 
    else
    {
        newnode->data=n;
        newnode->next=start;
        start=newnode;
    }
}
void addatend(int n)
{
    struct Node *newnode,*t;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    t=start;
    if(start==NULL)
    {
        newnode->data=n;
        newnode->next=NULL;
        start=newnode;
    } 
    else
    {
        while(t->next != NULL)
        {
            t=t->next;
        }
        t->next=newnode;
        newnode->data=n;
        newnode->next=NULL;
    }
}
void delfrombeg()
{
    struct Node *t;
    if(start!=NULL)
    {
        t=start;
        start=start->next;
        free(t);
    }
    else
    {
        printf("Not Possible");
    }
}
void delfromend()
{
    struct Node *t;
    if(start!=NULL)
    {
        while(t->next->next!=NULL)
        {
            t=t->next;
        }
        free(t->next);
        t->next=NULL;
    }
    else
    {
        printf("Not Possible");
    }
}
void insatmid(int pos,int n)
{
    struct Node *newnode,*t;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    t=start;
    for(int i=0;i<pos-1;i++)
    {
        t=t->next;
    }
    newnode->next=t->next;
    newnode->data=n;
    t->next=newnode;
}
void delfrommid(int pos)
{
    struct Node *t,*p;
    if(start!=NULL)
    {
        for(int i=0;i<pos-1;i++)
        {
            t=t->next;
        }
        p=t->next;
        t->next=t->next->next;
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
    while(t!=NULL)
    {
        printf("%d",t->data);
        t=t->next;
    } 
    printf("\n");
}
void main()
{
    int choice,n,k,pos;
    while(1)
    {
        printf("1. ADD DATA AT BEGINNING\n");
        printf("2. ADD DATA AT END\n");
        printf("3. DELETE DATA DROM BEGINNING\n");
        printf("4. DELETE DATA FROM END\n");
        printf("5. ADD DATA AT MIDDLE\n");
        printf("6. DELETE DATA FROM MIDDLE\n");
        printf("7. DISPLAY DATA\n");
        printf("8. EXIT\n");
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

            case 5:printf("Enter the position to be inserted");
            scanf("%d",&pos);
            printf("Enter a number");
            scanf("%d",&n);
            insatmid(pos,n);
            break;

            case 6:printf("Enter the position to be deleted");
            scanf("%d",&pos);
            delfrommid(pos);
            break;

            case 7:display();
            break;

            case 8:exit(0);
            break;

            default:printf("Invalid Input");
        }
    }
}
