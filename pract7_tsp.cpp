#include <iostream>
using namespace std;

#define INT_MAX 999999

#define n 4
int dp[2*n][n];
int dist[n][n];

// = {
//     {0, 20, 42, 25},
//     {20, 0, 30, 34},
//     {42, 30, 0, 10},
//     {25, 34, 10, 0}};

// mask set of cities that has been visited
int VISITED_ALL = (1 << n) - 1;

int tsp(int mask, int pos){ 

  if (mask == VISITED_ALL)
  {
    return dist[pos][0];
  }

 
  int ans = INT_MAX;

  //  // Look Up
  // if (dp[mask][pos] != -1)
  // {
  //   return dp[mask][pos];
  // }
  


  //try to go to unvisited city
  for (int  city = 0; city < n; city++)
  {
    if ((mask &(1<<city))==0)
    {
      int newans = dist[pos][city] + tsp(mask|(1<<city), city);
      ans = min(ans, newans);
    }
    
  }
  return dp[mask][pos] = ans;
}



int main(){
  

  
  cout << "Enter Graph Matrix NXN : \n";

  for (int i = 0; i < n; i++)
  { 
    for (int j = 0; j < n; j++)
    {
      cin >> dist[i][j];
    }
  }


  for (int i = 0; i < n; i++)
  { 
    for (int j = 0; j < n; j++)
    {
      if (dist[i][j] == 0)
      {
        dist[i][j] = 999;
      }
      
    }
  }



  for (int i = 0; i < n; i++)
  { 
    for (int j = 0; j < n; j++)
    {
      dp[i][j] = -1;
      
      
    }
  }

  cout << "Minimum cost pasth for TSP is : " << tsp(1, 0) << endl;

  return 0;
}