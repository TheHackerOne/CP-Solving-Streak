class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int len = s.length();
		    int num = pow(2, len);
		    vector<string> ans;
		    for(int i=1;i<num;i++){
		        int num = i;
		        string x = "";
		        for(int i=0;i<len;i++){
		            if(num&1)
		                x += s[i];
		            num >>= 1;
		        }
		        ans.push_back(x);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};