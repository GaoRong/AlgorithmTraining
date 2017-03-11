/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-11 11:00:13
** desc：  有一棵二叉树，树上每个点标有权值，权值各不相同，请设计一个算法算出权值最大的叶节点
**         到权值最小的叶节点的距离。二叉树每条边的距离为1，一个节点经过多少条边到达另一个节点为
**		   这两个节点之间的距离。
*********************************************************************************/



//这是常规解法，一定要注意递归的时候收集那些信息，即向上层或下层传递那些信息，
//递归终止条件，并且某一子树为空的情景
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Tree {
public:
	//每次递归都需要收集当前左右节点的最大值最小值及其距离，这样才能比较
    void getRes( TreeNode* root, int& maxVal, int& maxDis, int& minVal, int& minDis,  int& distance ){
        if( root->left == NULL && root->right == NULL) {
            minDis = maxDis = 0;
            minVal = maxVal = root->val;
            return;
        }
        
      	int lMaxVal, lMaxDis, lMinVal,lMinDis,lDistance;
        if( root->left )
        	getRes(root->left, lMaxVal,lMaxDis,lMinVal,lMinDis,lDistance);
        int rMaxVal, rMaxDis, rMinVal,rMinDis,rDistance;
        if( root->right )
        	getRes(root->right, rMaxVal, rMaxDis, rMinVal,rMinDis,rDistance);
        
        if( root->left && root->right == NULL){   //右子树为空
            maxVal = lMaxVal,  minVal = lMinVal;
            maxDis = lMaxDis+1,minDis = lMinDis+1;
            return;
        }
        if( root->right && root->left == NULL ){   //左子树为空
            maxVal = rMaxVal, minVal = rMinVal;
            maxDis = rMaxDis+1, minDis = rMinDis+1;
            return;
        }
        
		//左右都非空，需要比较左右子树中的最值并获得当前节点的最值
        if( lMaxVal > rMaxVal && lMinVal < rMinVal){
            maxVal = lMaxVal,  minVal = lMinVal;
            maxDis = lMaxDis+1,minDis = lMinDis+1;
            distance = lDistance;
        }else if( lMaxVal > rMaxVal && lMinVal > rMinVal ){
            maxVal = lMaxVal,  minVal = rMinVal;
            maxDis = lMaxDis+1,minDis = rMinDis+1;
            distance = maxDis + minDis;
        }else if( lMaxVal < rMaxVal && lMinVal < rMinVal ){
            maxVal = rMaxVal, minVal = lMinVal;
            maxDis = rMaxDis+1, minDis = lMinDis+1;
            distance = maxDis + minDis;
        }else{
            maxVal = rMaxVal, minVal = rMinVal;
            maxDis = rMaxDis+1; minDis = rMinDis+1;
            distance = rDistance;
        }   
    }
    
    
    int getDis(TreeNode* root) {
        int maxVal, maxDis, minVal,minDis,distance;
        getRes(root, maxVal,maxDis,minVal,minDis,distance);
		return distance;
    }	
 };


 //下面是精辟的解法，利用二进制编码，算出叶子节点二进制编码，再比编码，计算后缀长度和
 //巧用map进行排序，很到位，代码简洁
class Tree2 {
public:
    
    void getMap( TreeNode* root,map<int,string>& m,string str ){
        
        if( root->left== NULL && root->right == NULL  ){
            m[root->val] = str;
            return;
        }
        
        if( root->left ){
            getMap(root->left, m, (str+'0'));
        }
        if( root->right ){
            getMap(root->right, m, (str+'1'));
        }     
    }
    
    
    int getDis(TreeNode* root) {
    	map<int,string> m;
        string str;
        getMap(root, m, str);
        
        auto minIter = m.begin();
        string min = minIter->second;
        auto maxIter = --m.end();
        string max = maxIter->second;
        
        int i,j;
        for(i=0,j=0; i<min.size()&&j<max.size()&&min[i]==max[j]; i++,j++);
        
        return (min.size()-i) + (max.size()-j); 
        
    }	
 };