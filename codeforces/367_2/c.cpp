#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define LLINF 9223372036854775807
#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N;
int cost[100010];
ll dp[100010][2];
char prev[100010];
char now[100010];

bool weakcmp(char c1, char c2){ return c1 <= c2; }

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d", &cost[i]);
  scanf("\n");
  dp[0][0] = 0;
  dp[0][1] = cost[0];
  fgets(prev, 100000, stdin);
  prev[strcspn(prev, "\n")] = 0;
  int flag = true;
  for(int i = 1; i < N; ++i){
    fgets(now, 100000, stdin);
    now[strcspn(now, "\n")] = 0;
    dp[i][0] = dp[i][1] = LLINF;
    char* _prev = prev + strlen(prev);
    char* _now = now + strlen(now);
    if(lexicographical_compare(prev, _prev, now, _now) || strcmp(prev, now) == 0) dp[i][0] = dp[i-1][0];
    reverse(prev, _prev);
    if(lexicographical_compare(prev, _prev, now, _now) || strcmp(prev, now) == 0) dp[i][0] = min(dp[i][0], dp[i-1][1]);
    reverse(now, _now);
    if(lexicographical_compare(prev, _prev, now, _now) || strcmp(prev, now) == 0) dp[i][1] = dp[i-1][1] + cost[i];
    reverse(prev, _prev);
    if(lexicographical_compare(prev, _prev, now, _now) || strcmp(prev, now) == 0) dp[i][1] = min(dp[i][1], dp[i-1][0] + cost[i]);
    reverse(now, _now);
    strcpy(prev,now);
    
    if(dp[i][0] == LLINF && dp[i][1] == LLINF){
      flag = false;
      break;
    }
  }
  if(flag){
    printf("%I64d\n", min(dp[N-1][0], dp[N-1][1]));
  }else{
    printf("-1\n");
  }
}
