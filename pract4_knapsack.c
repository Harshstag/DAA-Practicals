#include <stdio.h>
void knapsack(float M, int N){

    float wi[N], pi[N], piwi[N], temp, remain = M;

    for (int i = 0; i < N; i++)
    {
        printf("\nEnter Profit and Weight : ");
        scanf("%f %f", &pi[i], &wi[i]);
        piwi[i] = pi[i] / wi[i];  //pi[i], wi[i]
    }


    //arranging it in decresing order
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if ( piwi[i] < piwi[j] )
            {
                temp = piwi[j]; //swaping ratio
                piwi[j] = piwi[i];
                piwi[i] = temp;

                temp = pi[j];  //  swaping profit
                pi[j] = pi[i];
                pi[i] = temp;

                temp = wi[j];   // swaping weight
                wi[j] = wi[i];
                wi[i] = temp;
            }   
        } 
    }

    float x[N], profit = 0.00;
    for (int  i = 0; i < N; i++)
    {

        if (remain <= 0)
        {
            x[i] = 0.00;
        }
        else if (wi[i] < remain) 
        {
            x[i] = 1.0;
            remain = remain - wi[i];
        }
        else
        {
            x[i] = remain / wi[i];
            remain = remain - wi[i];
        }
        printf("\nFor Pi [ %.2f ] Wi[ %.2f ] Xi is [ %.2f ] ", pi[i], wi[i], x[i]);
        profit = profit + (pi[i] * x[i]);
    }

    printf("\n\nReqired PiXi = %.2f\n", profit);
}
int main(){
    float M;
    int N;

    printf("\nEnter Maximum capacity : ");
    scanf("%f", &M);

    printf("\nEnter Number of objects : ");
    scanf("%d", &N);

    knapsack(M, N);

    return 0;
}