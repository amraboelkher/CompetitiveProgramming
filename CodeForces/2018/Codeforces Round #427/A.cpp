#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.in" , "r" , stdin);
	int s , v1 , v2 , t1 , t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int tot1 = v1 * s + 2 * t1;
	int tot2 = v2 * s + 2 * t2;
	if(tot1 < tot2)
		cout << "First" ;
	else if(tot1 > tot2)
		cout << "Second";
	else cout << "Friendship";
}
