// Practical:2 Using pointer and arrays

/* 1.C program to traverse the array and find the respective element
 at the given position and add n to that number */
#include<stdio.h>

void add(int *arr,int n,int size,int ad){
    for(int i=0;i<size;i++){
        if(i==n){
            arr[i]+=ad;
        }
    }
}

void traverse(int *arr,int size){
for(int i=0;i<size;i++){
    printf("%d ",arr[i]);
}printf("\n");
}

int main(){
    int arr[]={2,3,34,53,1,23,44,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    int n,ad;
    printf("Enter the index of an element and Number to be added\n");
    scanf("%d%d",&n,&ad);
    traverse(arr,size);
    add(arr,n,size,ad);
    traverse(arr,size);

    return 0;
}

/*2.To print sum of min and max element from the given range of an array */
// Output: 
 
#include<stdio.h>

void traverse(int *arr,int size){
for(int i=0;i<size;i++){
    printf("%d ",arr[i]);
}printf("\n");
}

int maxi(int arr[],int lb,int ub){
    int max=0;
    for(int i=lb;i<=ub;i++){
        if(arr[i]>max){
            max=arr[i];
        }}
        return max;
}

int min(int arr[],int lb,int ub){
    int mini=arr[lb];
    for(int i=lb+1;i<=ub;i++){
        if(arr[i]<=mini){
        mini=arr[i];
        }
    }
    return mini;
}

int main(){
    int arr[]={2,3,44,5,332,55,4,77,8,58,9,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    int lb,ub;
    printf("Enter the lower and upper bound interms of index\n");
    scanf("%d%d",&lb,&ub);
    traverse(arr,size);
    int m=maxi(arr,lb,ub);
    int n=min(arr,lb,ub);
    printf("Sum of min and max is: %d\n",m+n);

    return 0;
}