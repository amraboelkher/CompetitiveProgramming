#include<bits/stdc++.h>
using namespace std;
int main(){

	int a , b , c;
	cin >> a >> b >> c;
	int res = 0;
	for(int i = 1; i <= a; i ++){
		if(2 * i <= b && 4 * i <= c)
			res = i;
	}
	cout << res + 2 * res + 4 * res << endl;
}
