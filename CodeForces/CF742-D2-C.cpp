#include<bits/stdc++.h>
using namespace std;
bool ok ;
int vis[200] , to[200] , req;
bool poss , noway;
int dfs(int cur){
	if(vis[cur]){
		if(cur == req)
			poss = 1;
		return 0;
	}
	vis[cur] = 1;
	return 1 + dfs(to[cur]);
}
int main(){

	int n	 ;
	scanf("%d" , &n);
	for(int i = 1; i <= n ;i ++)
		scanf("%d", &to[i]) ;
	int res = 1;
	for(int i = 1; i <= n ;i ++){
		if(!vis[i]){
			poss = 0;
			req = i;
			int tmp = dfs(i);
			if(!poss)noway = 1;
			if(tmp % 2 == 0) tmp /= 2;
			res = res * tmp / __gcd(res , tmp);
		}
	}
	if(noway)puts("-1");
	else
		printf("%d\n" , res);

}
