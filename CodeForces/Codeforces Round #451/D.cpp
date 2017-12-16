#include<bits/stdc++.h>
using namespace std;



const int MAXN = 2e5 + 3;
int A[MAXN];
int main(){
	freopen("in.in" , "r" ,  stdin);
	set <int > X;
	int n , m , k;
	scanf("%d%d%d" , &n , &m , &k);
	for(int i = 0 ;i < n ; i ++)
		scanf("%d" , &A[i]);
	sort(A , A + n);
	if(n < k){
		puts("0");
		return 0;
	}
	for(int i = 0 ;i < k ;i ++){
		X.insert(A[i]);
	}
	int f = *X.begin() , ed = *(--X.end());
		int ret = 0;
	if(ed - f + 1 <= m){
		X.erase((--X.end()));
		ret ++;
	}
	else {
		X.erase(X.begin());
	}


	for(int i = k ; i < n ;i ++){
		X.insert(A[i]);
		int f = *X.begin() , ed = *(--X.end());
		if(ed - f + 1 <= m){
			X.erase((--X.end()));
			ret ++;
		}
		else {
			X.erase(X.begin());
		}
	}
	cout << ret << endl;
	

	
	
}
