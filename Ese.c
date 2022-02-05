// Practical:26 Program based on Structures and pointers.

#include<stdio.h>

struct book{
    int No_pages;
    char name[20];
    char author_name[20];
    float price;
    float purchase;
};


void display(struct book *b){
	printf("\n***** The book Information *****\n");
	printf("__________________________________");
	printf("\nName   	    : %s",b->name);
	printf("\nAuthor Name : %s",b->author_name);
	printf("\nPrice       : %2.f",b->price);
	printf("\nNo of Pages : %d",b->No_pages);
    printf("\nThe No.of Purchase of books : %2.f",b->purchase);
	printf("\n__________________________________\n");
}

int main(){
    struct book *b1,*b2;

    scanf("%s",&b1->name);
    scanf("%s",&b1->author_name);
    scanf("%f",&b1->price);
    scanf("%d",&b1->No_pages);
    scanf("%f",&b1->purchase);
    
    display(b1);

    scanf("%s",&b2->name);
    scanf("%s",&b2->author_name);
    scanf("%f",&b2->price);
    scanf("%d",&b2->No_pages);
    scanf("%f",&b2->purchase);

    display(b2);
}

