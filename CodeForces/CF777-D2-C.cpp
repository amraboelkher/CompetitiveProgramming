#include<bits/stdc++.h>
using namespace std;
int main(){


	
	int n , m;
	scanf("%d%d" , &n , &m);
	vector< vector< int > > tmp , res , res1;
	vector< int > rows(n);
	for(int i = 0 ;i < n ;i ++){
		vector< int > x(m);
		for(int l = 0 ;l  <m ; l ++)
			scanf("%d" , &x[l]);
		tmp.push_back(x);
		res.push_back(x);
		res1.push_back(x);
	}
	for(int i = 0 ;i < n ;i ++)
		for(int l = 0 ;l < m ;l ++)
			res[i][l] = 0 , res1[i][l] = 0;
	for(int l = 0 ; l < m ;l ++)
		for(int i = 0; i < n; i ++){
			if(i == 0)res1[i][l] = 1;
			else res1[i][l] = (tmp[i][l] >= tmp[i - 1][l]); 
		}
	

	for(int l = 0; l < m ;l ++){
		for(int i = 1 ; i < n ;i ++)
			if(res1[i][l])res1[i][l] += res1[i - 1][l];
	}
	
	for(int i = 0 ;i < n ;i ++){
		for(int l = 0 ;l < m ;l ++)
			rows[i] = max(rows[i] , res1[i][l]);
	}
	int q;
	scanf("%d" , &q);
	while(q --){

		int a , b;
		scanf("%d%d" , &a , &b) , a-- , b--;
		if(rows[b] >= b - a)puts("Yes");
		else puts("No");
	}
	return 0;
		
}
