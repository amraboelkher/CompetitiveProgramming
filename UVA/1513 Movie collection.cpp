#include<bits/stdc++.h>
using namespace std;
struct T{
	vector< int > Te;
	int n;
	T(int _n){
		n = 2 * _n + 2;
		Te.resize(n);
	}
	void add(int idx , int v){
		while(idx < n){
			Te[idx] += v;
			idx += (idx & -idx);
		} 
	}
	int get(int idx){
		int ret = 0;
		while(idx > 0){
			ret += Te[idx];
			idx -= (idx & -idx);
		}
		return ret;
	}
};
int main(){
	int t;
	scanf("%d" , &t);
	while(t --){
		int n , m;
		scanf("%d%d" , &n , &m);
		vector< int > A(n + 1);
		T tree(max(n , m));
		int mx = max(n , m);
		for(int i = 1 ;i <= n ;i ++)
			tree.add(i + mx , 1) , A[i] = i + mx;
		int cur = mx;
		for(int i = 0 ;i < m ;i ++){
			int x ;
			scanf("%d" , &x) ;
			int ret = tree.get(A[x] - 1);
			tree.add(A[x] , -1);
			A[x] = cur --;
			tree.add(A[x] , 1);
			if(i)printf(" ");
			printf("%d" , ret);	
		}
		puts("");
	}
}
