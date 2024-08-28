#include <bits/stdc++.h>
using namespace std;
vector<int> v(9);
int main(){
	for(int i = 0; i < 9; i++){
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(i == j) continue;
			
			int sum = 0;
			for(int k = 0; k < 9; k++){
				if(k != i && k != j) sum += v[k];
			}
			
			if(sum == 100){
				for(int k = 0; k < 9; k++){
					if(k != i && k != j){
						cout << v[k] << '\n';
					}
				}
				return 0;
			}
		}
	}
}