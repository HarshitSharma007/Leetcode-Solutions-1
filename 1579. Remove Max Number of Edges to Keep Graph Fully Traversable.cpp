//.1579. Remove Max Number of Edges to Keep Graph Fully Traversable
//Hard
//
//323
//
//3
//
//Add to List
//
//Share
//Alice and Bob have an undirected graph of n nodes and 3 types of edges:
//
//Type 1: Can be traversed by Alice only.
//Type 2: Can be traversed by Bob only.
//Type 3: Can by traversed by both Alice and Bob.
//Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.
//
//Return the maximum number of edges you can remove, or return -1 if it's impossible for the graph to be fully traversed by Alice and Bob.
//
// 
//
//Example 1:
//
//
//
//Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
//Output: 2
//Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
//Example 2:
//
//
//
//Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
//Output: 0
//Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
//Example 3:
//
//
//
//Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
//Output: -1
//Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
// 
//
// 
//
//Constraints:
//
//1 <= n <= 10^5
//1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
//edges[i].length == 3
//1 <= edges[i][0] <= 3
//1 <= edges[i][1] < edges[i][2] <= n
//All tuples (typei, ui, vi) are distinct.



class Solution {
public:

    int alice[100001];
    int bob[100001];
  
int finda(int a){
	if(alice[a]==-1)
	return a;
	return alice[a]=finda(alice[a]);
}
    int findb(int a){
	if(bob[a]==-1)
	return a;
	return bob[a]=findb(bob[a]);
}
void mergea (int a,int b){
	alice[a]=b;
}
    void mergeb (int a,int b){
	bob[a]=b;
}
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        for(int i=0;i<100001;i++){
	alice[i]=-1;
            bob[i]=-1;
}   
     int t3=0;
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==3){
                if(finda(edges[i][1])!=finda(edges[i][2])){
                   mergea(finda(edges[i][1]),finda(edges[i][2]));
                   mergeb(findb(edges[i][1]),findb(edges[i][2]));
                    t3++;
                }
            }
        }
        int t1=0;
         for(int i=0;i<edges.size();i++){
            if(edges[i][0]==1){
                if(finda(edges[i][1])!=finda(edges[i][2])){
                    mergea(finda(edges[i][1]),finda(edges[i][2]));
                    
                    t1++;
                    cout<<"I"<<i<<" ";
                }
            }
        }
        int t2=0;
         for(int i=0;i<edges.size();i++){
            if(edges[i][0]==2){
                if(findb(edges[i][1])!=findb(edges[i][2])){
                    mergeb(findb(edges[i][1]),findb(edges[i][2]));
                    
                    t2++;
                }
            }
        }
   if(t1+t3<n-1||t3+t2<n-1)
       return -1;
        
        cout<<t1<<" "<<t2<<" "<<t3<<endl;
      return edges.size()-t1-t2-t3;
    }
};

// yrrr agar yeh code smjhna he toh bsss sbse phle type third nodes count krrro jo essential he unse alice ka par array aur bob ka par array dono modify honge but in case of type 1 node we only modify alice array in second for loop then we run last loop for bob 
// so t1 +t2+t3 are all the essential nodes we can get 
//so answer is total -(essential);------------------:)
