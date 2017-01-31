#include<bits/stdc++.h>
using namespace std;

class MagicalGirl {
public:

	vector< pair< int , pair< int , int > > > A;
	int M;
	double dp[60][100003];
	bool vis[60][100003];
	int fix(int x){
        x = min(x , M);
        return x;
	}
	double rec(int idx , int lifePoints ){
		if(idx == A.size() || lifePoints <= 0){
			return lifePoints + A[idx].first;
        }
		double &ret = dp[idx][lifePoints];
		if(vis[idx][lifePoints])return ret;
		vis[idx][lifePoints] = 1;
		ret = 0.0;
		int nday = (A[idx + 1].first - A[idx].first);
		double p = A[idx].second.second / 100.0 ;
		int w = A[idx].second.first;
		ret = p * rec(idx + 1 , fix(lifePoints + w) - nday) + ( 1 - p ) * A[idx].first;
		ret = max(ret , rec(idx + 1 , lifePoints - nday) );
		return ret;
	}

	double maxExpectation(int _M, vector <int> day, vector <int> win, vector <int> gain) {
		A.clear();
		M = _M;
		for(int i = 0 ;i < win.size() ;i ++)
			A.push_back(make_pair(day[i] , make_pair(gain[i] , win[i]) ) );
        A.push_back(make_pair(1 , make_pair(0 , 0) ) );
        sort(A.begin() , A.end());
        A.push_back(make_pair(A.back().first , make_pair(0 , 0) ) ) ;

		memset(vis , 0 , sizeof vis);
		return rec(0 , _M - 1);

	}
};
int main(){

}
