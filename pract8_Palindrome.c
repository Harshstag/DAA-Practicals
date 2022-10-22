#include <stdio.h>
void maxCommonSub(char arr[], char arrRev[], int size) {
    int matSize= size+1;
    int orgVal[matSize][matSize], dpMat[matSize][matSize];
    for(int i=0;i<matSize;i++) {
        for(int j=0;j<matSize;j++) {
            orgVal[i][j]=0;
            dpMat[i][j]=0;
        }
    }
    for(int i=1;i<matSize;i++) {
        for(int j=1;j<matSize;j++) {
            if(arr[i-1]==arrRev[j-1]) {
                orgVal[i][j]= (orgVal[i-1][j-1])+ 1;
                dpMat[i][j]=3;
            } else {
                if(orgVal[i-1][j]>= orgVal[i][j-1]) {
                    orgVal[i][j]= orgVal[i-1][j];
                    dpMat[i][j]= 1;
                } else {
                    orgVal[i][j]=orgVal[i][j-1];
                    dpMat[i][j]= 2;
                }
            }
        }
    }

    printf("Numbers to be deleted from string to make it pandromic is: %d", size- (orgVal[size][size]));
    // cout<<"Numbers to be deleted from string to make it pandromic is: "<< size- (orgVal[size][size])<<endl;
}
int main() {
    int size;
    printf("Please enter the size of the string\n");
    scanf("%d", &size);

    printf("please enter the entire string with no spaces\n");
    char arr[size];
    scanf("%s",&arr);
    char arrRev[size];4
    int j=0;
    for(int i=size-1;i>=0;i--) {
        arrRev[j]= arr[i];
        j++;
    }
    
    maxCommonSub(arr, arrRev, size);
}