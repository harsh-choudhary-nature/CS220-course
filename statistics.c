#include<stdio.h>
float sqrt(float a){
    if(a>1){
        float sqrt=1;
        float step=0.01;
        while(((sqrt*sqrt)-a)>(0.0001)||((sqrt*sqrt)-a)>(-0.0001)){
            sqrt=sqrt+step;
        }
        return sqrt;
    }
    if(a<1){
        float sqrt=1;
        float step=0.01;
        while(((sqrt*sqrt)-a)>(0.0001)||((sqrt*sqrt)-a)>(-0.0001)){
            sqrt=sqrt-step;
            //printf("%f\n",sqrt);
        }
        return sqrt;
    }
}
float calcmean(int arr[],int size){
    int sum=0;
    float mean;
    for(int i=0;i<size;i++){
        sum=sum+arr[i];
    }
    mean=((float)sum)/size;
    return mean;
}
float calcVariance(int arr[],int size,float mean){
    float sum=0;
    float variance;
    for(int i=0;i<size;i++){
        sum=sum+((arr[i]-mean)*(arr[i]-mean));
    }
    variance=sum/size;
    return variance;
}
int main(){
    const int size=2;
    int ar[]={1,2};
    float mean=calcmean(ar,size);
    printf("%0.2f\n",mean);
    float variance=calcVariance(ar,size,mean);
    printf("%0.2f\n",variance);
    float sd=sqrt(variance);
    printf("%0.2f\n",sd);
    return 0;
}