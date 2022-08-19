#include<stdio.h>
int factorial(int n){
    int x=0;
    if(n==0){       //base case
        return 1;
    }
    x=factorial(n-1);       //recursive step
    return (n*x);
}
int main(){
    int num=4;
    printf("%d!=%d",num,factorial(num));
}