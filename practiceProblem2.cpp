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
            cout<<"Enter number 1:";
            cin>>num1;
            cout<<"Enter the operation:";
            cin>>oper;
            cout<<"Enter number 2:";
            cin>>num2;
            if(!cin) {      //!cin checks if no input is accepted by cin then cin equals zer0 so not cin equals 1;
                cout << "Invalid input\n";
            }else{
                displayResult(num1,oper,num2);
            }
            
        }
        void displayResult(int a, char op, int b){
            if(op=='+'){
                cout<<"Answer="<<float(a+b)<<endl;
            }else if(op=='-'){
                cout<<"Answer="<<float(a-b)<<endl;
            }else if(op=='*'){
                cout<<"Answer="<<float(a*b)<<endl;
            }else if(op=='/'){
                if(b==0){
                    cout<<"Cant divide by 0"<<endl;
                }else{
                    cout<<"Answer="<<float(a)/float(b)<<endl;
                }
            }else{
                cout<<"Enter valid operator\n";
            }
            cout<<"Bye"<<endl; 
        }
} ;
int main(){
    HarshCalculator hcalc;
    return 0;
}