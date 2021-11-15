// BOJ_1316 그룹 단어 체커
// [성공]

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, cnt = 0;
    char temp_c;
    vector<int> v(26); // check array
    cin >> N ;
    for(int i=0; i<N; i++){
        string temp;
        cin >> temp;
        for(int j=0; j<temp.length(); j++){
            if(j==temp.length()-1){
                cnt++;
                break;
            }
            temp_c = temp[j];
            if(temp_c!=temp[j+1]){
                if(v[(int)(temp[j+1]-'a')]==1) {
                    break;
                }
                v[(int)(temp_c-'a')] = 1;
            }
        }
        v.clear();
        v.assign(26,0);
    }
    cout << cnt;
}