// 1.Stack and its Applications.
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int *arr;
    int top;
    int size;
};

// check the initiation status of stack 
void isEmpty(struct stack *s){
    if(s->top==-1){
    printf("Stack is a Empty\n");
    }
    else{
        if(s->top==(s->size-1)){
            printf("Stack is Full\n");
        }
        else{
            printf("Stack is Initiated\n");
        }
    }
}
// to push inside the stack
void push(int d,struct stack *s){
    if(s->top==(s->size-1)){
        printf("Stack Overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=d;
        printf("The element %d is Pushed inside stack\n",(s->arr[s->top]));
    }
}
// to pop in a stack
void pop(struct stack *s){
    if(s->top==-1){
        printf("Stack is Underflow\n");
    }
    else {
        printf("The element %d is Popped from the stack\n",(s->arr[s->top]));
        s->top--;
    }
}

// main function
int main(){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=8;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    // to check the stack is empty or full
    isEmpty(s);
    // push an element in an stack
    push(23,s);
    push(89,s);
    // pop an element inside a stack
    pop(s);
    pop(s);
    
    return 0;
}
