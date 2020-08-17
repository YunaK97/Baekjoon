#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;
int dist[1001];
int main(){
	//freopen("1916.txt","r",stdin);
	int N,M;
	cin>>N>>M;
	vector<pair<int,int>> arr[N+1];
	for(int i=1;i<=M;i++){
		int from,to,cost;
		cin>>from>>to>>cost;
		arr[from].push_back({to,cost});
	}
	int start,end;
	cin>>start>>end;
	fill(dist,dist+N+1,INF);
	priority_queue<pair<int,int>> pq; //거리, 현재점 
	pq.push({0,start});
	dist[start]=0;
	 
	while(!pq.empty()){
		int cost=pq.top().first;
		int now=pq.top().second;
		pq.pop();
		for(int i=0;i<arr[now].size();i++){
			int next=arr[now][i].first;
			int ncost=arr[now][i].second;
			if(dist[next]>dist[now]+ncost){
				dist[next]=dist[now]+ncost;
				pq.push({-dist[next],next});
			}
		}
	}
	cout<<dist[end];
} 
