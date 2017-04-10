#include<bits/stdc++.h>
using namespace std;
int main(){
	deque< pair< int , bool > > q;
	int n , m;
	scanf("%d%d" , &n , &m);
	vector< int > A(n + 1 , 1);
	set< int > tillNow;

	for(int i = 0 ;i < m ;i ++){
		int x;
		char c[10];
		scanf("%s%d" , &c , &x);
		A[x] = 0;
		if(c[0] == '+'){
			tillNow.insert(x);
			q.push_back({x , 1});
		}
		else {
			if(tillNow.count(x) == 0)
				q.push_front({x , 1});
			else tillNow.erase(x);
			q.push_back({x , 0});
		}
	}
	if(q.size() && q.front().second){
		int x = q.front().first , tmp = x;
		int t = q.front().second;
		tillNow.clear();
		A[x] = 1;
		while(q.size()){
			x = q.front().first ;
			t = q.front().second;
			q.pop_front();
			if(t == 1){
				tillNow.insert(x);
				A[tmp] &= tillNow.count(tmp);
			}
			else 
				A[x] &= tillNow.size() == 1 , tillNow.erase(x);
		}
	}
	int sz = 0;
	for(int i = 1;i < A.size() ;i ++)
		sz += A[i];
	printf("%d\n" , sz);
	for(int i = 1; i < A.size() ;i ++) if(A[i])
		printf("%d " , i);
	return 0;
}
