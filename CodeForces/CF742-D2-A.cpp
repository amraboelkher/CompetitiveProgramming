#include<bits/stdc++.h>
using namespace std;
int get(int a ,  int b){
	if(b == 0) return 1;
	if(b == 1)return a % 10;
	int x = get(a , b / 2) % 10;
	x = x * x % 10;
	if(b & 1)
		x = (x * a) % 10;
	return x;
}
int main(){

	int n ;
	cin >> n;

	cout << get(1378 , n)  << endl;


}
