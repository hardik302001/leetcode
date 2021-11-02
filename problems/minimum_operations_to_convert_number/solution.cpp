class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        
        queue<long long> q;
        vector<bool> visited(1050,false);
        
        q.push(start);
        visited[start]=true;
                
        long long len=0;
                
        while(q.size()>0)
        {
            long long qs=q.size();
            len++;

            while(qs--)
            {
                long long u=q.front(); q.pop();
                
                if(u<0 or u>1000)
                    continue;
                                
                for(auto v:nums)
                {
                    
                    if((u+v)==goal)
                            return len;
                    
                     if((u+v)<=1000 and (u+v)>=0 and visited[u+v]==false )
                    {    
                        q.push(u+v); visited[u+v]=true;           
                    }
                    
                    
                    if((u-v)==goal)
                            return len;
                    
                    if((u-v)<=1000 and (u-v)>=0 and visited[u-v]==false )
                    {    
                        q.push(u-v); visited[u-v]=true;           
                    }
                    
                    if((u^v)==goal)
                            return len;
                    
                     if((u^v)<=1000 and (u^v)>=0 and visited[(u^v)]==false )
                    {    
                        q.push(u^v); visited[u^v]=true;           
                    }
                    
                    
                }
                
            }
            
            // cout<<size<<endl;
            
        }
        
        return -1;
        
    }
};