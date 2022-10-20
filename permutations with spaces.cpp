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
		//with space
        info[beg]=1;
		perm(ar,info,beg+1,size);
		//without space
		info[beg]=0;
		perm(ar,info,beg+1,size);
	}
	return;
}
void subsets(int* ar,int* info, int size,int beg){
    if(beg==size){
        for(int i=0;i<size;i++){
            if(info[i]==1){
                printf("%d",ar[i]);
            }
        }
        printf("\n");
        return;
    }
    // printf("Inside subsets()\n");
    //exclude first element
    info[beg]=0;
    subsets(ar,info,size,beg+1);
    //include first element
    info[beg]=1;
    subsets(ar,info,size,beg+1);
    return;
}
int count0(int* info,int size){
    int count=0;
    for(int i=0;i<size;i++){
        if(info[i]==0){
            count++;
        }
    }
    return count;
}
void k_subsets(int* ar,int* info,int size,int beg,int k,int c){
    if(beg==size){    
        if(c==k){
            for(int i=0;i<size;i++){
                if(info[i]==0){
                    cout<<ar[i];
                }
            }
            cout<<endl;
        }
        return;
    }
    if(c==k){
        for(int i=0;i<size;i++){
            if(info[i]==0){
                cout<<ar[i];
            }
        }
        cout<<endl;
        return;
    }
    //exclude first element
    info[beg]=1;
    k_subsets(ar,info,size,beg+1,k,c);
    //include first element
    info[beg]=0;
    //when c==k then we already have reached the length of k element subarray
    k_subsets(ar,info,size,beg+1,k,c+1);
    info[beg]=1;        //needed or else change the order to first include then exclude
}
bool binarySearch(int* ar,int beg,int end,int key){
    if(end<=beg){
        if(ar[end]==key){
            return true;
        }
        return false;
    }
    int mid=(beg+end)/2;
    if(ar[mid]==key){
        return true;
    }
    if(ar[mid]<key){
        return binarySearch(ar,mid+1,end,key);
    }
    if(ar[mid]>key){
        return binarySearch(ar,beg,mid,key);
    }
}
void printBinary(int* ar,int nbits,int beg){
    if(beg==nbits){
        int l1=0;
        int r1=0;
        for(int i=0;i<nbits/2;i++){
            if(ar[i]==1){
                l1+=1;
            }
            if(ar[nbits-i-1]==1){
                r1+=1;
            }
        }
        if(l1==r1){
            for(int i=0;i<nbits;i++){
                cout<<ar[i];
            }
            cout<<endl;
        }
        return;
    }
    //cout<<"printBinary()"<<endl;
    ar[beg]=1;
    printBinary(ar,nbits,beg+1);
    ar[beg]=0;
    printBinary(ar,nbits,beg+1);
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
    cout<<"Question 4"<<endl;
    //info array is back to original state as due to recursive method of previous function call itself
    for(int i=0;i<size;i++){
        printf("%d",info[i]);
    }
    subsets(ar,info,size,0);
    cout<<"Question 5"<<endl;
    int k;
    cout<<"Enter the value of k:";
    cin>>k;
    k_subsets(ar,info,size,0,k,0);
    cout<<"Question 6"<<endl;
    int key;
    cout<<"Enter the value of key:";
    cin>>key;
    cout<<binarySearch(ar,0,size,key);
	cout<<endl<<"Question 7:-"<<endl;
    int nbits;
    cout<<"Enter the number of digits in binary number:";
    cin>>nbits;
    int* bin=(int*)calloc(nbits,sizeof(int));
    // printf("%d",bin[0]);
    printBinary(bin,nbits,0);
    return 0;
}
