// BOJ_1057 토너먼트
// [성공]
// 수학, 브루트포스

#include <iostream>
#include <cstdlib>
using namespace std;

int N, J, H;

int ifSameNextRound(int n){
    if(n%2==1)
        return (n+1)/2;
    else
        return n/2;
}

void changeNum(){
    if(J%2==1)
        J = (J+1)/2;
    else
        J = J/2;
    if(H%2==1)
        H = (H+1)/2;
    else
        H = H/2;
}

void tournament(){
    int round = 1;
    while(true){
        if(ifSameNextRound(J)==ifSameNextRound(H)){
            cout << round;
            break;
        }
        changeNum();
        round++;
    }
}

int main(){
    cin >> N >> J >> H;
    tournament();
}