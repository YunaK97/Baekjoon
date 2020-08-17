#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

int dist[20001];
int main(){
//	freopen("1753.txt","r",stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int V,E;
	cin>>V>>E;
	int start;
	cin>>start;
	vector<pair<int,int>> arr[V+1]; //2차원 배열 
	for(int i=0;i<E;i++){
		int from,to,val;
		cin>>from>>to>>val;
		arr[from].push_back({to,val});
	}
	fill(dist,dist+V+1,INF); 
	priority_queue<pair<int,int>> pq; //거리, 현재노드 
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
	for(int i=1;i<=V;i++){
		if(dist[i]>=INF)
			cout<<"INF"<<'\n';
		else
			cout<<dist[i]<<'\n';
	}
	
}
