#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 3;
char s[MAXN];
vector< int > P(string &S){
    vector< int > A(S.size());
    int len = 0;
    for(int i = 1;i < A.size() ;i ++){
        while(len && S[len] != S[i])
            len = A[len - 1];
        if(S[len] == S[i])
            len ++;
        A[i] = len;
    }
    return A;
}
int get(string &s , string &p){
    vector< int > A = P(p);
    int len = 0;
    int mx = 0;
    for(int i = 0; i < s.size() ;i ++){
        while(len && s[i] != p[len])
            len = A[len - 1];
        if(s[i] == p[len])
            len ++;
    }
    return len;
}
int main()
{
    while(~scanf("%s" , s)){
        string S = s , rS = s , res = "";
        reverse(rS.begin() , rS.end());
        int x = get(S , rS);
        res = S.substr(0 , S.size() - x);
        reverse(res.begin() , res.end());
        S  += res;
        printf("%s\n" , S.c_str());
    }
}
