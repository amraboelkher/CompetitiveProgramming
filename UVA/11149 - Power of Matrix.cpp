#include<bits/stdc++.h>
using namespace std;
typedef vector< vector< int > > matrix;
int n , k;
matrix I;
matrix operator * (const matrix &F ,const matrix &S){
    matrix res(n , vector< int > (n , 0) );
    for(int i = 0 ;i < n ;i ++)
        for(int l = 0 ; l < n ;l ++)
            for(int k = 0; k < n ;k ++){
                res[i][l] = (res[i][l] + F[i][k] * S[k][l]) % 10;
            }
    return res;
}
matrix operator ^ (matrix base , int power){
    matrix res(n , vector< int > (n) );
    for(int i = 0 ;i < n ;i ++)
        res[i][i] = 1;
    for(int i = power ; i > 0 ; i >>= 1){
        if(i & 1) res = res * base;
        base = base * base;
    }
    return res;
}
matrix operator + (const matrix &A , const matrix &B ){
    matrix ret(n , vector< int > (n) );
    for(int i = 0 ;i < n ;i ++)
        for(int l = 0 ; l < n ;l ++){
            ret[i][l] = (A[i][l] + B[i][l]) % 10;
        }
    return ret;

}
matrix get(matrix base , int k){
    if(k == 1)
        return base;
    int k2 = k / 2;
    matrix tmp = get(base , k2) * (I + (base ^ k2) );
    if(k & 1)
        tmp = tmp + (base ^ k);
    return tmp;
}

//s(4) = A + A^2 + A^3 + A^4
//s(4) = (A + A^2) * (I + A + A^2)
//s(4) = A + A^2 + A^3 + A^2 + A^3 + A^4
//s(4) = A + 2 A^2 + 2 A^3 + A^4
//
//s(2) = A + A^2
//s(1) = A
//
//s(2) = s(1) * (I + A)
//s(2) = A + A^2
//
//s(4) = s(2) * (I + A^2)
//s(4) = (A + A^2) * (I + A^2)
//s(4) = A + A^3 + A^2 + A^4


int main(){
//    freopen("in.in" , "r" , stdin);
    while(scanf("%d%d" , &n , &k) && n > 0){
        matrix base(n , vector< int > (n));
        I = base;
        for(int i = 0; i < n ;i ++ )
            for(int l = 0 ;l < n ;l ++){
                scanf("%d" , &base[i][l]) ;
                I[i][i] = 1 , base[i][l] %= 10;
            }
        matrix ret = get(base , k);
        for(int i = 0 ;i < n ;i ++){
            for(int l = 0; l < n ;l ++){
                if(l)printf(" ");
                printf("%d" , ret[i][l]);
            }
            printf("\n");
        }
        printf("\n");
    }

}
