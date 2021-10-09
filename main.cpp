#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "matrix.h"
#include "common.h"

using namespace std;

matrix markov;

void dfs(vector<int> &visit, matrix &dist, int x, long double current_possi, long double min_possi){
    if(current_possi<min_possi) return;
    visit[x]=1;
    for(int i=0;i<NODE_SIZE;i++){
        if(i==x) continue;
        int new_possi=current_possi*markov[x][i];
        if(dist[x][i]<new_possi && new_possi>=min_possi){
            dist[x][i]=new_possi;
            dfs(visit, dist,i,new_possi,min_possi);
        }
    }
}

bool check_converge(long double possi, int c){
    int count=0;
    matrix dist(NODE_SIZE,vector<long double>(NODE_SIZE,0));
    vector<int> visit(NODE_SIZE,0);
    for(int i=0;i<NODE_SIZE;i++){
        if(visit[i]) continue;
        dfs(visit, dist,i,1.0,possi);
        count++;
    }
    return count<=c;
}

void print_usage(int argc, char **argv){
    cout<<"usage: cluster.exe [matrix input text file] [matrix cluster count] [maximum possibility]"<<'\n';
    cout<<"example: cluster.exe markov_matrix.txt 10 0.5"<<'\n';
}

int main(int argc, char **argv){
    if(argc!=4){
        print_usage(argc, argv);
        return 0;
    }
    int c=stoi(argv[2]);
    long double possi=stold(argv[3]);

    markov.resize(NODE_SIZE);
    FILE *fp=freopen(argv[1],"r",stdin);
    if(fp==NULL){
        print_usage(argc, argv);
        return 0;
    }
    for(int i=0;i<NODE_SIZE;i++){
        markov[i].resize(NODE_SIZE);
        for(int j=0;j<NODE_SIZE;j++){
            cin>>markov[i][j];
        }
    }
    fclose(fp);

    while(true){
        markov=markov*markov;   // expansion
        markov=calc_inf(markov);   // inflation
        if(check_converge(possi,c)){
            print_matrix(markov);
            break;
        }
    }

    return 0;
}