#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>


#define INF 2000000000
#define PI 3.14159265358979
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int TC;


int main(){
	scanf("%d", &TC);
	for(int Tn = 1; Tn <= TC; Tn++){
		printf("Case #%d:\n", Tn);

		int N;
		scanf("%d", &N);

		int coord[3030][2];
		for(int i = 0; i < N; i++) scanf("%d%d", &coord[i][0], &coord[i][1]);
		for(int k = 0; k < N; k++){
			int min_chop = 5000;
			vector< pair<double, int> > angles;
			for(int i = 0; i < N; i++){
				if(i == k) continue;
				int dx = coord[i][0] - coord[k][0];
				int dy = coord[i][1] - coord[k][1];
				double angle = atan2(coord[i][1]-coord[k][1], coord[i][0] - coord[k][0]);
				if(angle < 0) angle += 2*PI;
				angles.push_back(make_pair(angle, i));
			}
			sort(angles.begin(), angles.end());
			int head = 0;
			//for(int i = 0; i < N - 1; i++) printf("%f (%f, %f) - ", angles[i].first, coord[angles[i].second][0], coord[angles[i].second][1]);
			for(int i = 0; i < N - 1; i++){
				//head = max(i, head);
				while(true){
					double diff = ((angles[head].first - angles[i].first) + 2 * PI);
					if(diff >= 2 * PI) diff -= 2*PI;
					//printf("head = %d, i=%d diff = %f\n", head, i, diff);
					if(!(abs(diff - PI) < EPS) && diff < PI){
						head++;
						head%=(N-1);
						if(head == i) break;
					}else{
						break;
					}
				}
				//int L = lower_bound(angles.begin(), angles.end(), angles[head].first + PI);
				//printf("head = %d, i=%d\n", head, i);
				min_chop = min(((head - i) + (N-1) ) % (N-1) - 1, min_chop);
				min_chop = max(min_chop, 0);
			}
			if(N == 1) min_chop = 0;			
			printf("%d\n", min_chop);
		}

	}
}