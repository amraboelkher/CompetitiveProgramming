#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n , m , q;
	scanf("%d%d%d" , &n , &m , &q);
	map<int , int > mp;
	vector< int > A(n);
	for(int i = 0; i < n ;i ++)
		scanf("%d" , &A[i]) , mp[A[i]] = i;
	vector< int > res;

	while(q --){
		int t , x;
		scanf("%d%d" , &t , &x);
		if(t == 1){
			res.push_back(A[x - 1]);
			sort(res.rbegin() , res.rend());
			while(res.size() > m)
				res.pop_back();
		}
		else {
			bool in = 0;
			for(int i = 0 ;i < res.size() ;i ++) if(mp[res[i]] == x - 1)
				in = 1;
			if(in)puts("YES");
			else puts("NO");
			
		}
		
	
	}
	
	
}
