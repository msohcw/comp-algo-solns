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

ll d,k,a,b,t;

int main(){
  scanf("%lld%lld%lld%lld%lld", &d, &k, &a, &b, &t);
  if(k >= d){ // drive
    printf("%lld\n", a*d);
  }else{
    long double density = (a*k+t);
    density /= k;
    if(density > b){
      printf("%lld\n", k*a + (d-k)*b);
    }else{
      ll T = 0;
      T += (ll)(d/k) * (a*k+t) - t;
      d = d%k;
      T = min(T+t+d*a, T+d*b);
      printf("%lld\n", T);
    }
  }
}
