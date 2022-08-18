#include<iostream>
using namespace std;
int gcd(int num1,int num2){
    int gcd=1;
    for(int i=1;(i<=num1)&&(i<=num2);i++){
        if((num1%i==0)&&(num2%i==0)){
            gcd=i;
        }
    }
    return gcd;
}
int main(){
    unsigned int a,b;
    cout<<"Enter space seperated two integers";
    cin>>a>>b;
    printf("The GCD of %d and %d is %d",a,b,gcd(a,b));
    cout<<endl;
    return 0;
}