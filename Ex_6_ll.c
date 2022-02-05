//Q. implementation of linked list and its application
#include<stdio.h>
#include<stdlib.h>

// implementation of a linked list
struct node{
    int data;
    struct node *next;
};

// printing data from linked list
void display(struct node *ptr){

while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
}
printf("\n");
}

// deletion in a linked list 
struct node* deletion(struct node *ptr,int pos){
    int i=1;
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    head=ptr;

  if(pos==1){
      ptr=head->next;
      free(head);
      return ptr;
  }
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    q=ptr->next;
    while(i!=pos-1){
        ptr=ptr->next;
        q=q->next;
        i++;
    }
    ptr->next=q->next;
    free(q);
    return head;
}
 
// insertion in a linked list
struct node* insertion(struct node *ptr,int pos,int data){
    
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    head=ptr;
  
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
if(pos==1){  
    p->next=ptr;
    return p;
}
else{
    int i=1;
    while(i!=pos-1){
        ptr=ptr->next;
        i++;
    }
    p->next=ptr->next;
    ptr->next=p;
return head;
}
} 

// sorting in a linked list
// 22-> 33-> 44-> 2->null
// sorting in a linked list is done by a bubble sort techinque

// main function
int main(){
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;
    first=(struct node*)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    fifth=(struct node *)malloc(sizeof(struct node));

    first->data=37;
    first->next=second;
    second->data=7;
    second->next=third;
    third->data=17;
    third->next=fourth;
    fourth->data=23;
    fourth->next=fifth;
    fifth->data=1;
    fifth->next=NULL;

// display a linked list
printf("\nThe LL is Displayed: \n");
display(first);
printf("\nLL after deleting the element at 2nd position:\n");
first=deletion(first,2);
display(first);
printf("\nLL after inserting 35 at 3rd position:\n");
first=insertion(first,3,35);
display(first);


    return 0;
}

// Various operations performed are :
// 1.Displaying the data of linked list.
// 2.Insertion in linked list .
// 3.Deletion in linked list .