#include <stdio.h>
#include <math.h>


#define SIZE 500
int arr[SIZE];
int num, count = 0, found = 0, low = 0, high = 500, mid;


int BinarySearch(){

    while (low<=high)
    {
        mid = (low + high)/2;

        if (num == arr[mid])
        {
            printf("\nThe element found at position : %dth Index \n\n",mid);
            found = 1;
            // count++;
            break;
        }  
        else if (num < arr[mid])
        {
            high = mid-1;
            count++;
        }
        else if (num > arr[mid])
        {
            low = mid+1;
            count++;
        }
    }
    if(! found) 
    {
        // if element does not found in arr 
        printf("\nElement not found \n\n");
    }
    return count;
}


unsigned int Log2n(unsigned int n)
{
    return (n > 1) ? 1 + Log2n(n / 2) : 0;
}


int main() 
{
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = i;
    }
    printf("\nEnter the number you want to search : ");
    scanf("%d",&num);


    int outputt, sum;
    for (int i = 0; i < 2; i++)
    {
        outputt = BinarySearch();
        outputt = outputt + outputt  ;
    }
    unsigned int n = SIZE;
    printf("\nlog2n =  %u", Log2n(n));
    getchar();

    return 0;
} 