class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i=1;
        int j = 0;
        int back = target[target.size()-1];
        vector<string>v;
        while(true){
            if(i==target[j]){
                v.push_back("Push");
                i++;
                j++;
            }
            else{
                v.push_back("Push");
                v.push_back("Pop");
                i++;
            }
            
            if(i==back+1){
                break;
            }
            
            
            
        }
        return v;
    }
};