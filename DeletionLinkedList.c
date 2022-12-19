#include<stdio.h>
#include<stdlib.h>


struct node{

  int data;
  struct node *next;

};

void traversal(struct node*head){

 struct node *ptr=head;
  while(ptr!=NULL){
       printf("The value is : %d\n",ptr->data);
       ptr=ptr->next;
  }





}

struct node*deleteatfirst(struct node*head){
 struct node *p;
  p=head;
  head=p->next;

   free(p);
   printf("Deletion done");

  return head;

}


struct node*deleteatanypos(struct node*head){

  int i;

  struct node *p=head;
  struct node*q=head->next;
  printf("Enter the position at which the node to be deleted \n");
  scanf("%d",&i);
   int s=0;



  while(s!=(i-1)){
    p=p->next;
    q=q->next;
    s++;

  }

   p->next=q->next;
   free(q);

  return head;

}


struct node*deleteatlast(struct node*head){


  struct node *p=head;
  struct node *q=head->next;


  while(q->next!=NULL){
    p=p->next;
    q=q->next;
  }

   p->next=NULL;
   free(q);
  printf("Deletion sucessful at the end");
  return head;

}








int main(){


     struct node *head;
     struct node *two;
     struct node *three;
      struct node *four;
     int choice;

      head=(struct node*)malloc(sizeof(struct node));
      two=(struct node*)malloc(sizeof(struct node));

      three=(struct node*)malloc(sizeof(struct node));
         four=(struct node*)malloc(sizeof(struct node));

      head->data=12;
      head->next=two;

      two->data=20;
      two->next=three;

      three->data=30;
      three->next=four;


      four->data=40;
      four->next=NULL;




        do
    {
        printf("\nEnter the choice for the options in the queue.\n1. Delete at First\n2. Delete at any position\n 3.Delete at last\n4. Display option\n5. Exit the process\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=deleteatfirst(head);
                    break;
            case 2: head=deleteatanypos(head);
                    break;
            case 3: head=deleteatlast(head);
                    break;
            case 4: traversal(head);
            case 5: printf("\nExiting the program!");
                    exit(0);
                    break;
            default: printf("Invalid Choice!");
                     break;
        }
    } while (1);

}



