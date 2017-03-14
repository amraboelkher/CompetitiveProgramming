#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1002;
vector< int > T[MAXN];
int A[MAXN] , B[MAXN] , C[MAXN] , Tm[MAXN]  , idx , done , id , N , H;
pair<int , int > dp1[MAXN][(1 << 10) + 2][25] , dp2[MAXN][25];
pair< int , int > rec1( int u , int msk , int rem) ;

pair<int ,  int > rec2( int  u , int rem ){
	pair<int ,  int > &ret = dp2[u][rem];
	if(ret.first != -1)
		return ret;
	ret = make_pair(0 , 0);
	int tm = Tm[u];
	if(tm > rem)
		ret.first ++ , rem = H;
	rem -= tm;
	pair< int , int > P = rec1(u , 0 , rem);
	ret.first += P.first ;
	ret.second = P.second ;
	return ret;
}
pair<int , int> rec1(int u , int msk ,  int rem){
	pair<int , int> &ret = dp1[u][msk][rem];
	int sz = T[u].size();
	if(msk == (1 << sz) - 1)
		return make_pair(0 , rem);
	if(ret.first != -1)
		return ret;
	ret = make_pair((1 << 22) , -1);
	if(T[u].size() == 0)
		ret = make_pair(0 , rem);
	for(int i = 0 ;i < T[u].size() ;i ++){
		int v = T[u][i];
		if(!(msk & (1 << i)) ){
			pair<int , int > P = rec2(v , rem);
			pair<int , int > R = rec1(u ,( msk | (1 << i) ), P.second);
			if(R.first + P.first < ret.first)
				ret.first = R.first + P.first , ret.second = R.second;
			else if(R.first + P.first == ret.first && R.second > ret.second)
				ret.first = R.first + P.first , ret.second = R.second;
		}
	}
	return ret;
}
int main(){
	int t;
	scanf("%d" , &t);
	while(t --){
		id = idx = done = 0;
		scanf("%d%d" , &N , &H);
		for(int i = 0 ;i < N ;i ++)
			scanf("%d" , &Tm[i]);
		for(int i = 0 ;i < N ;i ++){
			int m  , tmp;
			scanf("%d" , &m);
			for(int l = 0 ;l < (1 << m) ;l ++)
				for(int k = 0 ;k <= H; k ++)
					dp1[i][l][k] = make_pair(-1 , -1);
			for(int k = 0 ;k <= H ;k ++)
				dp2[i][k] = make_pair(-1 , -1);
				
			T[i].clear();
			while(m --){
				scanf("%d" , &tmp);
				T[i].push_back(tmp - 1);
			}
		}
		pair< int , int > res = rec2(0 , 0);
		printf("%d\n" , res.first);

	}
}
