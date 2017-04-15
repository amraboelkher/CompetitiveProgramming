#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , m;
	scanf("%d%d" , &n , &m);
	vector< int > mp(32);
	vector< int > A(m);
	for(int i = 0 ;i < n ;i ++){
		int no;
		scanf("%d" , &no);
		for(int ii = 0 ; ii < 31; ii ++)if( no & (1 << ii) )
			mp[ii] ++ ;
	}
	for(int i = 0 ;i < m ;i ++)
		scanf("%d" , &A[i]);
	sort(A.begin() , A.end());
	int res = 0;
	for(int i = 0 ;i < A.size() ;i ++){
		for(int ii = A[i] ; ii < 31 ; ii ++) if(mp[ii] > 0){
			res ++;
			mp[ii] --;
				for(int iii = A[i] ; ii != A[i] && iii < ii ; iii ++) 
					mp[iii] ++; 

			break;
		}
	}
	printf("%d\n" , res);
	
}
