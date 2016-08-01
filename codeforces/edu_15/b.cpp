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
vi num;
ll pairs = 0;

int msb(int x){
  int m = 0;
  while(x >> m >= 1) m++;
  return m;
}

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    int a;
    scanf("%d", &a);
    num.push_back(a);
  }

  sort(num.begin(),num.end());
  for(int i = N-1; i >= 0; --i){
    int partner = (1 << msb(num[i])) - num[i];
    if(binary_search(num.begin(), num.begin()+i,partner)){
      pairs += upper_bound(num.begin(),num.begin()+i,partner) - lower_bound(num.begin(), num.begin()+i,partner);
    }
  }
  cout << pairs << endl;
}
