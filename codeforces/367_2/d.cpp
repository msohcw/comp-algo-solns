#include <cstdlib>
#include <stdio.h>
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
set<int> ms;
map<int, int> num;

int main(){
  scanf("%d", &N);
  ms.insert(0);
  for(int i = 0; i < N; ++i){
    char a;
    int d;
    scanf(" %c %d", &a, &d);
    if(a == '+'){
      if(ms.count(d) == 1){
        num[d]++;
      }else{
        num[d] = 1;
        ms.insert(d);
      }
    }else if(a == '-'){
      if(num[d] == 1) ms.erase(d);
      num[d]-=1;
    }else if(a == '?'){
      int ct = 0;
      int low = 0;
      int high = *(ms.rbegin()) + 1;
      int ptr = 0;      
      for(int i = 30; i >= 0; i--){
        ptr |= (1 << i);
        if(ms.lower_bound(ptr) == ms.end()){
          ptr -= (1 << i);
          continue;
        }
        int lb = *(ms.lower_bound(ptr));  
        
        if(((1 << i) & d) == 0){ // 0, look for 1
          if(lb < high) low = lb;
          if(lb >= high) ptr -= (1 << i);
        }else{ // searching for highest 1
          if(lb < high && lb > low) high = lb;
          if(lb > low) ptr -= (1 << i);
        }
      }
      printf("%d\n", low^d);      
    }
  } 
}
