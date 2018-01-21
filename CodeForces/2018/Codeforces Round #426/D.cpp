#include<bits/stdc++.h>
using namespace std;
const int MAXN = 35005 , MAXK = 51;
int dp[MAXN][MAXK];
int  n  , K;
long long ac2[MAXN] , ac1[MAXN];
int rec(int idx , int k){
	if(k < 0)return -1e7;
	if(k == 0)return 0;
	if(idx == n)
		return  -1e7;
	int &ret = dp[idx][k];
	if(ret != -1)return ret;
	int x = ((k == K && idx) ? ac2[idx - 1] : 0);
	int y = ( k - 1 > 0 ? ac2[idx] : 0);
	
	ret = max(ac1[idx] + rec(idx + 1 , k) , ac1[idx] - y - x + rec(idx + 1 , k - 1) );
	cout << idx << " " << k << " " << ret << " -- " << ac1[idx] - y - x << " " << rec(idx + 1 , k) << " " << rec(idx + 1 , k - 1) << endl; 
}
void print(long long ar[]){
	for(int i = 0 ;i < n ;i ++)
		cout << ar[i] << " " ;
	cout << endl;
}
int main(){
	freopen("in.in" , "r" , stdin);
	
	scanf("%d%d" , &n , &K);
	memset(dp , -1 , sizeof dp);
	set< int > s;
	for(int i = 0 ;i < n ;i ++){
		int x; 
		scanf("%d" , &x);
		s.insert(x);
		ac1[i] = s.size();
		ac2[i] = ac1[i];
		if(i)	ac2[i] += ac2[i - 1];
	}
	int ret = 0;
	print(ac1);
	print(ac2);
	ret = rec(0 , K);
	printf("%d\n" , ret);
	
}
