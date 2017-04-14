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


class WeirdSort {
public:
	void push(vector< int > &A , int no , int n){
		for(int i = 0 ;i < n ;i ++)
			A.push_back(no);
	}
	vector <int> sortArray(vector <int> data) {
		vector< int > cnt(1001) , res;
		sort(data.begin() , data.end());
		do{
			for(auto it = data.begin() ; it != data.end() ; it ++){
				if(res.size() && res.back() + 1 == *it) continue ;
				if(data.front() == *it && data.back() == *it + 1) continue;
				res.push_back(*it);
				data.erase(it);
				break;
			}
		}while(data.size());
		return res;
	}
};

