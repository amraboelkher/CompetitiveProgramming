#include<bits/stdc++.h>
using namespace std;
int main(){
	int n  , mx = -1 , idx = 0;
	scanf("%d" , &n);
	long long res = 0;
	vector< int > r(n) , l(n) , A(n) , c(n);
	for(int i = 0 ; i < n ;i ++){
		scanf("%d" , &A[i]);
		if(A[i] > mx)
			mx = A[i] , idx = i;
	}
	rotate(A.begin() , A.begin() + idx , A.end());
	for(int i = n - 1; i >= 0 ;i --){
		r[i] = i + 1;
		while(r[i] < n && A[i] > A[r[i]])
			r[i] = r[r[i]];
		if(r[i] < n && A[i] == A[r[i]]){
			c[i] = c[r[i]] + 1;
			r[i] = r[r[i]];
		}
	}
	for(int i = 0 ;i < n ;i ++){
		res += c[i];
		if(A[i] == mx)continue;
		l[i] = i - 1 , res += 2;
		while(l[i] >= 0 && A[i] > A[l[i]])
			l[i] = l[l[i]];
		if(l[i] >= 0 && A[i] == A[l[i]]){
			c[i] = c[l[i]] + 1;
			l[i] = l[l[i]];
		}
		if(l[i] == 0  && r[i] == n)
			res --;
	}
	printf("%lld\n" , res);

}
