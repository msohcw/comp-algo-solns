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
int w, v, u;
vii poly;
ii maxX, minY;

int main(){
  scanf("%d%d%d%d", &N, &w, &v, &u);
  maxX = make_pair(-INF,0);
  minY = make_pair(0,INF);
  for(int i = 0; i < N;i++){
    int x, y;
    scanf("%d%d",&x,&y);
    if(x > maxX.first) maxX = make_pair(x,y);
    if(y < minY.second) minY = make_pair(x,y);
    
    poly.push_back(make_pair(y,x));
  }
  sort(poly.begin(),poly.end());
  // lowest;
  double t = 0;
  double pPos = 0;
  double bPos = 0;
  double pt = 0;
  while(pPos < w && pt < N){
    ii low = poly[pt];
   printf("at %d %d, pos:%f, bus:%f, t:%Lf   ", low.second, low.first, pPos, bPos, t);
    if(low.second - bPos <= 0){ // translate
      pt++;
    }else{
      double low_reach_zero = ((double) low.second - bPos) / double(v);
      printf("low.second: %Lf b.pos: %Lf,  v: %d lrz: %Lf \n",(double) low.second, bPos, v, low_reach_zero);
      if(pPos + low_reach_zero * double(u) <= low.first || low.second == maxX.first){
        // run
        //pPos += low_reach_zero * double(u);
        if(pPos + low_reach_zero*double(u) >= w){
          t += (double(w)-pPos)/double(u);
          pPos = w;
        }else{
          t += low_reach_zero;
          pPos += low_reach_zero * double(u);
        }
      }else{
        // halt
        t+= low_reach_zero;
        pPos = low.first; // touch the point
      }
      bPos = low.second;
      pt++;
    }
  }
  
   printf("final  pos:%f, bus:%f, t:%Lf\n", pPos, bPos, t);
    if(pPos < w){
      t += (double(w)-pPos)/double(u);
    }
  printf("%.10lf\n", t);
}
