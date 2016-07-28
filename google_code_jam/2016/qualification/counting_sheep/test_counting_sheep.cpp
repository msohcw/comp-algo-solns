#include <stdio.h>
#include <cstring>

using namespace std;

int sieve[1000010];
int nmax = 0;

int terminate(int x){
    int ct = 0;
    int mem[10];
    memset(mem, 0, sizeof(mem));
    for(int i = 1; i < 1000000; i++){
      int n = i*x;
      while(n > 0 && ct < 10){
        if(mem[n%10] == 0){ 
            mem[n%10] = 1;
            ct++;
        }
        n/=10;
      }
      if(ct == 10){
        printf("%d term %d\n",x,i*x);
        if(i > nmax) nmax = i;
        break; 
      }
    }
}

int main(){
  memset(sieve, 0, sizeof(sieve));
  sieve[2] = 1;
  terminate(1);
  terminate(2);
  for(int i = 3; i< 1000000; i+=2){
    if(sieve[i]) continue;
    terminate(i);
    for(int j = i; j< 1000000;j+=i) sieve[i] = 1;
  }
  printf("nmax is %d\n", nmax);
}
