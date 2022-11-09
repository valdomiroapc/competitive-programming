#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<vector<int>> matrix_int;
matrix_int matrix_product(matrix_int a,matrix_int b,long long int m){
    matrix_int ans;

    for(int i=0;i<a.size();i++){
        ans.pb({});
        for(int j=0;j<b[0].size();j++){
            ans.back().pb({});
            for(int k=0;k<b.size();k++){
                ans.back().back() =(ans.back().back()%m + (a[i][k]%m * (b[k][j]%m))%m)%m;
            }
        }
    }

    return ans;
}
matrix_int fast_matrix_pow(matrix_int x, long long int e, long long int m){
    if(e==0)
        return {{1,0},{0,1}};
    if(e==1)
        return x;
    if(e%2)
        return matrix_product(x, fast_matrix_pow(matrix_product(x,x,m), e/2,m),m);
    return fast_matrix_pow(matrix_product(x,x,m), e/2,m);
}
int main(){
    long long int n,m;
    while(cin>>n>>m){
        matrix_int M = fast_matrix_pow({{1,1},{1,0}},n,1<<m);
        matrix_int obj = matrix_product(M,{{1},{0}},1<<m);
        cout<<obj[1][0]<<endl;
    }
}
