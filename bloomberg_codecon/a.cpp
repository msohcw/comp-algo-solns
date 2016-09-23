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
#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

// priority_queue<int, std::vector<int>, std::greater<int> > Q;

int N, M;
vii orders;
int num[100];
int maxv = -1;
int t = 0;
queue<ii> Q;

int main(){
  scanf("%d %d", &N, &M);
  memset(num, sizeof(num), 0);

  for(int i = 0; i < N; ++i){
    int a;
    scanf("%d", &a);
    num[a] += 1;
    maxv = max(a, maxv);
    Q.push(make_pair(a, i));
  }
  while(!Q.empty()){
      if(num[maxv]  == 0){
        maxv--;
        continue;
      }
      ii top = Q.front();
      Q.pop();
      if(top.first < maxv){
        Q.push(top);
      }else if(top.second == M){
        t += 2;
        printf("%d\n", t);
        break;
      }else{
        num[maxv] -= 1;
        t+=2;
      }
  }
}
