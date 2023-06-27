#include<bits/stdc++.h>

int helper(string s, string t, int indx1, int indx2,vector<vector<int>> &dp){
	if(indx1<0 || indx2<0) return 0;
	if(dp[indx1][indx2]!=-1) return dp[indx1][indx2];

	if(s[indx1]==t[indx2])
		 return dp[indx1][indx2] = 1 + helper(s,t,indx1-1,indx2-1,dp);
	else{
		int possibility1 = helper(s,t,indx1-1,indx2,dp);
		int possibility2 = helper(s,t,indx1,indx2-1,dp);
		return dp[indx1][indx2] = max(possibility1,possibility2);
	}
}

int lcs(string s, string t)
{
	vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
	return helper(s,t,s.length()-1,t.length()-1,dp);
}