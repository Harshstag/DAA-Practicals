// Asignment 3&4 Q3 - Quick sort 
#include <stdio.h>
#define max 5
int arr[max];


void display(int arr[], int end) 
{
    printf("\n  steps          :    ");
    for(int i=0;i<max;i++)
    {
        printf("\t%d", arr[i]);

    }
    printf(" \t Pivot : %d | Index : %d ",arr[end],end);
    printf("\n");
}


int partition(int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while ((arr[start] <= pivot) && (start < end))
        {
            start++;
        }
        while ((arr[end])>pivot)
        {
            end--;
        }
        if (start<end)
        {
            //swaping
            int temp;
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }   
    }
    arr[lb] = arr[end];
    arr[end] = pivot;

    display(arr, end);
    return end;
}


void quickSort(int lb, int ub)
{
    if (lb<ub)
    {
        int loc = partition(lb, ub);//location of pivot
        quickSort(lb, loc - 1); //left
        quickSort(loc + 1 , ub); // right
    }
    
}

int main()
{
    int i,j;
    printf("Enter Elements of Array : \n");
    for (i = 0; i < max; i++)
    {
        scanf("%d", &arr[i]);
    }
    

    printf("\nUnsorted Array   :\t");
    for (i = 0; i < max; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");

    quickSort(0, max - 1);

    printf("\nQuick Sort Array :\t");
    for (i = 0; i < max; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
