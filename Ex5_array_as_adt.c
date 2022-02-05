// Q.program to insert, delete and sort array 
#include<stdio.h>

void display(int arr[],int n){
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}
printf("\n");
}

int insert(int *arr ,int n,int ele,int pos){
    if(pos==n+1){
        arr[pos-1]=ele;
        n=n+1;
    }
    else{
        for(int i=n;i>=pos-1;i--){
            arr[i]=arr[i-1];
        }
        arr[pos-1]=ele;
        n=n+1;
    }
     display(arr,n); 
     return n;
}

int delete(int *arr,int n,int pos){
    if(pos<=n+1){
    for(int i=pos-1;i<n;i++){
        arr[i]=arr[i+1];
    }
    n=n-1;
    display(arr,n);
    return n;   
    }

return n;

}

void sort (int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j =i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    display(arr,n);
}

int main(){
    int arr[]={2,44,6,7,88,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int ele,pos,os;
    // to insert an element to an array
    printf("enter the element to insert in array \n");
    scanf("%d",&ele);
    printf("enter the position of element \n");
    scanf("%d",&pos);
    int p=insert(arr ,size,ele,pos);
    
    // to delete an element from an array
    printf("enter the position of element to delete from array \n");
    scanf("%d",&os);
    int q=delete(arr,p,os);

    // to sort an array
    printf("The sorted array is:\n");
    sort(arr,q);
    return 0;
}