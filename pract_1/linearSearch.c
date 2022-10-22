#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int count = 0;


int BinarySearchRecu(int arr[], int low, int high, int key){
    
    if (low > high)
    {
        return 1;
    }
    
    int mid = (low + high)/2;

    if (arr[mid]== key)
    {
        // printf("Element Found");
        return count;
    }
    else if (key > arr[mid])
    {
        low = mid + 1;
        count++;
        BinarySearchRecu(arr, low, high, key);

    }
    else{
        high = mid -1;
        count++;
        BinarySearchRecu(arr, low, high, key);
    }
    
}
unsigned int Log2n(unsigned int n)
{
    return (n > 1) ? 1 + Log2n(n / 2) : 0;
}


int main(){

    int size = 500, output = 0, avg, key, sum=0;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < 50; i++)
    {
        count = 0;
        output = 0;
        key = rand() % 100 ;
        output = BinarySearchRecu(arr, 0, size, key);
        sum = sum + output;
    }


    avg = sum / 50;
    printf("\nAvgrage is : %d", avg);

    unsigned int n = size;
    printf("\nlog2n =  %u", Log2n(n));
    getchar();


    return 0;

}