#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;

int n;
vector<iii> stars;

double shoestring(int a, int b, int c){
	long double area = 0;
	area += double(stars[a].first.first) * double(stars[b].first.second);
	area += double(stars[b].first.first) * double(stars[c].first.second);
	area += double(stars[c].first.first) * double(stars[a].first.second);


	area -= double(stars[a].first.second) * double(stars[b].first.first);
	area -= double(stars[b].first.second) * double(stars[c].first.first);
	area -= double(stars[c].first.second) * double(stars[a].first.first);

	if(area < 0) area = -area;
	return area/2;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		stars.push_back(make_pair(make_pair(a,b),i));
	}
	sort(stars.begin(),stars.end());
	for(int i = 0 ; i < 2; i++) printf("%d ", stars[i].second + 1);

	for(int i = 2 ; i < n; i++){
		if(shoestring(0,1,i) < 0.000001) continue;
		// printf("%f\n", shoestring(0,1,i));
		printf("%d\n", stars[i].second + 1);
		break;
	}
}