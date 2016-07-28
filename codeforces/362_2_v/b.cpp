#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

char num[10000];
int clean[10000];

int toNum(char a){
	return (int) a - 48;
}

int main(){
	memset(num, 0, sizeof(num));
	memset(clean, 0, sizeof(clean));
	
	gets(num);
	int decimal = -1;
	int eloc = -1;
	int dp = 0;
	int ptr = 0;

	for(int i = 0; i < strlen(num); i++){
		if(num[i] == '.'){
			decimal = i;
		}else if(num[i] == 'e'){
			eloc = i;
		}else if(eloc == -1){
			clean[ptr] = toNum(num[i]);
			ptr++;
		}
	}
	int power = 0;
	for(int i = eloc+1; i < strlen(num);i++){
		power += toNum(num[i]) * ceil(pow(10, strlen(num) - i - 1));
	}
	
	dp = power;
	bool leadingZero = true;

	if(clean[1] == 0 && ptr == 2) ptr = 1; 	//integer case
	for(int i = 0; i < ptr; i++){
		if(clean[i] == 0 && leadingZero && i != dp) continue;
		leadingZero = false;
		printf("%d", clean[i]);
		if(i == dp && i!= ptr-1) printf(".");
	}

	for(int i = ptr; i <= dp; i++)	cout << '0';
	cout << endl;
}