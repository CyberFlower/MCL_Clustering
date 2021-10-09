#include <stdio.h>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;

const int SZ=15;

matrix operator *(const matrix &m1, const matrix &m2){
    matrix res(SZ,vector<int>(SZ,0));
    for(int i=0;i<SZ;i++){
        for(int j=0;j<SZ;j++){
            for(int k=0;k<SZ;k++){
                res[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    return res;
}

matrix operator ^(const matrix &m1, const matrix &m2){
    matrix res(15);
}

int main(int argc, char **argv){

    return 0;
}