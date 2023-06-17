#include <bits/stdc++.h> 
class minStack
{
	stack<int> s;
	int mini;
	
	public:
		
		minStack() 
		{ 
			// Write your code here.
		}
		
		void push(int num)
		{
			if(s.empty()){
				mini = num;
				s.push(num);
			}
			else{
				if(mini <= num){
					s.push(num);
				}
				else{
					int prev = num;
					num = 2*num - mini;
					mini = prev;
					s.push(num);
				}
			}
		}
		
		int pop()
		{
			if(!s.empty()){
				int data = s.top();
				if(data >= mini){
					s.pop();
					return data;
				}
				else{
					int prev = mini;
					mini = 2*mini - data;
					s.pop();
					return prev;
				}
			}
			return -1;
		}
		
		int top()
		{
			if(!s.empty()){
				int data = s.top();
				if(data >= mini) return data;
				else return mini;
			}
			return -1;
		}
		
		int getMin()
		{
			if(!s.empty()){
				return mini;
			}
			return -1;
		}
};