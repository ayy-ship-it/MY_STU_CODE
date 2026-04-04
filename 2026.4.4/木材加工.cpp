#include<iostream>
#include<algorithm>


using namespace std;
const int N = 1e5 + 10;
int n,k;
int a[N];

//x表示切取木头的长度,sum存能够得到的段数 
bool check(int x){
	int sum = 0;
	for(int i = 1;i <= n;i++){
		sum += a[i] / x;
	} 
	if(sum >= k) return true;
	return false;
}


int main(){
	cin >> n >> k;
	int highest = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		highest = max(highest,a[i]);
	}
	int l = 0,r = highest;
	
	while(l + 1 < r){
		
		int mid = l + r >> 1;
		
		if(check(mid)) l = mid;
		else r = mid;
	}
	
	cout << l << endl;
	
	
	return 0;
}

