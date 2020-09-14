#include<iostream>
#include<vector>
using namespace std;
int n,k;
int main(){
	freopen("11047_1.txt","r",stdin);
	cin>>n>>k;
	vector<int> v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	vector<int> dp(k+1);
	for(int i=1;i<=k;i++){
		dp[i]=-1;
		for(int j=1;j<=n;j++){
			if(i-v[j]>=0){
				if(dp[i-v[j]]<0)
					continue;
				if(dp[i]<0)
					dp[i]=dp[i-v[j]]+1;
				else if(dp[i]>dp[i-v[j]]+1)
					dp[i]=dp[i-v[j]]+1;
			}
		}
	}
	cout<<dp[k];
}
