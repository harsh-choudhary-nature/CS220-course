void rev_arr(int arr[],int size){
    int* ptr=arr;
    for(int i=0;i<size/2;i++){
        int temp=ptr[i];
        ptr[i]=ptr[size-i-1];
        ptr[size-i-1]=temp;
    }
}