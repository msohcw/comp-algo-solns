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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define INF18 100000000000000000
#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N, x, y;
ll dp[20000010];

int main(){
  scanf("%d%d%d", &N, &x, &y);
  for(int i = 0; i <= N; ++i) dp[i] = INF18;
  dp[0] = 0;
  dp[1] = x;
  for(int i = 2; i <= N; ++i){
    ll forward = dp[(i+1)/2] + y + x + (i+1)%2 * x;
    ll backward = dp[i-1] + x;
    dp[i] = min(forward, backward);
  }
  cout << dp[N] << endl;
}
