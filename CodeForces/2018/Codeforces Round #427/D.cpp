#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5003;
int dp[MAXN][MAXN] , ret[MAXN];
int main(){
	freopen("in.in" , "r" , stdin);
	int N;
	string S;
	cin >> S;
	N = S.size();
	for(int i = 0 ;i < N ;i ++)
		dp[i][i] = 1 , ret[dp[i][i]] ++;
	for(int L = 2; L <= N ;L ++){
		for(int i = 0 ;i + L <= N ;i ++){
			int j = i + L - 1;
			if(S[i] == S[i + L - 1] && (L == 2 || dp[i + 1][i + L - 2] != 0) )
				dp[i][i + L - 1] += dp[i][i + L / 2 - 1] +  1;
			ret[dp[i][i + L - 1]] ++;
		}
	}

	for(int i = N - 1 ;i ; i --)
		ret[i] += ret[i + 1];
	for(int i = 1; i <= N ;i ++){
		if(i != 1)
			printf(" ");
		printf("%d" , ret[i]);
	}
	puts("");
	
}
