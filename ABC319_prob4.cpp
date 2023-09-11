#include<bits/stdc++.h>
using namespace std;

int main(){
	long N, M;
	cin>>N>>M;
	vector<int> L(N);
	for(int i = 0; i < N; i++){cin>>L[i];}
	long max = *max_element(L.begin(), L.end());
	auto check = [&](long x)->bool{
		long row = 0;
		long col = 0;
		for(int i = 0; i < N; i++){
			row += L[i];
			if(row < x){
				row += 1;
			}else if(row == x){
				col++;
				row = 0;
			}else{
				col++;
				row = L[i] + 1;
			}
		}
		if(row>0)col++;
		if(col > M){
			return false;
		}else{
			return true;
		}
	};
	
	long left = max - 1;
	long right = max*N + N;
	while(right - left > 1){
		long mid = (left + right)/2;
		if(check(mid)) right = mid;
		else left = mid;
	}
	cout<<right<<endl;
}
