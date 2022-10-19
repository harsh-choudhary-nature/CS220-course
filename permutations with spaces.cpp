//Author: Harsh Choudhary
#include<iostream>
#include<stdio.h>
using namespace std;
int sum1(int n){
	if(n==0){		//base case
		return 0;
	}
	return (sum1(n/10)+n%10);		//recursive steps
}
int decToBin(int n){
	if(n==1){		//base case
		return 1;
	}
	int bin=decToBin(n/2)*10+n%2;		//recursive step
	return bin;
}


//permutation with spaces
void perm(int* ar,int* info,int beg,int size){
	if(beg==size){
		int i=0;
		while(i!=size){
			//printf("%d is count\n",count);
			if(info[i]==0){
				printf("%d",ar[i]);
				i++;
			}else{
				printf(" %d",ar[i]);
				i++;
			}
		}
		printf("\n");
		return;
	}
	if(beg==0){
		perm(ar,info,beg+1,size);
	}else{
		//without space
		perm(ar,info,beg+1,size);
		//with space
		info[beg]=1;
		perm(ar,info,beg+1,size);
	 	info[beg]=0;
	}
	return;
}
int main(){
	int n;
	cout<<"Question1:"<<sum1(12345)<<endl;
	cout<<"Question2:-"<<endl;
	cout<<"Enter the decimal number"<<endl;
	cin>>n;
	cout<<"Binary equivalent:"<<decToBin(n)<<endl;
	printf("Question3:-\n");
	int size;
	scanf("%d",&size);
	int* ar=(int*)malloc(size*sizeof(int));
	int* info=(int*)calloc(size,sizeof(int));
	for(int i=0;i<size;i++){
		printf("Enter the %dth element",i+1);
		scanf("%d",&ar[i]);
	}
	printf("The input array is:-");
	for(int i=0;i<size;i++){
		printf("%d",ar[i]);
	}
	printf("\n");
	perm(ar,info,0,size);
	return 0;
}

