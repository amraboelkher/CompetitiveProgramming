#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002] , n , m , W;
int gb[1002] , mxInG[1002] , P[1002] , b[1002] , w[1002];
vector< pair<int ,int > > G[1002];
int get(int a){
	return (a == P[a] ? a : P[a] = get(P[a]) );
}
void un(int a , int b){
	if(get(a) == get(b) )
		return ;
	P[get(a)] = get(b);
}
int rec(int idx , int total){
	if(idx >= n)
		return 0;
	int &ret = dp[idx][total];
	if(ret != -1)
		return ret;
	ret = rec(idx+1 , total);
	int sum1 = 0 , sum2 = 0;
	for(int l = 0 ;l < G[idx].size(); l ++){
		sum1 += G[idx][l].first , sum2 += G[idx][l].second ;
		if(G[idx][l].first + total <= W)
			ret = max(ret , G[idx][l].second + rec(idx + 1 , G[idx][l].first + total) );
	}
	if(sum1 + total <= W)
		ret = max(ret , sum2 + rec(idx + 1 , total + sum1) );
	return ret;
} 

int main(){

	scanf("%d%d%d" , &n , &m , &W);
	for(int i = 0 ;i < n ;i ++)
		scanf("%d" , &w[i]);
	for(int i = 0 ;i < n ;i ++)
		scanf("%d" , &b[i]) , P[i] = i;
	while(m --){
		int a , b;
		scanf("%d%d" , &a , &b) , a -- , b --;
		un(a , b);
	}

	for(int i = 0; i < n ;i ++)
		G[get(i)].push_back(make_pair(w[i] , b[i]) );
	memset(dp , -1 , sizeof dp);
	printf("%d\n" , rec(0 , 0) );
	
	

}
