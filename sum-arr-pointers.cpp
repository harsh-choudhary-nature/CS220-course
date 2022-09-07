#include<stdio.h>
int sum_arr(int A[],int size){
	int* ptr=A;
	int sum=0;
	for(int i=0;i<size;i++){
		sum=sum+ptr[i];
	}
	return sum;
}

int main(){
	const int size1=5;
	int arr[size1]={10,20,15,-3,9};
	printf("\n%d",sum_arr(arr,size));
	return 0;
}
