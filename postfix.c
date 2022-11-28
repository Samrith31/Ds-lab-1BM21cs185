#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct stack{

     int size;
     int top;
     char *arr;

};


int isempty(struct stack *ptr){

  if(ptr->top==-1){
       return 1;
  }
  else{
    return 0;
  }


}

int isfull(struct stack *ptr){


   if(ptr->top==ptr->size-1){
        return 1;
   }
   else{
    return 0;
   }




}
// pushing
void push(struct stack *ptr,int val){

    if(isfull(ptr)){
        printf("Stack Overflow\n");  
        
    }
     
     else{
     ptr->top++;

     ptr->arr[ptr->top]=val;
     }


}
// popping

int pop(struct stack *ptr){

    if(isempty(ptr)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
            
      int val=ptr->arr[ptr->top];
       ptr->top--;
       return val;

    }



}

int peek(struct stack *ptr,int i){

    int arrind=ptr->top - i +1;
    if(arrind<0){
        printf("NOt  a valid position for stack\n");
        return -1;
    }
    else{
        return ptr->arr[arrind];
    }


}

int stacktop(struct stack *ptr){
     return ptr->arr[ptr->top];
}
int stackbot(struct stack *ptr){
    return ptr->arr[0];
}


 int isoperator(char ch){
    if(ch=='+'|| ch=='-'||ch=='*'||ch=='/'){
        return 1;

    }
    else{
        return 0;
    }
 }

int  precedence(char ch){
    if(ch=='/'||ch=='*'){
        return 3;
    }
    if(ch=='+'||ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}





char *infixtopostfix(char*infix){


       struct stack *s=(struct stack*)malloc(sizeof(struct stack));
       s->size=10;
       s->top=-1;
       s->arr = (char *)malloc(s->size *sizeof(char));
         char*postfix =(char*)malloc(strlen(infix)+1*sizeof(char));
        int i=0;
        int j=0;
        while(infix[i]!='\0'){
            if(!isoperator(infix[i])){
                  postfix[j]=infix[i];
                 i++;
                 j++;
            }
            else{

                if(precedence(infix[i]) > precedence(stacktop(s))){
                    push(s,infix[i]);
                    i++;
                }
                else{
                    postfix[j]=pop(s);
                    j++;
                }

            }
        }
        while(!isempty(s)){
           postfix[j]=pop(s);
           j++;
        }
        postfix[j]='\0';
        return postfix;

        }










int main(){






char *infix="p-q-r/a";

printf("The postfix is %s\n",infixtopostfix(infix));




}