#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int n;
int x[];
int feasible(int k,  int j){
    // int i;
    for (int i = 1; i <= k-1; i++)
    {
        if ( (x[i] == j) || (abs(j-x[i]) == abs(k-i)) )
        {
            return false;
        }
    }
    return true;
}


void recur_nqueens(int k, int n){


    for(x[k] = 1; x[k] <= n; x[k]++)
    {
        if (feasible(k , x[k]))
        {
            if (k == n)
            {
                for (int  i = 1; i <= n; i++)
                {
                    printf("%d\t", x[i]);
                }
                printf("\n");
                
            }
            else{
                recur_nqueens(k + 1, n);
            }
        }
    }
}

int main(){
     
    printf("\nEnter The Size N : ");
    scanf("%d", &n);
    recur_nqueens(1, n);
    x[n];

    // for (int i = 1; i <= n; i++)
    // {
    //     x[i] = i;
    // }
    
    return 0;

}