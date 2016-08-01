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
int num[100010];
int dp[100010];

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d", &num[i]);
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for(int i = 1; i < N; ++i){
    dp[i] = 1;
    for(int j = i-1; j >= 0; --j){
      if(num[i] > num[j]) dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  printf("%d\n", dp[N-1]);
}
