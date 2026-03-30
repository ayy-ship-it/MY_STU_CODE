#include<iostream>

using namespace std;
int n;
int a[4];
int nums[10010] = {6,2,5,5,4,5,6,3,7,6};
int ret = 0;


int cal(int num){
	if(nums[num]) return nums[num];
	
	int sum = 0;
	while(num){
		sum += nums[num%10];
		num /= 10;
	}
	return sum;
}

void dfs(int pos,int sum){
	
	if(sum > n-4) return;
	
	if(pos > 3){
		
		if(a[1] + a[2] == a[3] && sum == n - 4){
			ret++; 
		}
		
		return ;
	}
	
	
	
	for(int i = 0;i <= 1000;i++){
		a[pos] = i;
		dfs(pos+1,sum+cal(i));
		a[pos] = 0;
	}
}



int main(){
	cin >> n;
	dfs(1,0);	
	cout << ret; 
	return 0;
}
