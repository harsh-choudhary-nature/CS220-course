/*
Original Author: Harsh Choudhary
Date: 18-8-2022
*/
#include<iostream>
using namespace std;
class HarshCalculator{
    int num1;
    char oper;
    int num2;
    public:
        HarshCalculator(){
            num1=num2=0;
            int sign=1;
            printf("Enter number 1:");
            char c=getchar();
            if(c=='-'){
                sign=-1;
                c=getchar();
            }
            if(c=='\n'){
                printf("\nnum1 can't be empty!");
                return;
            }
            while(c!='\n'){
                if(((c-'0')>9)||((c-'0')<0)){
                    printf("\nEnter valid number");
                    return;
                }
                num1=num1*10+(c-'0');
                c=getchar();
            }
            num1=sign*num1;
            sign=1;
            //printf("\n%d",num1);
            printf("\nEnter the character:");
            char oper=getchar();
            char check=getchar();
           // printf("%c",check);
            if(check!='\n'){
                printf("\nEnter valid operator");
                return;
            }
            printf("\nEnter number 2:");
            c=getchar();
            if(c=='-'){
                sign=-1;
                c=getchar();
            }
            if(c=='\n'){
                printf("\nnum2 can't be empty!");
                return;
            }
            while(c!='\n'){
                if(((c-'0')>9)||((c-'0')<0)){
                    printf("\nEnter valid number");
                    return;
                }
                num2=num2*10+(c-'0');
                c=getchar();
            }
            num2=sign*num2;
            //printf("\n%d",num2);
            displayResult(num1,oper,num2);
        }
        void displayResult(int a, char op, int b){
            if(op=='+'){
                printf("\nAnswer=%d",a+b);
            }else if(op=='-'){
                printf("\nAnswer=%d",a-b);
            }else if(op=='*'){
                printf("\nAnswer=%d",a*b);
            }else if(op=='/'){
                if(b==0){
                    cout<<"Cant divide by 0"<<endl;
                }else{
                    printf("\nAnswer=%d",a/b);
                }
            }else{
                printf("\nEnter valid operator!");
            }
            printf("\nBye!"); 
        }
} ;
int main(){
    HarshCalculator hcalc;
    return 0;
}
