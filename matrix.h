#include <vector>
#include <stdio.h>
#include "common.h"s

using namespace std;

typedef vector<vector<long double>> matrix;

//Expansion operation uses M_exp=M*M
matrix operator *(const matrix &m1, const matrix &m2){
    matrix res(NODE_SIZE,vector<long double>(NODE_SIZE,0));
    for(int i=0;i<NODE_SIZE;i++){
        for(int j=0;j<NODE_SIZE;j++){
            for(int k=0;k<NODE_SIZE;k++){
                res[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    return res;
}

matrix calc_inf(const matrix &m1){
    matrix res(NODE_SIZE,vector<long double>(NODE_SIZE,0));
    for(int i=0;i<NODE_SIZE;i++){
        for(int j=0;j<NODE_SIZE;j++){
            long double chi = m1[i][j]*m1[i][j];
            long double par = 0;
            for(int k=0;k<NODE_SIZE;k++){
                par += m1[k][j]*m1[k][j];
            }
            res[i][j]=chi/par;
        }
    }
    return res;
}

void print_matrix(const matrix &mat){
    for(int i=0;i<NODE_SIZE;i++){
        for(int j=0;j<NODE_SIZE;j++){
            printf("%Lf ",mat[i][j]);
        }
        printf("\n");
    }
}