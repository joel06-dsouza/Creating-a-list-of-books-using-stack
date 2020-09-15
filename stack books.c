#include<stdlib.h>
#include<stdio.h>
#define size 50

struct book 
{
   char name[50];
   int pages;
   float price;
};

typedef struct book book;

book stack[size];
int top = -1;

book getbookdetails();
void push(book b);
book * pop();
void peep();
void display();
void show(book b);

int main()
{	
	int choice;
	book * bp;
	book b;
	
   while(1)
   {
  	  printf("\n1. Push  2. Pop  3. Peep  4. Display  5. Exit\n Enter your  choice:");
  	  scanf("%d",&choice);
      switch(choice)
  	  {
 	     case 1: 
			 	 printf("\nEnter the details of the book...");
			 	 b=getbookdetails(); 
			 	 push(b);
			 	 break;
 	 	 case 2: 
		         bp=pop();	
				 if(bp!=NULL)
				 {   	  
		              printf("\nBook removed is");
				      show(*bp);
			     }       
 	 	 	     break;
 	 	 case 3: peep(); 
				 break;
 	 	 case 4: display(); 
				 break;
	 	 case 5: exit(0);
	 
	 	 default: printf("\n\nEnter valid choice!!\n");
		
     }
   }
}

book getbookdetails()
{
   book b;
   gets(b.name);
   printf("\nEnter the title of the book:");
   gets(b.name);
   printf("\nEnter the number of pages in the book:");
   scanf("%d",&b.pages);
   printf("\nEnter the price of the book:");
   scanf("%f",&b.price);
   return b;   
}


void push(book b)
{
	if(top == size-1)
 	 	 printf("\nStack Full!!\n");
	else
	{
	    top++;
		stack[top]=b;
	}
}


void show(book b)
{
   printf("\nBook name = %s,pages = %d,price = %f",b.name,b.pages,b.price);
}


book * pop()
{
	if(top==-1)
	{
		printf("\nStack Empty!!\n");
		return NULL;
	}
	else
	{
	    top--;
		return (&stack[top+1]);
	}
	return; 
}


void peep()
{
	if(top == -1)
		printf("\nStack Empty!!\n");
	else
	{
		printf("\nBook at top is");	   
	}
}


void display()
{	
    int i;
	if(top == -1)
		printf("\nStack Empty!!\n");
	else
	 {	 
	    printf("\nBooks entered are....\n");
	  	  for(i=top;i>=0;i--)
				printf("\nBook at %d",stack[i]);
	 }
}




