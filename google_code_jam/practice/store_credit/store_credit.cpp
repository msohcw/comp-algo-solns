#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int t;

int main(){
  scanf("%d", &t);
  for(int i = 0;i<t;i++){
    int c, l, p;
    scanf("%d%d", &c, &l);
    vector< pair<int, int> > list;
    for(int j = 0;j<l;j++){
      scanf("%d", &p);
      list.push_back(make_pair(p,j));
    }
    
    sort(list.begin(), list.end());
    int s = 0;
    int e = l-1; 
    while(s<e){
      int sum = list[s].first+list[e].first;
      if(sum == c){
        int a = (list[s].second < list[e].second)?list[s].second+1:list[e].second+1;
        int b = (list[s].second < list[e].second)?list[e].second+1:list[s].second+1;
        printf("Case #%d: %d %d\n", i+1,a,b);
        break;
      }else{
        if(sum > c) e--;
        if(sum < c) s++;
      }
    }
  }
}
