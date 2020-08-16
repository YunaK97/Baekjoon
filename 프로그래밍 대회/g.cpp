#include<bits/stdc++.h>
using namespace std;

int n,m;
vector< pair<long long,long long> > vMoney;
vector< pair<long long,int> > vPharm;

int main(void){
	ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
	freopen("g.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		long long a,b;
		cin>>a>>b;
		vMoney.push_back( make_pair(a,b) ); //Min~Max 마스크값 입력 
	}
	
	for(int j=0;j<m;j++){
		long long a,b;
		cin>>a>>b;	
		vPharm.push_back( make_pair(a,b) );
	}
	sort(vMoney.begin(),vMoney.end());
	sort(vPharm.begin(),vPharm.end());

	int monLen=vMoney.size(),pharmLen=vPharm.size();
	int ans=0;
	int i=0,j=0;

	while(i<pharmLen){
		if(j>=monLen)break;
		long long cost=vPharm[i].first;
		if(vPharm[i].second==0){
			i++;
			continue;	
		}
		long long Min=vMoney[j].first,Max=vMoney[j].second;
		if(Min<=cost && cost<=Max){
			ans++;
			vPharm[i].second--;
			j++;
		}else if(cost<Min){
			i++;
		}else if(Max<cost){
			break;
		}
	}
	cout<<ans;
	return 0;
}
