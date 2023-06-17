#include <bits/stdc++.h> 
int findCelebrity(int n) {
	stack<int> s;
	 for(int i=0;i<n;i++)
	  s.push(i);
	while(s.size() > 1)
	{
		int a=s.top();
		s.pop();
		int b=s.top();
		s.pop();
		if(knows(a,b))
		 s.push(b);
		else
		 s.push(a);
	}
	int ans=s.top();
	// step 3
	int zerocount=0;
	for(int i=0;i<n;i++)
	{
		if(!knows(ans,i))
		zerocount++;
	}
	if(zerocount != n)
	 return -1;
	
	int onecount=0;
	for(int i=0;i<n;i++)
	{
		if(knows(i,ans))
		onecount++;
	}
	if(onecount != n-1)
	 return -1;
	return ans;

}