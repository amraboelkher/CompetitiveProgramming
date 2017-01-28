#include<bits/stdc++.h>
using namespace std;
char S[50][50];
double  A[50][50];
int main()
{
//    freopen("in.in" , "r" , stdin);
    string s;
    int N = 16;
    for(int i = 0 ; i < N ;i ++ ){
        scanf("%s" , S[i]) ;
        s = S[i] ;
    }
    for(int i = 0 ;i < N ;i ++)
        for(int l = 0; l < N ;l ++)
            scanf("%lf" , &A[i][l]) , A[i][l] /= 100.0;
    vector< double > res(N , 1.0);
    for(int lvl = 1 , k = 1; lvl < 5; lvl ++ , k *= 2){
        int idx = 0 ;
        vector< double > nres(N , 0.0);

        while(idx < N){
            for(int i = idx; i < idx + k; i ++){
                for(int l = idx + k ; l < idx + 2 * k ;l ++){

                    nres[i] += res[i] * res[l] * A[i][l];
                    nres[l] += res[l]  * res[i] *  A[l][i];
                }
            }
            idx += 2 * k;
        }
        res = nres;
    }
    for(int i = 0 ;i < N; i ++){
        string s = S[i];
        while(s.size() < 10)s += " ";
        printf("%s p=%0.2lf%\n" , s.c_str() , 100.0 * res[i]);
    }
}

