// BOJ_1063 킹
// [성공]
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string D, K, tmp;
    int N, dl, dc, kl, kc;
    vector<string> v;
    // 이동 과정을 계산할 때 쓰일 배열 (열(x), 행(y))
    // R, L, B, T, RT, LT, RB, LB
    int ax[8] = {0, 0, 1, -1, -1, -1, 1, 1};
    int ay[8] = {1, -1, 0, 0, 1, -1, 1, -1};



    // 초기값 입력받기
    cin >> K >> D >> N;

    // 이동 과정 입력받기
    for(int i=0; i<N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    // 돌과 킹의 초기 인덱스 구하기
    // 돌 : (dc, dl)  킹 : (kc, kl)
    dl = D[0] - 'A';
    dc = '8' - D[1];
    kl = K[0] - 'A';
    kc = '8' - K[1];

    for(int i=0; i<N; i++){
        // 이동한 위치를 구하기 쉽도록 인덱싱
        int index;
        if(v[i]=="R") index = 0;
        else if(v[i]=="L") index = 1;
        else if(v[i]=="B") index = 2;
        else if(v[i]=="T") index = 3;
        else if(v[i]=="RT") index = 4;
        else if(v[i]=="LT") index = 5;
        else if(v[i]=="RB") index = 6;
        else if(v[i]=="LB") index = 7;

        // 임시 공간에 킹 위치 임시로 계산
        int t_kc = kc + ax[index];
        int t_kl = kl + ay[index];

        // 임시로 계산한 값이 범위를 벗어나면 그 경우는 건너뜀
        if(t_kc == -1 || t_kc == 8 || t_kl == -1 || t_kl == 8) continue;

        // 만약 킹을 옮겼는데 돌 위치와 겹쳤다면?
        if(t_kc == dc && t_kl == dl){
            // 임시 공간에 돌 위치 임시로 계산
            int t_dc = dc + ax[index];
            int t_dl = dl + ay[index];
            // 임시로 계산한 값이 범위를 벗어나면 그 경우는 건너뜀
            if(t_dc == -1 || t_dc == 8 || t_dl == -1 || t_dl == 8) continue;
            
            // 돌이 범위를 벗어나지 않으면 fix
            dc = t_dc; dl = t_dl;
        }
        // 킹의 위치 fix
        kc = t_kc; kl = t_kl;
    }

    // 출력
    cout << (char)(kl+'A') << 8-kc << endl;
    cout << (char)(dl+'A') << 8-dc << endl;
    return 0;
}
