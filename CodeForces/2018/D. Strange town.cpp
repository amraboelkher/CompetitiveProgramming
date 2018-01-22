#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 2 , N = 22;
int A[N] , vis[MAXN];
int main(){
	freopen("in.in" , "r", stdin);
	int n ;
	scanf("%d" , &n);
	vis[1] = vis[2] = vis[3] = 1;
	A[1] = 1 , A[2] = 2;
	for(int i = 3; i <= n ;i ++){
		bool flag = 0;
		int &cur = A[i];
		while(!flag){
			flag = 1;
			for(int ii = 0 ; ii < i ; ii ++){
				if(vis[A[ii] + cur]){
					flag = 0;
					break;
				}
			}
			cur += flag ^ 1;
		}
		for(int ii = 0 ;ii < i ; ii ++)
			vis[A[ii] + cur] = 1;
	}
	for(int i = 0 ; i < n ;i ++){
		for(int ii = 0 ;ii < n ; ii ++){
			int sum = A[i] + A[ii];
			if(i == ii) sum = min(i ^ ii , sum);
			if(ii)printf(" ");
			printf("%d" , sum);
		}
		puts("");
	}
}
