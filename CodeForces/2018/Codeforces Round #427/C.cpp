#include<bits/stdc++.h>
using namespace std;
const int MAXN = 102;
long long sum[12][MAXN][MAXN];
int get(int t , int X1 , int Y1 , int X2 , int Y2){
	return sum[t][X2][Y2] - sum[t][X2][Y1 - 1] - sum[t][X1 - 1][Y2] + sum[t][X1 - 1][Y1 - 1];
}
int main(){
	freopen("in.in" , "r" , stdin);
	int n , m , c;
	scanf("%d%d%d" , &n , &m , &c);
	int mod = c + 1;
	for(int i = 0 ;i < n ;i ++){
		int x,  y , s;
		scanf("%d%d%d" , &x , &y , &s);
		int cur = s;
		for(int ii = 0 ; ii < mod ; ii ++){
			if(cur > c)
				cur = 0;
			sum[ii][x][y] += cur;
			cur ++;
		}
	}
	for(int x = 0 ; x < mod; x ++)
		for(int i = 1 ;i < MAXN ;i ++)
			for(int ii = 1; ii < MAXN ;ii ++)
				sum[x][i][ii] += sum[x][i - 1][ii] + sum[x][i][ii - 1] - sum[x][i - 1][ii - 1];	

	
	while(m --){
		int t , x , y ,x2 , y2;
		scanf("%d%d%d%d%d" , &t , &x , &y , &x2 , &y2);
		t %= mod;
		int X1 = x, Y1 = y , X2 = x2 , Y2 = y2;
		int ret = get(t , X1 , Y1 , X2 , Y2);
		printf("%d\n" , ret);
	}
}
