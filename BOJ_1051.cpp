// BOj_1051 숫자 정사각형
// [성공]

#include <iostream>
using namespace std;

int map[51][51];
int N, M;

int solve(){
    int maxnum = max(N, M);
    int maxsize = 1;
    for(int i=1; i<maxnum; i++){
        for(int r=0; r<N; r++){
            for(int c=0; c<M; c++){
                if(r+i<N && c+i<M){
                    if((map[r][c] == map[r+i][c]) && (map[r+i][c] == map[r][c+i]) && (map[r][c+i] == map[r+i][c+i]) && (map[r+i][c+i] == map[r][c]))
                        maxsize = i+1;
                }
            }
        }
    }
    return maxsize*maxsize;
}

void input(){
    cin >> N >> M;
    for(int r=0; r<N; r++){
        string temp;    //댑악
        cin >> temp;
        for(int c=0; c<M; c++){
            map[r][c] = temp[c] - '0';
        }
    }
}

int main(){
    input();
    cout << solve() << '\n';
}