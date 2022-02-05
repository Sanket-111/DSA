// Practical:1 Structure and pointer
// // Q1.Display book information using Structure and Pointer.

#include<stdio.h>
/*Inputs
My_Journey
Dr.A.P.J.Abdul_Kalam
200
450
*/
struct book{
    int No_pages;
    char name[20];
    char author_name[20];
    float price;
};


void display(struct book *b){
	printf("***** The book Information *****\n");
	printf("__________________________________");
	printf("\nName   	    : %s",b->name);
	printf("\nAuthor Name : %s",b->author_name);
	printf("\nPrice       : %2.f",b->price);
	printf("\nNo of Pages : %d",b->No_pages);
	printf("\n__________________________________");
}

int main(){
    struct book *b1;

    scanf("%s",&b1->name);
    scanf("%s",&b1->author_name);
    scanf("%f",&b1->price);
    scanf("%d",&b1->No_pages);

    display(b1);
}

//Q2.Display Student information.

#include<stdio.h>
/* 2020BTECS00005
Sanket_Jadhav
27_Aug_2002
Second_Year_BTECH
3rd_sem
9.2*/

struct student{
    char id[20];
    char name[20];
    char birthdate[20];
    char cls[20];
    char semester[20];
    float cgpa;
};


void display(struct student *b){
	printf("***** About Student *****\n");
	printf("__________________________________");
	printf("\nStudent ID  : %s",b->id);
	printf("\nName   	    : %s",b->name);
	printf("\nBirth_date  : %s",b->birthdate);
	printf("\nClass       : %s",b->cls);
	printf("\nSemester    : %s",b->semester);
	printf("\nCGPA        : %0.2f",b->cgpa);
	printf("\n__________________________________");
}

int main(){

    struct student *b1;
    scanf("%s",&b1->id);
    scanf("%s",&b1->name);
    scanf("%s",&b1->birthdate);
    scanf("%s",&b1->cls);
    scanf("%s",&b1->semester);
    scanf("%f",&b1->cgpa);
    display(b1);
}