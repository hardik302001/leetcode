// Create a max heap of the form pair<int,char> to store the count of each character.
// while (pq.size()>1)Pop out the first 2 pair who have the max frequency.
// Add greedily the occurances of the first pair to the ans and update it's count.
// For the second pair, compare it's occurances with the first pair and add accordingly.
// Finally add the pairs to the Max Heap if their count>0.
// If pq.empty() return ans, else add the leftover character to the ans according to the remaining counts and return the ans.


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        //using max heap
        priority_queue<pair<int,char>>pq;
        if(a)
        pq.push({a,'a'});   //if ypu do "a", "b" here then you get error, use single quote only..
        if(b)
        pq.push({b,'b'});
        if(c)
        pq.push({c,'c'});
        string ans="";
        while(pq.size()>1){
            pair<int,char>one = pq.top();pq.pop();   // consider 2 diff elemnet at a time, else you can get same element again and again
            pair<int,char>two = pq.top();pq.pop();
            if(one.first>=2){
                ans+=one.second;
                ans+=one.second;
                one.first-=2;
            }
            else{
                ans+=one.second;
                one.first-=1;
            }
            if(two.first>=2 && two.first>=one.first){
                ans+=two.second;
                ans+=two.second;
                two.first-=2;
            }
            else{
                ans+=two.second;
                two.first-=1;
            }
            if(one.first>0)
                pq.push(one);
            if(two.first>0)
                pq.push(two);
        }
        if(pq.empty())
            return ans;
        if(pq.top().first>=2){  // now only one element is left
            ans+=pq.top().second;
            ans+=pq.top().second;
        }
        else{
            ans+=pq.top().second;
        }
        return ans;
        
    }
};
