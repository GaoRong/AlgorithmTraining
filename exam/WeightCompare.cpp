/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-11 16:40:07
** desc：  https://www.nowcoder.com/questionTerminal/ac27e60e63b549d6a9b59f815d9bc6e2
*********************************************************************************/

//思路一: 首先构造有向图，其中方向标识大到小，然后利用Floyd算法构造完整的层次关系
class Cmp {
public:
    int cmp(int g1, int g2, vector<vector<int> > records, int n) {
		
        int maxNum = -10000;
        //首先获取最大值
        for(int i=0; i<n; i++){
            maxNum = max( records[i][0], maxNum);
            maxNum = max( records[i][1], maxNum );
        }
        
        //构造有向图邻接矩阵
        int matrics[maxNum+1][maxNum+1];	//如果编译不过可以使用vector
        memset(matrics,0,sizeof(matrics));
        
        for(int i=1; i<=maxNum; i++){
            matrics[i][i] = 1;
        }
        
        for(int i=0; i<n; i++){
        	matrics[ records[i][0] ][ records[i][1] ] = 1;
        }
        
        //利用Floyd算法进行关系的递推
        for(int i=1; i<=maxNum; i++){
            for(int j=1; j<=maxNum; j++){
                for(int k=1; k<=maxNum; k++){
                    if( matrics[i][k]==1 && matrics[k][j]==1 ){
                        matrics[i][j] = 1;
                    }
                }
                
            }
        }
        
        if( matrics[g1][g2]==1 ){
            return 1;
        }else if( matrics[g2][g1]==1 ){
            return -1;
        }else{
            return 0;
        }
        
    
    }
};

#include <unordered_map>
class Cmp2 {
public:
    bool check(unordered_map<int,vector<int>>& m, int g1, int g2 ){
    	
		//进行BFS
        unordered_map<int,bool> mark;
        queue<int> q;
        q.push( g1 );
        mark[g1] = true;
        
        while( !q.empty() ){
            int val = q.front();
            q.pop();
          	mark[val] = true;
            if( val == g2 )
                return true;
           
            for(int i=0; i<m[val].size(); i++){
            	if( mark[ m[val][i] ] == false ){
                    mark[ m[val][i] ] = true;
                    q.push( m[val][i] );
                }
            }            
        }
        
        return false;
        
    } 
        
    int cmp(int g1, int g2, vector<vector<int> > records, int n) {
		
        //利用多叉树保存大小关系，叶节点的值比根的重量轻
        unordered_map<int,vector<int>> m;
        
        for(int i=0; i<n; i++){
            m[ records[i][0] ].push_back( records[i][1] );
        }
        
		//进行BFS层次遍历，判断是否为子树
        if( check( m, g1,g2 ) ){
            return 1;
        }
        else if( check( m, g2, g1 ) ){
            return -1;
        }else{
            return 0;
        }
    
    }
};