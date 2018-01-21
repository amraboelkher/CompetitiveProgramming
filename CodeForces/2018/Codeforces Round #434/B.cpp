#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.in" , "r" , stdin);
	int n , m;
	cin >> n >> m;
	vector< int > N(m) , F(m);
	for(int i = 0 ;i < m ;i ++)
		cin >> N[i] >> F[i];
	int ret = -1;
	for(int i = 1; i < 101 ;i ++){
		int floors = i;
		int expN = (n + floors - 1) / floors;
		bool valid = 1;
		for(int ii = 0 ;ii < m ;ii ++){
			int exp = (N[ii] + floors - 1) / floors;
			if(exp != F[ii])
				valid = 0;
		}
		if(valid){
			if(ret == -1)
				ret = expN;
			else if(ret != expN){
				ret = -1;
				break;
			}
		}
	}
	cout << ret << endl;
}
