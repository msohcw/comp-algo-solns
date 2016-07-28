#include <stdio.h>
#include <cstring>
#include <cmath>

using namespace std;

int T;
int mem[105][105][105];

int gold(int k, int c, int o, int p){
    if(c == 1) return o == p;
    if(gold(k,c-1,o,p/k)){
        return true;
    }else{
        return (p%k == o);
    }
}

int main(){
    scanf("%d", &T);
    for(int Tn = 1; Tn <= T; Tn++){
        printf("Case #%d: ", Tn);
        int k, c, s;
        scanf("%d%d%d", &k, &c, &s);
        int moves = ceil(float(k)/float(c));
        //int min_gain = ceil(float(k)/float(moves));
        if(moves > s){
            printf("IMPOSSIBLE\n");
        }else{
           int covered = 0;
          
           for(unsigned long long int i = 62312000; i < (unsigned long long int)(pow(double(k),double(c))); i++){
               int ct = 0;
               if(i == 62313000) break;

              
               bool flag = true;
               for(int j = 0; j<k; j++){
                    if(!gold(k,c,j,i)){
                        printf(".");
                        flag = false;
                        //break;
                    }else{
                        printf("G");
                    }
                }
               printf(" %llu\n", i+1);
               if(flag){
                  //printf("%llu ", i+1);
                  covered+=c;
                  if(covered + c <= k) i = (unsigned long long int) (ceil(double(i)/pow(double(k),double(c-1))) * pow(double(k),double(c-1)));
               }
               if(covered >= k) break;
            }
            printf("\n");
        }
    }
} 
