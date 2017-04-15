#include<bits/stdc++.h>
using namespace std;
deque< int >x  , y;
int cal(vector < int > A , vector < int > B , int beg){	
	x.clear();
	y.clear();
	int cnt = 0;
	int start = 0;
	for(int i = beg; i < 10 ;i ++){
		if(A[i] && B[10 - i]){
			A[i] --;
			B[10 - i] --;
			x.push_front(i);
			y.push_front(10 - i);
			start = 1;
			cnt ++;
			break;
		}
	}
	if(!start)return -1;
	for(int i = 0 ; i < 10; i ++){
		while(A[i] && B[9 - i]){
			A[i] --;
			B[9 - i] --;
			x.push_front(i);
			y.push_front(9 - i);
			cnt ++;
		}
	} 
	while(A[0] && B[0]){
		A[0] --;
		B[0] --;
		x.push_back(0);
		y.push_back(0);
		cnt ++;
	}
	for(int i = 0 ;i < 10 ;i ++){
		while(A[i])
			x.push_front(i) , A[i] --;
		while(B[i])
			y.push_front(i) , B[i] --;
	}
	return cnt;
}
int main(){

	string s ;
	cin >> s;
	vector< int > A(10), B(10);
	for(int i = 0 ;i < s.size() ;i ++)
		A[s[i] - '0'] ++ , B[s[i] - '0'] ++;
	bool start = 0;
	for(int i = 1; i < 10 ;i ++){
		if(A[i] && B[10 - i])
			start = 1;
	}
	if(!start){
		sort(s.rbegin() , s.rend());
		cout << s << endl << s << endl;
	}
	else {
		deque< int > a , b;
		int res = 0;
		for(int i = 1; i < 10 ; i ++){
			int r = cal(A  , B , i);
			if(r > res){
				res = r;
				a = x;
				b = y;
			}
		}
		for(int i = 0 ;i < a.size() ;i ++)
			cout << a[i] ;
		cout << endl;
		for(int i = 0 ;i < b.size() ;i ++)
			cout << b[i];
		cout << endl;
	}
}
