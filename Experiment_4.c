// Practical:4 Using Recursion
// 1. Factorial of a number
#include<stdio.h>

int fact(int n){
    if(n==1 || n==0){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    int n=5;
    int a=fact(n);
    printf("Factorial of %d is: %d",n,a);
    return 0;
}

// 2.Fibonacci Serires 
// Output:

#include<stdio.h>

int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

int main(){
    //     1st,2nd,3rd 
    //0,1  ,1  ,2  ,3  ,5  ,8
    int n=3;
    int a=fibo(n);
    printf("%d Element of Fibonacci series is: %d",n,a);
    return 0;
}