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

struct node*insertatfirst(struct node*head){
  int val;
  struct node*ptr=(struct node*)malloc(sizeof(struct node));
  printf("Enter the value to be Added first\n");
  scanf("%d",&val);
  ptr->data=val;
  ptr->next=head;
  head=ptr;
  return head;

}

struct node*insertatanypos(struct node*head){
  int val;
  int i;
  struct node*ptr=(struct node*)malloc(sizeof(struct node));
  struct node *p=head;
  printf("Enter the position at which the value to be inserted\n");
  scanf("%d",&i);
   int s=0;


  printf("Enter the value to be Added\n");
  scanf("%d",&val);

  while(s!=(i-1)){
    p=p->next;
    s++;

  }
  ptr->data=val;
   ptr->next=p->next;
   p->next=ptr;

  return head;

}


struct node*insertatlast(struct node*head){
  int val;
  struct node *ptr=(struct node*)malloc(sizeof(struct node));
  struct node *p=head;
  printf("Enter the value to be Added last\n");
  scanf("%d",&val);

  while(p->next!=NULL){
    p=p->next;
  }
  ptr->data=val;
   ptr->next=NULL;
  p->next=ptr;

  return head;

}





int main(){


     struct node *head;
     struct node *two;
     struct node *three;
     int choice;

      head=(struct node*)malloc(sizeof(struct node));
      two=(struct node*)malloc(sizeof(struct node));

      three=(struct node*)malloc(sizeof(struct node));

      head->data=12;
      head->next=two;

      two->data=20;
      two->next=three;

      three->data=30;
      three->next=NULL;





        do
    {
        printf("\nEnter the choice for the options in the queue.\n1. Insert at First\n2. Insert at any position\n 3.Insert at last\n4. Display option\n5. Exit the process\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insertatfirst(head);
                    break;
            case 2: head=insertatanypos(head);
                    break;
            case 3: head=insertatlast(head);
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










