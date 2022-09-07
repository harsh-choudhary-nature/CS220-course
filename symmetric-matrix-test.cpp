#include<stdio.h>
#define size 3
int checkSymmetric(int arr[size][size]){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(arr[i][j]!=arr[j][i]){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    int matrix1[size][size]={{1,2,3},
                            {2,3,4},
                            {4,5,6}};
    int result=checkSymmetric(matrix1);
    printf("%d",result);
    return 0;
}