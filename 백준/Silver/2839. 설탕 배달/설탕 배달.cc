#include <bits/stdc++.h>
using namespace std;
int a, cnt;
int main(){
    cin >> a;
    while (a >= 0){
        if(a % 5 == 0){
            cnt += a/5;
            cout << cnt;
            return 0;
        }
        a-=3;
        cnt++;
    }
    cout << -1 ;
}