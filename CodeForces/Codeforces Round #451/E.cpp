#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e9;
int main(){
	freopen("in.in" , "r" ,  stdin);
	set< long long > S;
	int last = -1;
	for(int i = 0; i *1LL* i <= MAXN; i ++){
		S.insert(i * 1LL* i);
		last = i;
	}
	last ++;
	S.insert(last * 1LL * last);
	

	int n ;
	scanf("%d" , &n);
	vector< int > A , sq;
	for(int i = 0 ;i < n ;i ++){
		int no;
		scanf("%d" , &no);
		if(S.count(no)){
			sq.push_back(no);
		}
		else A.push_back(no);
	}
	sort(sq.begin() , sq.end() );
	sort(A.begin() , A.end() );
	long long ret = 0;
	vector< pair< long long , int > > dif , toNot;// to get req sq
	vector< int > extra;
	if(sq.size() > n / 2){
		for(int i = 0; i < sq.size() ;i ++){
			int no = sq[i];
			if(no > 2){
				dif.push_back({1 , no + 1});
			}
			else {
				dif.push_back({2 - no , 2});
			}
		}
		sort(dif.begin() , dif.end() );
		for(int i = 0 ;i < dif.size() && A.size() < n / 2 ;i ++){
			ret += dif[i].first;
			A.push_back(dif[i].second);	
		}
		
	}
	else if(sq.size() < n / 2){

		for(int i = 0 ;i < A.size() ;i ++){
			int no = A[i];
			auto nxt = S.upper_bound(no);
			auto before = nxt;
			before --;
			int DIFN = MAXN + 1;
			int DIFB = MAXN + 1;
			if(nxt != S.end()){
				DIFN = *nxt - no;
			}
			DIFB = no - *before;
			dif.push_back({min(DIFB , DIFN) , no}); 
		}
		sort(dif.begin() , dif.end() );
		for(int i = 0 ;i < dif.size() && sq.size() < n / 2 ; i ++){
			ret += dif[i].first;
			sq.push_back(dif[i].second);
		}
	}
	cout << ret<< endl;
	
}
