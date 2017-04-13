#include<bits/stdc++.h>
using namespace std;
int main(){

	int n , m;
	int T =  0;
	while(scanf("%d" , &n) && n ){
		vector< pair<int , int > > A;
		multiset< int > B[101];
		multiset< int > ::iterator it , it1;
		long long ansN = 0 , ansE = 0;
		for(int i = 0 ;i < n ;i ++){
			int a , b;
			scanf("%d %d" , &a , &b);
			B[a].insert(b);
			ansN ++ , ansE += a;
		}


		scanf("%d" , &m);
		A.resize(m);
		for(int  i = 0; i < m; i ++){
			int a , h , m1;
			scanf("%d %d:%d" , &a , &h , &m1);
			int no = 60 * (h - 14) + m1;
			A[i] = make_pair(a , no);
		}
		sort(A.begin() , A.end() , [](pair< int , int >&a , pair<int , int> &b){ 
				return (a.second < b.second || (a.second == b.second && a.first < b.first) ) ; } );
				

		// trying to  match the largest number of students who have the smallest required time first 
		// with the smallest allocated time matching the required number too :D 
		for(int i = 0; i < A.size() ;i ++){
			int no = A[i].first , tm = A[i].second;
			int mnT = 1e9 , from = -1;
			for(int l = no ; l > 0 ; l --) {
				it = B[l].begin();
				if(B[l].size() > 0 && *it <= tm){
					ansN -- , ansE -= l;
					B[l].erase(B[l].begin());
					break;
				}
			}

		}
		printf("Trial %d: %lld %lld\n\n" , ++T , ansN , ansE);
		
	
	}

}
