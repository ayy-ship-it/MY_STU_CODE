#include<iostream>

using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
LL n,m;
LL h[N];


//x表示锯子的高度 
bool check(LL x){
	LL sum = 0;
	for(int i = 1;i <= n;i++){
		sum += max(0LL,h[i] - x);
	}
	
	if(sum >= m) return true;
	return false;
}


int main(){
	cin >> n >> m;
	LL highest = 0;
	for(int i = 1;i <= n;i++){
		cin >> h[i];
		highest = max(highest,h[i]);
	}
	
	
	LL l = 0,r = highest;
	
	while(l + 1 < r){
		LL mid = l + r >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}	
	
	
	cout << l << endl;
	
	return 0;
}
