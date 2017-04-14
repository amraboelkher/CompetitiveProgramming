#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class RangeGame {
public:
	int getNo(string s){
		int no = 0;
		for(int i = 0 ;i < s.size() ;i ++)
			no = (no * 10 + (s[i] - '0') );
		return no;
	}
	vector < pair< int , int > > parse( string s ){
		vector< pair< int , int > > A;
		stringstream S(s);
		while(S >> s){
			int idx = s.find("-");
			if(idx != string::npos){
				string a = s.substr(0 , idx);
				string b = s.substr(idx + 1);
				int _a = getNo(a) , _b = getNo(b);
				A.push_back({_a , _b});
			}
			else {
				int _a = getNo(s);
				A.push_back({_a , _a});
			}
		}
		return A;
	}
	vector< vector< pair< int , int > > > A;
	int get(){
		vector< pair< int , int > > R;
		for(int i = 0 ;i < A.size() ;i ++){
			for(int ii = 0 ;ii < A[i].size() ; ii ++){
				R.push_back({A[i][ii].first , 1});
				R.push_back({A[i][ii].second , 2});
			}
		}
		sort(R.begin() , R.end());
		map< int , int > mp;
		int mx = 0 , cnt = 0 , cur = 0;
		for(int i = 0 ;i < R.size() ;i ++){
			if(R[i].second == 1) cur ++;
			mp[R[i].first] = max(mp[R[i].first] , cur);
			if(mp[R[i].first] > cnt || (mp[R[i].first] == cnt && R[i].first < mx) )
				mx = R[i].first , cnt = mp[R[i].first];
			if(R[i].second == 2) cur --;
		}
		return mx;
	}
	bool isit(int a , int b , int c , int d){
		return ((a >= c && a <= d) || (b >= c && b <= d) );
	}
	void del(string s){
		vector< pair < int , int > > X = parse(s);
		vector< vector< pair< int , int > > > nA;
		for(int i = 0 ;i < A.size() ;i ++){
			bool in = 0;
			for(int ii = 0 ;ii < A[i].size() ;ii ++){
				for(int iii = 0 ;iii < X.size() ; iii ++){
					int a = A[i][ii].first , b = A[i][ii].second ;
					int c = X[iii].first , d = X[iii].second;
					if(isit(a , b , c , d) || isit(c , d , a , b) )
						in = 1;
					
				}
				
			}
			if(!in)nA.push_back(A[i]);
		}
		A = nA;
	}
	vector <int> bestDoors(vector <string> P, vector <string> H) {
		A.clear();
		for(int i = 0 ;i < P.size() ;i ++){
			vector< pair< int , int > > B = parse(P[i]);
			A.push_back(B);	
		}
		vector< int > res;
		res.push_back(get());
		for(int i = 0 ;i < H.size() ;i ++){
			del(H[i]);
			res.push_back(get());
		}
		return res;
		
	}
};


