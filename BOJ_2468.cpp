// BOJ_2468 안전 영역
// [성공_참고]
// DFS함수는 방문 여부만 탐색하여 기록해주는 역할을 함

#include <iostream>
#include <cstring>
using namespace std;

int map[101][101], isVisited[101][101]={1}; // 방문하면 1, 안방문했으면 0
int N, maxheight = 0; // 입력 높이 중 최대 높이
int row[4] = {1, 0, -1, 0};
int col[4] = {0, -1, 0, 1};

void DFS(int r, int c){
    isVisited[r][c] = 1;
    for(int i=0; i<4; i++){
        int t_r = r + row[i];
        int t_c = c + col[i];

        if(0<=t_r && t_r<N && 0<=t_c && t_c<N){ // 범위를 벗어나지 않고
            if(!isVisited[t_r][t_c] && map[t_r][t_c]>0) // 방문한 적이 없으며, 살아남은 지역이라면
                DFS(t_r, t_c); // 깊이우선탐색 다시 시작
        }
    }
}

void input(){
    cin.tie(NULL); 
    cin.sync_with_stdio(false);
    cin >> N;
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            cin >> map[r][c];
            if(map[r][c] > maxheight)
                maxheight = map[r][c];  // 최대 높이 갱신
        }
    }
}

int solve(){
    int maxsum = 1;
    for(int i = 1; i<=maxheight; i++){
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                if(map[r][c]<=i)
                    map[r][c] = 0;
            }
        }

        int t_sum = 0;
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                if(!isVisited[r][c]){ // 방문했던 적이 없고(maxsum에 카운트되지 않고)
                    if(map[r][c]>0){ // 살아남은 지역이라면
                        t_sum++;
                        DFS(r,c);
                    }
                }
            }
        }
        maxsum = max(maxsum, t_sum);
        memset(isVisited, 0, sizeof(isVisited)); 
    }
    return maxsum;
}

int main(){
    input();
    cout << solve() << '\n';
}