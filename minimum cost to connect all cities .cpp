////.There are n cities and there are roads in between some of the cities. Somehow all the roads are damaged simultaneously. We have to repair the roads to connect the cities again. There is a fixed cost to repair a particular road. Find out the minimum cost to connect all the cities by repairing roads. Input is in matrix(city) form, if city[i][j] = 0 then there is not any road between city i and city j, if city[i][j] = a > 0 then the cost to rebuild the path between city i and city j is a. Print out the minimum cost to connect all the cities. 
////It is sure that all the cities were connected before the roads were damaged.
//
//
//
//
////The way to do that is to find out the Minimum Spanning Tree(MST) of the map of the cities
//(i.e. each city is a node of the graph and all the damaged roads between cities are edges). 
//And the total cost is the addition of the path edge values in the Minimum Spanning Tree.
















#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
struct edge {
	int a;
	int b;
	int w;
};
int par[10001];
edge arr[100000];
int find(int a){
	if(par[a]==-1)
	return a;
	return par[a]=find(par[a]);
}
void merge (int a,int b){
	par[a]=b;
}
bool cmp(edge a ,edge b){
	return a.w<b.w;
}
int findcost(int n,vector<vector<int> >city){
  for(int i=0;i<n;i++){
	par[i]=-1;
}
	int sum=0;
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		    if(i>j&&city[i][j]){
		    	arr[k].a=i;
		    	arr[k].b=j;
		    	arr[k].w=city[i][j];
		    	k++;
			}
				
			}
		}
		
		sort(arr,arr+k,cmp);
	for(int i=0;i<k;i++){
	 int a=find(arr[i].a);
	 int  b=find(arr[i].b);
	  if(a!=b){
	  	sum+=arr[i].w;
	  	merge(a,b);
	  }
}
	return sum;
}
int main(){

 int n1 = 5;
  vector<vector<int> > city1 = {{0, 1, 2, 3, 4},
                               {1, 0, 5, 0, 7},
                               {2, 5, 0, 6, 0},
                               {3, 0, 6, 0, 0},
                               {4, 7, 0, 0, 0}};
  int n2 = 6;
  vector<vector<int>> city2 = {{0, 1, 1, 100, 0, 0},
                               {1, 0, 1, 0, 0, 0},
                               {1, 1, 0, 0, 0, 0},  
                               {100, 0, 0, 0, 2, 2},
                               {0, 0, 0, 2, 0, 2}, 
                               {0, 0, 0, 2, 2, 0}};

 cout<<"\n"<<findcost(n2, city2);
return 0;}



