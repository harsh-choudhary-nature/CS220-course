#include<stdio.h>
#include<stdlib.h>
//function to find middle element of an array
int* midEle(int ar[],int size){
	int beg=0,end=size-1;
	while(beg<=end){
		if(beg==end){
			int* middle=(int*)malloc(1*sizeof(int));
			middle[0]=ar[beg];
			return middle;
		}
		if(end-beg==1){
			int* middle=(int*)malloc(2*sizeof(int));
			middle[0]=ar[beg];
			middle[1]=ar[end];
			return middle;
		}
		beg++;end--;
	}
	return NULL;	//array of size 0
}
int main(){
	const int size=7;
	int arr[7]={1,3,4,5,6,7,8};
	int* ptr=midEle(arr,size);
	if(ptr==NULL){
		printf("Array was empty\n");
	}
	if(size%2==0){
		printf("%d\n%d\n",ptr[0],ptr[1]);
	}else{
		printf("%d\n",ptr[0]);		
	}
	return 0;
}

