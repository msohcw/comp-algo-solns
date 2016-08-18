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
char s[100010];
int sum[100010];
int main(){
  memset(sum, 0, sizeof(sum));
  fgets(s, 100000, stdin);
  sum[0] = 0;
  for(int i = 0; i < strlen(s)-1; ++i){
    if(s[i] == s[i+1]) sum[i+1] = 1;
  }
  for(int i = 1; i < strlen(s); ++i) sum[i] += sum[i-1];
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", sum[b-1] - sum[a-1]);
  }
}
