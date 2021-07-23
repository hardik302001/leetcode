
class Solution {
public:
    static bool sort_karo(string &a,string& b)
    {
        return a+b>b+a;
    }

    string largestNumber(vector<int>& nums) {
        if(nums.size()==0)
            return "";
    
        vector<string> get;
        for(int i=0;i<nums.size();i++)
            get.push_back(to_string(nums[i]));

        sort(get.begin(),get.end(),sort_karo);

        string s="";
        if(get[0]=="0")
            return "0";

        for(int i=0;i<get.size();i++)
            s+=(get[i]);

        return s;
    }
};