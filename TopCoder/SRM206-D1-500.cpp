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


class SensorGrid {
public:
	vector <int> largestRectangle(int width, int height, vector <int> x, vector <int> y) {
		vector< pair< int , int > > p;
		vector< long long > res;
		for(int i = 0 ;i < x.size() ;i ++)
			p.push_back({x[i] , y[i]});
		x.push_back(-1) ; x.push_back(width) ; sort(x.begin() , x.end());
		y.push_back(-1) ; y.push_back(height); sort(y.begin() , y.end());
		for(int i = 0 ;i < x.size() ;i ++){
			for(int ii = i + 1; ii < x.size() ;ii ++){
				for(int l = 0 ;l < y.size() ;l ++){
					for(int ll = l + 1; ll < y.size() ;ll ++){
						int x1 = x[i] , y1 = y[l];
						int x2 = x[ii] , y2 = y[ll];
						int w = x2 - x1 - 1 , h = y2 - y1 - 1;
						if(w < 0 || h < 0) continue;
						bool in = 0;
						for(int iii = 0 ; iii < p.size() ; iii ++){
							if(p[iii].first > x1 && p[iii].first < x2 && p[iii].second > y1 && p[iii].second < y2)
								in = 1;
						}
						if(in)continue;
						vector< long long > tmp;
						tmp.push_back(-w*1LL*h);
						tmp.push_back(y1 + 1);
						tmp.push_back(x1 + 1);
						tmp.push_back(-w);
						tmp.push_back(-h);
						if(res.size() == 0 || tmp < res)
							res = tmp;
						
					}
				}
			}
		}
		return {res[2] , res[1] , -res[3] , -res[4]}; 
	}
	
};
