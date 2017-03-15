/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-12 23:49:54
** desc：  
*********************************************************************************/

//动态规划

int maxProfit1(vector<int>& prices) {
	if(prices.size() == 0)
		return 0;
	
	int profit = -1;
	int minValue = prices[0];
	
	for(int i=0; i< prices.size(); i++ ){
		
		if( prices[i] - minValue > profit){
			profit = prices[i]-minValue;
		}
		
		if( prices[i] < minValue ){
			minValue = prices[i];
		}
	}
	return profit;
}


int maxProfit2(vector<int>& prices) {
	if( prices.size() == 0 )    return 0;
	
	int profit = 0;
	for(int i=1; i<prices.size(); i++){
		if( prices[i] > prices[i-1]){
			profit += prices[i]-prices[i-1];
		}
	}  
	return profit;
}