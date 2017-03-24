#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector< int > A , B;
int get(int c){
	int res = 0 , curT = 0;
	for(int i = 0 ; i < A.size() ;i ++){
				curT += B[i];
		ll cost = A[i] - c * curT;

		res += max(0LL , cost);
	}
	return res;
}
int main(){
	int n , c;
	scanf("%d%d" , &n , &c);
	A.resize(n);
	B.resize(n);
	for(int i = 0 ;i < n ;i ++)
		scanf("%d" , &A[i]);
	for(int i = 0 ;i < n ;i ++)
		scanf("%d" , &B[i]);
	int a = get(c);
	reverse(A.begin() , A.end());
	reverse(B.begin() , B.end());
	int b = get(c);
	if(a > b)
		puts("Limak");
	else if(a < b)
		puts("Radewoosh");
	else puts("Tie");
	
}
