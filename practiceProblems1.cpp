#include<iostream>

using namespace std;
int armstrong(int num){
    /*
    Function to find if the number is armstrong or not
    Parameter: num
    Default value: None
    */
   int temp=num,sum=0;
   while(temp!=0){
       sum+=(temp%10)*(temp%10)*(temp%10);
       temp=temp/10;
   }
   if(sum==num){
       return 1;
   }else{
       return 0;
   }
   return 0;
}
int lcm(int num1,int num2){
    /*
    Function to find LCM of two numbers
    Parameter: num1,num2
    Default value: None
    */
    if((num1==0)||(num2==0)){
        return 0;
    }
    int maxi,mini;
    if(num1==num2){
        return num1;
    }else if(num1>num2){
        maxi=num1;
        mini=num2;
    }else{
        maxi=num2;
        mini=num1;
    }
    while(true){
        if((maxi%num1==0)&&(maxi%num2==0)){
            return maxi;
        }
        maxi++;
    }
}
int reverse(int num){
   /*
    Function to find the reverse of the number
    Parameter: num
    Default value: None
    */
    int rev=0;
    while(num!=0){
        rev=(rev*10)+(num%10);  //main line of this function
        //rev*10 creates a space to accomodate the new coming number at one's place by shifting all the currently existing digits at their immediate tens
        num=num/10;
    }
    return rev;
}
int main(){
    //for q-1
    cout<<armstrong(153)<<endl;
    //for q-2
    cout<<lcm(2000,200001)<<endl;
    //for q-3
    cout<<reverse(1234);
    return 0;
}