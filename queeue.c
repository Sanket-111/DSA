// 2.Queue and its applications
#include <stdio.h>
#include <stdlib.h>
struct queue{
int rare,top,size;
int *arr;
};

int isempty(struct queue *a){
    if(a->top==-1){
        return 1;
    }
   return 0; 
}

int isfull(struct queue *a){
    if(a->rare==(a->size-1)){
        return 1;
    }
    return 0;
}

  // To push the data into the queue.
void enqueue(int n,struct queue *s){
    if(!isfull(s)){
        if(s->top==-1 && s->rare==-1){
           s->top=0;
           s->rare=0; 
           s->arr[s->rare]=n;
           printf("The element %d is Enqueued\n",s->arr[s->rare]);

        }
        else{
            s->rare++;
            s->arr[s->rare]=n;
            printf("The element %d is Enqueued\n",s->arr[s->rare]);
        }
    }
    else{
        printf("Queue is Full\n");
    }
}
  // To pop the data into the queue.
void dequeue(struct queue *s){
    if(s->top!=s->size){
       
        int n=s->arr[s->top];
        s->top++;
        printf("The element %d is dequeued\n",n);
        
    }
    else{
        printf("Queue is empty\n");
    }
}
// To display the data from queue.
void display(struct queue *s){
    if(isempty(s)){
        printf("Queue is empty\n");
    }
    else{
    for(int i=s->top;i!=s->rare;i++){
        printf("%d ",s->arr[i]);
    }
    printf("%d \n",s->arr[s->rare]);
    }
}

int main(){
    struct queue *a=(struct queue*)malloc(sizeof(struct queue));
    a->arr=(int *)malloc(sizeof(int));
    a->top=-1;
    a->rare=-1;
    a->size=5;
    // To push the data into the queue.
    enqueue(23,a);
    enqueue(3,a);
    enqueue(12,a);
    enqueue(87,a);
    printf("\nDisplaying The queue: \n");
    display(a);
    printf("\n");
    // T0 pop the element in an queue
    dequeue(a);
    dequeue(a);
    // To Display elements of an queue
    printf("\nDisplaying The queue: \n");
    display(a);
    printf("\n");
    return 0;
}