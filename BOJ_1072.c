// BOJ_1072 게임
// [성공_참고]
#include <stdio.h>
#define MAX 1000000000
int main(){
    long long X, Y;
    int Z, z;

    scanf("%lld %lld", &X, &Y);
    Z = (Y*100)/X;

    // 확률이 99% 이상이면 절대 바뀔 수 없음.(100%가, 그 이상이 될 수 없음)
    // X==Y라면과 동일한 조건.
    if(Z >= 99){
        printf("-1\n");
        return 0;
    }

    int left = 0, right = MAX;
    int result = -1;
    while(left<=right){
        int mid = (left + right)/2;
        z = ((Y+mid)*100)/(X+mid);
        if(Z>=z){
            // Z>=z인 시점에서 곧 결과가 이뤄질 것이므로
            result = mid+1;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    printf("%d", result);
    return 0;
}