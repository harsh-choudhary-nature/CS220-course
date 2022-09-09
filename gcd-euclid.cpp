#include<stdio.h>
int recCount=0,iterCount=0;
void check(int* n1,int* n2){
    if(*n1<*n2){
        int temp=*n1;
        *n1=*n2;
        *n2=temp;
    }
}
int gcd(int a, int b){
    check(&a,&b);
    //a is greater now
    int n1=a,n2=b;
    int q=n1/n2;
    int r=n1%n2;
    while(r!=0){
        iterCount++;
        n1=n2;
        n2=r;
        r=n1%n2;
    }
    return n2;
}
int gcdRecursion(int num1,int num2){
    recCount++;
    if(num1%num2==0){
        return num2;
    }
    check(&num1,&num2);
    //num1 is greater now
    //gcd(a,b)=gcd(b,a%b)
    int gcd=gcdRecursion(num2,num1%num2);
    return gcd;
}
int main(){
    int gcdrec=gcdRecursion(78000454,14565464);
    int gcditer=gcd(78000454,14565464);
    printf("\nUsing recursion, gcd=%d and no. of steps is %d",gcdrec,recCount);
    printf("\nUsing iteration, gcd=%d and no. of steps is %d",gcditer,iterCount);
    return 0;
}