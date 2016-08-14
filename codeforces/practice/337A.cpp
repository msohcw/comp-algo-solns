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

int N, M;
vi puzzles;
int minV = INF;

int main(){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < M; ++i){
    int a;
    scanf("%d", &a);
    puzzles.push_back(a);
  }
  sort(puzzles.begin(), puzzles.end());
  for(int i = N-1; i < M; ++i) minV = min(minV, puzzles[i] - puzzles[i-N+1]);
  printf("%d\n", minV);

}
