#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 3;
vector< int > Adj[MAXN];
int cur , mx[MAXN] , n , d, h;
int main(){

	scanf("%d%d%d" , &n , &d , &h);
	if(d > 2 * h || d < h || (h == 1 && n == 2 && d != 1) || (h == 1 && n > 2 && d != 2)){
		puts("-1");
		return 0;
	}
	
	int D = d;
	cur ++;
	int myH = 0;
	while(myH < h){
		Adj[cur].push_back(cur + 1);
		cur ++;
		myH ++;
		d --;
	}
	cur ++;
	if(d > 0){	
		Adj[1].push_back(cur);
		int value = 1 , pv = cur;
		d --;
		while(d > 0){
			Adj[cur].push_back(cur + 1);
			cur ++;
			d --;
		}
		cur ++;
	}
	int x = 2;
	if(h == 1 && n > 2 && D == 2)
		x = 1;
	while(cur <= n){
		Adj[x].push_back(cur);
		cur ++;
	}
	for(int i = 1; i <= n ; i ++){
		for(int ii = 0; ii < Adj[i].size() ; ii ++)
			printf("%d %d\n" , i , Adj[i][ii]);
	}
	
	
	
	
}
