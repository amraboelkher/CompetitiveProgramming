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


class HowUnsorted {
public:
	void add(vector< int > &A , int idx){
		while(idx < A.size()){
			A[idx] ++;
			idx += (idx & -idx);
		}
	}
	int get(vector< int > &A , int idx){
		int ret = 0;
		while(idx > 0 ){
			ret += A[idx];
			idx -= (idx & -idx);
		}
		return ret;
	}
	long long howMany(int m, int c, int n) {
		vector< long long > A(n);
		vector< int > B(2 * n);
		A[0] = 1;
		for(int i = 1;i < n ;i ++)
			A[i] = (m * A[i - 1] + c) % ((1LL << 31) - 1);
		map< long long , int > mp;
		for(int i = 0 ;i < n ;i ++)
			mp[A[i]];
		int cnt = 0;
		for(auto &no : mp)
			no.second = ++cnt;
		long long ret = 0;
		for(int i = n - 1; i >= 0 ;i --){
			ret += get(B , mp[A[i]] - 1);
			add(B , mp[A[i]]);
		}
		return ret;
	}
};
