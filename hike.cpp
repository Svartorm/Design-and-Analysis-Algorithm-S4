// Knapsack problem 
/*
Vasya is going to hike with fellow programmers and decided to take a responsible approach to the choice of what he will take with him. Vasya has n things that he could take with him in his knapsack. Every thing weighs 1 kilogram. Things have different "usefulness" for Vasya.

The hiking is going to be very long, so Vasya would like to carry a knapsack of weight no more than w kilo.

Help him to determine the total "usefulness" of things in his knapsack if the weight of backpack can be no more than w kilo.

INPUT: 
The first line contains integers w и n (1 ≤ w, n ≤ 20). The second line contains n integers c[i] (1 ≤ c[i] ≤ 1000) - the "usefulness" for each thing

OUTPUT:
Print the total "usefulness" of things that Vasya can take with him.
*/

//0-1 Knapsack Dynamic Programming
#include<stdio.h>

#define max(x, y) ((x < y) ? y : x)

int main() {
    int G, N;   //G:max weight, N: number of elements
    scanf("%d %d", &G, &N);
    int Weight[N+1], Price[N+1];    //wt: weight, p:price
    int dp[N+1][G+1];   //memoization
    Weight[0]=Price[0]=0;   //starting from zero
    for(int c=1;c<=N;c++){
        scanf("%d", &Price[c]);
        Weight[c] = 1;
    }

    for(int i=0;i<=N;i++){
        for(int w=0;w<=G;w++){
            if(i==0 || w==0)
                dp[i][w]=0;
            else if(Weight[i]<=w)
                dp[i][w]= max(Price[i]+dp[i-1][w-Weight[i]],dp[i-1][w]); 
            else 
                dp[i][w]= dp[i-1][w];
        }
    }
    
    //minimize weight
    int stop=0;
    for(int i=1;i<=G;i++){
        if(dp[N][i]==dp[N][G]){
            stop=i;
            break;
        }
    }
    printf("%d\n", dp[N][G]);
    return 0;
}