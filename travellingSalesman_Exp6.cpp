#include <bits/stdc++.h>
using namespace std;
#define INF 99999999

int n = 4;
int dp[16][4];
int dist[10][10] = {
    {0, 10, 15, 20},
    {5, 0, 25, 10},
    {15, 30, 0, 5},
    {15, 10, 20, 0}
};

int VISITED_ALL = (1<<n) -1;

int tsp(int mask, int pos) {
    
    if(mask==VISITED_ALL) {
        return dist[pos][0];
    }
    if(dp[mask][pos] != -1) {
       return dp[mask][pos];
    }

    int ans = INF;
    
    for(int city=0;city<n;city++) {

        if((mask&(1<<city))==0) {

            int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
            ans = min(ans, newAns);
            
        }

    }
    
    return dp[mask][pos] = ans;
    
}

int main() {
    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<n;j++) {
            dp[i][j] = -1;
        }
    }
    cout<<"The minimum travelling cost is "<<tsp(1,0)<<endl;

    return 0;
}