
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n , a , b;
    while(scanf("%d" , &n) && n){
        scanf("%d%d" , &a , &b);
        unordered_map< int , int > mp;
        int cur = 0;
        while(++ mp[cur] != 3){
            cur = ( ( ( (cur * 1LL * cur) % n) * a) + b ) % n;
        }
        int x = 0 , y = 0;
        for(unordered_map< int , int > ::iterator it = mp.begin() ; it != mp.end() ; it ++){
            if(it -> second >= 2)
                y ++;
        }
        printf("%d\n" , n - y);
    }
}
