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

int T, N;
vector<ll> A;
vector<ll> maxsum;

int maxval(int l, int r, int depth){
  if(r - l <= 1) return depth;
  double weight = double(maxsum[r-1]);
  if(l > 0) weight += double(maxsum[l-1]);
  weight /= 2;
  int mid = lower_bound(maxsum.begin()+l, maxsum.begin()+r, weight) - maxsum.begin();
  if(double(maxsum[mid]) == weight) return max(maxval(l, mid+1, depth + 1), maxval(mid+1, r, depth+1));
  return depth;
}

int main(){
  scanf("%d", &T);
  for(int tc = 0; tc < T; tc++){
    A.clear();
    maxsum.clear();
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
      int a;
      scanf("%d", &a);
      A.push_back(a);
      if(i == 0){
        maxsum.push_back(a);
      }else{
        maxsum.push_back(maxsum[i-1] + a);
      }
    }    
    printf("%d\n", maxval(0, N, 0));
  }
}
