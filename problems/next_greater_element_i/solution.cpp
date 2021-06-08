//see previous solution


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        map<int,int>m;
        
        for(int i = 0;i<nums2.size();i++){
            if(s.empty()){
                s.push(nums2[i]);
            }
            else{
                if(s.top()>=nums2[i]){
                    s.push(nums2[i]);
                }
                else{
                    while(!s.empty() and s.top()<nums2[i]){
                        m.insert({s.top(),nums2[i]});
                        s.pop();                      //we need to do it seperately bcz in cpp..s.pop( dont return anything...bcz its actually a stl) ..so we took the element...put it into map..and then popped it ...while in python stack is actually a list..so we get an element on stack.pop()
                    }
                    s.push(nums2[i]);
                }
            }
        }
        
        vector<int>v;
        
        for(int i = 0;i<nums1.size();i++){
            if(m.find(nums1[i])==m.end()){
                v.push_back(-1);
            }
            else{
                v.push_back(m[nums1[i]]);
            }
        }
        
        
        return v;
        
    }
};