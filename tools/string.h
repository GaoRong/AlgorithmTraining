/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-17 21:26:44
** desc：  some of tools to convince the program
*********************************************************************************/


//以指点字符分割字符串，返回vector数组
vector<string> split(const string &s, const char sep){
	vector<string> result;
	
	int bi = 0,ei =0;
	for (int i = 0; i < s.length(); i++){
		if (s[i] != sep){
			ei++;
		}
		else{
			result.push_back(string(s,bi,ei-bi));
			bi = ei+1;
			ei++;
		}
	}
	result.push_back(string(s, bi));
	
	return result;
}