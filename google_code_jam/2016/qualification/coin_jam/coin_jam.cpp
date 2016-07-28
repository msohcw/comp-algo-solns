#include <stdio.h>
#include <cstring>
#include <math.h>
#include <vector>

using namespace std;

int T, N, J;
int sieve[66000];
vector<int> list;

unsigned int in_base(unsigned int n, int b){
  unsigned int r = 0;
  int ct = 0;
  while(n >> ct > 0){
    if(n >> ct & 1) r += int(pow(double(b), double(ct)));
    ct++;
  }
}

int main(){
    scanf("%d%d%d", &T, &N, &J);
    unsigned int floor = pow(2, double(N-1)) + 1;
    unsigned int ceil = pow(2, double(N)) -1;
    printf("%u %u diff %u\n", floor, ceil, floor - ceil);
    memset(sieve, 0, sizeof(sieve));

    for(int i = 3; i<=pow(2, double(N/2)); i+=2){
        if(sieve[i] == 1) continue;
        list.push_back(i);
        for(int j = i; j<= pow(2,double(N/2)); j+=i) sieve[j] = 1;
    }
    
    for(unsigned int i = floor; i<ceil;i++){
        
    }
}
