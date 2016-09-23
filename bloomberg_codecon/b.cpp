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
#include <sstream>

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

int N;
int open[150];
int used[150];
vi final[150];
int main(){
  memset(open, 0, sizeof(open));
  memset(used, 0, sizeof(used));
  scanf("%d\n", &N);
  for(int i = 0; i < N; ++i){
    char line[100];
    cin >> line;
    if(line[0] == '^'){
      open[line[1]] = 1;
      used[line[1]] = 1;
    }else if(line[0] == '/'){
      open[line[1]] = 0;
    }else{
      int insert = atoi(line);
      for(int i = 60; i < 130; ++i) if(open[i] == 1) final[i].push_back(insert);
    }
  }
  for(int i = 60; i < 130; ++i){
    if(used[i] == 0) continue;
    printf("%c ", char(i));
    sort(final[i].begin(), final[i].end());
    for(int j = 0; j < final[i].size(); ++j) printf("%d ", final[i][j]);
    printf("\n");
  }
}
