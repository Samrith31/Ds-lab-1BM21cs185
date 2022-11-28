#include<stdio.h>
#include<stdlib.h>
#define Maximum 10
int queue_arr[Maximum];
int rear=-1;
int front=-1;

void insert(){

int val;
if (rear==Maximum-1){
    printf("Queue Overflow\n");
}
else{
    if(front==-1){
        front=0;
    }
        printf("Enter the value to be inserted\n");
        scanf("%d",&val);
        rear++;
        queue_arr[rear]=val;
    }
}




void delete(){

  if(front==-1||front>rear){
    printf("Queue Underflow\n");

  }
  else{
     printf("The element %d is deleted from the queue\n",queue_arr[front]);
     front++;
  }


}


void display(){
   int i;
 if(front==-1){
    printf("NO Elements in the queue\n"); }



else{

  for(i=front;i<=rear;i++){
    printf("The element at the position %d is %d\n",i+1,queue_arr[i]);
  }
}
}

int main(){
int choice;

 while(1){
        printf("");
printf(" 1: Insert element into queue\n");
printf("2.Delete element into queue\n");
printf("3.Display queue\n");
printf("4.Quit\n");
printf("Enter the choice\n");
scanf("%d",&choice);


    switch(choice){


    case 1: insert();
            break;

    case 2: delete();
            break;
    case 3: display();
            break;

    case 4: exit(1);

    default:printf("Wrong choice\n");


    }

 }
return 0;
}




