#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 3;
int res[MAXN] , boyFriendNo[MAXN] , girlFriendNo[MAXN];
bool vis[MAXN] , noWayOut;
vector< int > goTo[MAXN];
void dfs(int u , int color){
	if(vis[u]){
		if(!noWayOut && res[u] != color)
			noWayOut = 1; 
		return ;
	}
	res[u] = color;
	vis[u] = 1;
	color = (color + 1 ) % 2;
	for(int i = 0 ;i < goTo[u].size() ;i ++)
		dfs(goTo[u][i] , color);
}
int main(){
	int couples ;
	scanf("%d" , &couples);
	for(int i = 1;i <= 2 * couples; i += 2){
		goTo[i].push_back(i + 1);
		goTo[i + 1].push_back(i);
	}
	for(int i = 0; i < couples ;i ++){
		scanf("%d%d" , &boyFriendNo[i] , &girlFriendNo[i]);
		goTo[boyFriendNo[i]].push_back(girlFriendNo[i]);
		goTo[girlFriendNo[i]].push_back(boyFriendNo[i]);
	}
	for(int i = 1; i <= 2 * couples; i ++){
		if(!vis[i])
			dfs(i , 0);
	}
	if(noWayOut)puts("-1");
	else {
		for(int i = 0; i < couples ;i ++)
			printf("%d %d\n" , res[boyFriendNo[i]] + 1 , res[girlFriendNo[i]] + 1 );
	} 
	
}

