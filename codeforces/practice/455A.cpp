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

#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N;
ll num[100010];
ll dp[100010][2];
ll minV = INF;
ll maxV = -1;

int main(){
  scanf("%d", &N);
  memset(num, 0, sizeof(num));
  for(int i = 0; i < N; ++i){
    int a;
    scanf("%d", &a);
    num[a]++;
    maxV = max(maxV, (ll) a); 
    minV = min(minV, (ll) a);
  }
  dp[minV][0] = 0;
  dp[minV][1] = minV * num[minV];
  for(int i = minV+1; i <= maxV; ++i){
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    dp[i][1] = dp[i-1][0] + i*num[i];
  }
  printf("%I64d\n", max(dp[maxV][0], dp[maxV][1]));
}
