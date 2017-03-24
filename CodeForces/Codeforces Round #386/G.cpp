#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 3;
int A[MAXN] , cur[MAXN];
int in1 ;
vector< int > Adj[MAXN];
int P[MAXN]  , in[MAXN];
pair<int , int > lvl[MAXN];
int main(){
	int n , m , k , tot = 1;
	scanf("%d%d%d" , &n , &m , &k);
	for(int i = 1; i <= m ;i ++)
		scanf("%d" , &A[i]) , tot += A[i] - 1;
	int cur = 1 , nxt = 2;
	for(int i = 1; i <= m ;i ++){
		int first = nxt;
		lvl[i].first = nxt;
		for(int ii = 0 ; ii < A[i] ; ii ++)
			 in[cur] ++ , P[nxt ++] = cur;
		lvl[i].second = nxt - 1;
		cur = first ;
	}
	for(int i = 2; i <= m && tot > k ; i ++){
		int sz = A[i - 1]  , toSz = A[i];
		int L = lvl[i - 1].first + 1 , R = lvl[i - 1].second , first = L - 1;
		int toL = lvl[i].first + 1 , toR = lvl[i].second;
		if(sz == 1 || toR < toL || toSz == 1 || in[first] <= 1)
			continue;
		while(toL <= toR && L <= R && tot > k){
			tot --;
			P[toL] = L;
			L ++;
			toL ++;
		}
	}
	for(int i = 2; i < nxt; i ++)
		Adj[P[i]].push_back(i);
	

	if(tot != k || nxt - 1 != n)
		in1 = 1;

	if(in1 != 0)puts("-1");
	else {
		printf("%d\n" , n);
		for(int i = 1; i < nxt ; i ++)
			for(int l = 0 ;l < Adj[i].size() ;l ++)
				printf("%d %d\n" , i , Adj[i][l]);
	}

}
