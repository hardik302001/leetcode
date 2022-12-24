
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        
        
        vector<pair<int,int> > tmp;
        vector<int> sol;
        map<string,int> pos,neg;
        for(auto p:positive_feedback){
            pos[p]=1;
        }
        
        for(auto p:negative_feedback){
            neg[p]=1;
        }
        
        int n=report.size();
        for(int i=0;i<n;i++){
            int sc=0;
            string curr;
            for(auto ch:report[i]){
                if(ch==' '){
                    if(pos.find(curr) != pos.end()){
                        sc+=3;
                    }
            
                    if(neg.find(curr) != neg.end()){
                        sc-=1;
                    }
                        
                    curr.clear();
                }else{
                    curr+=ch;
                }
            }
            
            
            if(pos.find(curr) != pos.end()){
                sc+=3;
            }
            
            if(neg.find(curr) != neg.end()){
                sc-=1;
            }
            
            tmp.push_back({-sc,student_id[i]});
        }
        
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<k;i++){
            sol.push_back(tmp[i].second);
        }
        
        return sol;
        
    }
};