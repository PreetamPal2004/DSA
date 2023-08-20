#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int queue[10];
int front=-1,rear=-1;
void insert(int);
int delete_element();
void display();

void main()
 {
   int num,choice,s,k;
   while(1)
     {
	  printf("**Menu**\n");
	  printf("\n\t\t\t\t1. Insert Element\n");
	  printf("\n\t\t\t\t2. Delete Element\n");
	  printf("\n\t\t\t\t3. Display\n");
	  printf("\n\t\t\t\t4. Exit\n");
	  printf("Enter your choice");
	  scanf("%d",&choice);
	  switch(choice)
	   {
	     case 1:printf("Enter  number");
		    scanf("%d",&num);
		    insert(num);
		    break;
	     case 2:k=delete_element();
		    printf("Value %d is deleted from queue",k);
		    break;
	     case 3:display();
		    break;
	     case 4:exit(0);
	     default:printf("Wrong choice");
	   }

    getch();
   }
 }
   void insert(int n)
    {
      if(rear==9)
      {
      printf("Queue overflow");
      }
     else if(front==-1&&rear==-1)
     {
     front=rear=0;
     }
      else
      {
      rear++;
      }
      queue[rear]=n;
    }

   int delete_element()
    {
      int v;
      if(front==-1 ||front>rear)
       {
	 printf("Queue is empty");
       }
       else
	{
	  v=queue[front];
	  front++;
	  if(front>rear)
	    front=rear=-1;
	  return(v);
	}
     }
  void display()
   {
    int i;
    if(front==-1 ||front>rear)
    printf("Queue is empty");
    for(i=front;i<=rear;i++)
     {
       printf("%d ",queue[i]);
     }
  }
