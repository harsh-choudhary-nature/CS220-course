#include<stdio.h>
int power(int a,int b){
	int pow=1;
	for(int i=0;i<b;i++){
		pow*=a;
	}
	return pow;
}
int calcSum(int n){
	int sum=0;
	int totalSum=0;
	while(n>0){
		sum=sum+power(10,n-1);
		totalSum+=sum;
		n--;
	}
	return totalSum;
}
int main(){
	//printf("%d",power(10,1));
	printf("%d",calcSum(5));
	return 0;
}

