#include<bits/stdc++.h>
using namespace std;
int main(){

    int n  , c ;
    cin >> n >> c;
    int cnt = 0 , cur = c;
    while(n && cur){
        if(n % 2 == 1){
            if(cur == 1)cur = 0;
            else if(cur == 0) cur = 1;
        }
        else {
            if(cur == 1)cur = 2;
            else if(cur == 2) cur =  1;
        }
        n --;
	
    }
    if(n && n % 2 == 0)
        n = max(0 , n - 1);
    int lp = (n) % 6 , x = 0;

    while(lp){
        if(lp % 2 == 1){
            if(cur == 1)cur = 0;
            else if(cur == 0) cur = 1;
        }
        else {
            if(cur == 1)cur = 2;
            else if(cur == 2)cur = 1;
        }
        lp --;
    }
    cout << cur << endl;


}
