#牛客网校招模拟题1
####[序列和](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/SumOfSequence.cpp)
tag : 数学逻辑    
address: https://www.nowcoder.com/questionTerminal/46eb436eb6564a62b9f972160e1699c9   
>给出一个正整数N和长度L，找出一段长度大于等于L的连续非负整数，他们的和恰好为N。答案可能有多个，我们需要找出长度最小的那个。
>例如 N = 18  L = 2：   
>5 + 6 + 7 = 18;   
>3 + 4 + 5 + 6 = 18;   
>都是满足要求的，但是我们输出更短的 5 6 7      

####[超级素数幂](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/PrimePow.cpp)      
tag : 数学逻辑,精度		     
address: https://www.nowcoder.com/questionTerminal/fb511c3f1ac447309368d7e5432c6c79		
>如果一个数字能表示为p^q(^表示幂运算)且p为一个素数,q为大于1的正整数就称这个数叫做超级素数幂。现在给出一个正整数n,如果n是一个超级素数幂需要找出对应的p,q。    
>输入描述:输入一个正整数n(2 ≤ n ≤ 10^18)    
>输出描述:如果n是一个超级素数幂则输出p,q,以空格分隔,行末无空格。如果n不是超级素数幂，则输出No    
>输入例子:27    
>输出例子:3 3    

####[连续整数](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/SeriesNumber.cpp)	
tag : 按位异或	
address: https://www.nowcoder.com/questionTerminal/c3083cd30d5043e1b95000f139b5b2c9	

####[循环单词](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/CircleWord.cpp)	
tag : 字符串    	
address: https://www.nowcoder.com/questionTerminal/9d5fbe7750a34d0b91c73943f93b2d7d  
>如果一个单词通过循环右移获得的单词，我们称这些单词都为一种循环单词。 例如：picture 和 turepic 就是属于同一种循环单词。 现在给出n个单词，需要统计这个n个单词中有多少种循环单词。 



#网易2016实习研发工程师   
####[二叉树](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/BTleafNodeDistance.cpp)
tag: 二叉树   
address: https://www.nowcoder.com/questionTerminal/d567727f21a247f7b64ba32431cb9a19   

>有一棵二叉树，树上每个点标有权值，权值各不相同，请设计一个算法算出权值最大的叶节点到权值最小的叶节点的距离。二叉树每条边的距离为1，一个节点经过多少条边到达另一个节点为这两个节点之间的距离。 给定二叉树的根节点root，请返回所求距离。    

tips: 典型的二叉树递归也可解，但将二叉树叶子结点进行01编码是妙解     

####[比较重量](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/WeightCompare.cpp)
tag: 有向图，多叉树，bfs，floyd算法  
address: https://www.nowcoder.com/questionTerminal/ac27e60e63b549d6a9b59f815d9bc6e2       

>给定两颗钻石的编号g1,g2，编号从1开始，同时给定关系数组vector,其中元素为一些二元组，第一个元素为一次比较中较重的钻石的编号，第二个元素为较轻的钻石的编号。最后给定之前的比较次数n。请返回这两颗钻石的关系，若g1更重返回1，g2更重返回-1，无法判断返回0。输入数据保证合法，不会有矛盾情况出现。    

tips:  对于判断相互关系的题型都可以这样构造一个有向图或多叉树      

#搜狐2016研发工程师编程题
 
####[马戏团](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/Circus.cpp)    
tag: 最长递增子序列     
address: https://www.nowcoder.com/questionTerminal/c2afcd7353f84690bb73aa6123548770     

>搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，精彩的表演结束后发现团长正和大伙在帐篷前激烈讨论，小王打听了下了解到，
马戏团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗汉表演。考虑到安全因素，要求叠罗汉过程中，站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。
团长想要本次节目中的罗汉塔叠的最高，由于人数众多，正在头疼如何安排人员的问题。小王觉得这个问题很简单，于是统计了参与最高罗汉塔表演的所有团员的身高体重，并且很快找到叠最高罗汉塔的人员序列。  现在你手上也拿到了这样一份身高体重表，请找出可以叠出的最高罗汉塔的高度，这份表中马戏团员依次编号为1到N。

tips: 先按照体重排序，然后对身高求最长递增序列    
####[发奖金](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/Bonus.cpp)    
tag: 正反遍历    
address: https://www.nowcoder.com/questionTerminal/acb888f7ccee4fc0aab208393d41a552    

>搜狐进行了一次黑客马拉松大赛，全公司一共分为了N个组，每组一个房间排成一排开始比赛，比赛结束后没有公布成绩，但是每个组能够看到自己相邻的两个组里比自己成绩低的组的成绩，比赛结束之后要发奖金，以1w为单位，每个组都至少会发1w的奖金，另外，如果一个组发现自己的奖金没有高于比自己成绩低的组发的奖金，就会不满意，作为比赛的组织方，根据成绩计算出至少需要发多少奖金才能让所有的组满意。 






