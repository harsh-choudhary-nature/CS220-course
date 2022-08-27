#include<stdio.h>
int nfavorable=0;
int ntotal=0;
int shouldSwap(char st[],int beg,int i){
    for(int t=beg;t<i;t++){
        if(st[t]==st[i]){
            return 0;
        }
    }
    return 1;
}
void swap(char st[],int beg,int i){
    char temp=st[beg];
    st[beg]=st[i];
    st[i]=temp;
    return;
}
void favourable_perm(char st[],int beg,int size){
    if(beg==size){
        ntotal++;
        for(int i=0;i<size;i++){
            printf("%c",st[i]);
        }
        printf("\n");
        int acount=0,bcount=0;
        for(int i=0;i<size;i++){
            if(st[i]=='A'){
                acount+=1;
            }else{
                bcount+=1;
            }
            if(acount<=bcount){
                return;
            }
        }
        nfavorable+=1;
        return;
    }
    for(int i=beg;i<size;i++){
        if(shouldSwap(st,beg,i)==1){
            swap(st,beg,i);
            favourable_perm(st,beg+1,size);
            swap(st,beg,i);
        }
    }
    return;
}
int main(){
    int n,m;
    printf("Enter the number of votes for A:");
    scanf("%d",&n);
    printf("Enter the number of votes for B:");
    scanf("%d",&m);
    int length=n+m;
    char ballot[length];
    for(int i=0;i<n;i++){
        ballot[i]='A';
    }
    for(int i=n;i<length;i++){
        ballot[i]='B';
    }
    for(int i=0;i<length;i++){
        printf("%c",ballot[i]);
    }
    printf("\n");
    favourable_perm(ballot,0,length);
    float probability=float(nfavorable)/ntotal;
    printf("\nNumber of favorable events are %d",nfavorable);
    printf("\nProbability that A always leads B in ballot counting is %0.2f",probability);
    return 0;
}