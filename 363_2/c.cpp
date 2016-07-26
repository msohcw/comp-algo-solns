#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int g[100];
int dp[100][3];

int min_rest = 10000;

// rest, contest, gym
// nothing, con, gym, congym
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &g[i]);
    }
    min_rest = N;
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    if(g[0] == 1) dp[0][1] = 0;
    if(g[0] == 2) dp[0][2] = 0;
    if(g[0] == 3) dp[0][1] = dp[0][2] = 0;

    for(int i = 1; i < N; i++){
        dp[i][0] = min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + 1;
        dp[i][1] = dp[i][2] = dp[i][0];
        if(g[i] == 1){
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }else if(g[i] == 2){
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);    
        }else if(g[i] == 3){       
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);    
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }
    }

    min_rest = min(min(dp[N-1][0],dp[N-1][1]),dp[N-1][2]);
    printf("%d\n", min_rest);
}
