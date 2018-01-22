#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 3 , MAXK = 7;
int AK[MAXK][2 * MAXK] , m;
void buildK(){
	for(int i = 2 ; i < MAXK ;i ++){
		for(int ii = 0 ; ii < 2 * (i - 1) ; ii ++){
			int md = ii;
			if(md == 0)md = 2;
			if(md > i)md = 2 * i - md;
			AK[i][ii] = md;
		}
	}
}
int cal(int x , int kk){
	x %= (2 * (kk - 1) );
	return x;
}
struct node{
	vector< long long > v[MAXK];
	node(){
		for(int i = 2 ;i < MAXK ;i ++)
			v[i].resize(2 * (i - 1) );
	}
	void build(int val){
		for(int i = 2 ;i < MAXK ;i ++){
			for(int ii = 0 ; ii < 2 * (i - 1) ; ii ++){
				v[i][ii] = val * 1LL * AK[i][ii]; 
			}
		} 
	}
	void merge(node &L  , node &R , int sz){
		for(int i = 2 ;i < MAXK ;i ++){ 
			for(int ii = 0; ii < 2 * (i - 1) ;ii ++){
				v[i][ii] = L.v[i][ii];
				int nxt = cal(sz + ii , i);
				v[i][ii] += R.v[i][nxt];
			}
		}
	}
};

node Te[4 * MAXN] , dum;
int n;
void up(int idx , int l1 , int r1 , int l , int r , int v){
	if(l > r1 || r < l1)
		return ;
	if(l >= l1 && r <= r1){
		Te[idx].build(v);
		return ;
	}
	int md = (l + r) >> 1;
	up(idx * 2 , l1 , r1 , l , md , v);
	up(idx * 2 + 1 , l1 , r1 , md + 1 , r , v);
	int sz = md - l + 1;
	Te[idx].merge(Te[idx * 2] , Te[idx * 2 + 1] , sz);
}
int varK;
long long get(int idx , int l1 , int r1 , int l , int r , int kk){
	if(l > r1 || r < l1)
		return 0;
	if(l >= l1 && r <= r1){
		int x = cal(varK , kk);
		long long val = Te[idx].v[kk][x];
		varK += (r - l + 1);
		return val;
	}
	int md = (l + r) >> 1;
	return get(idx * 2 , l1 , r1 , l , md , kk ) + get(idx * 2 + 1 , l1 , r1 , md + 1 , r , kk);

} 
int main(){
	freopen("in.in" , "r" , stdin);
	buildK();
	scanf("%d" , &n);
	for(int i = 0 ;i < n ;i ++){
		int x;
		scanf("%d" , &x);
		up(1 , i , i , 0 , n - 1 , x);
	}
	scanf("%d" , &m);
	for(int i = 0 ;i < m ;i ++){
		int type , pos , l , r , val , zz;
		scanf("%d" , &type) , varK = 1;
		if(type == 1){
			scanf("%d%d" , &pos , &val) , pos --;
			up(1 , pos , pos , 0 , n - 1 , val);
		}
		else {
			scanf("%d%d%d" , &l , &r , &zz) , l -- , r -- ;
			long long ret = get(1 , l , r , 0 , n - 1 , zz);
			printf("%lld\n" , ret);
		}
	}
}

