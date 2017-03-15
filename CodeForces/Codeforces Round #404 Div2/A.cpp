#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 3;
int main(){

	map<string , int > mp;
	mp["Icosahedron"] = 20;
	mp["Dodecahedron"] = 12;
	mp["Octahedron"] = 8;
	mp["Cube"] = 6;
	mp["Tetrahedron"] = 4;
	string  s; 
	int n  , res = 0;
	cin >> n ;
	for(int i = 0; i < n ;i ++){
		cin >> s;
		res += mp[s];
	}
	cout << res << endl;
		

}
