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

#define I18F 1000000000000000000 // 10^18
#define INF 2139062143
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N, T;
vi H;
ll maxsum[100010];
ll maxval;

int main(){
  scanf("%d", &T);
  for(int tc = 0; tc < T; ++tc){
    scanf("%d", &N);
    H.clear();
    maxval = 0;
    for(int i = 0; i < N; ++i){
      int a;
      scanf("%d", &a);
      H.push_back(a);
    }
    sort(H.begin(), H.end());
    maxsum[N] = 0;
    for(int i = N-1; i >= 0; --i){
      maxsum[i] =  maxsum[i+1] + H[i];
    }
    for(int i = 0; i < N; ++i){
      maxval = max( maxval, (i+1) * maxsum[i]);
    }
    printf("%lld\n", maxval);
  }
}
