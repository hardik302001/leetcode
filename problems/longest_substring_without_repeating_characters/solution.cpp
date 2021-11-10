//sliding window




class Solution {
public:
    int lengthOfLongestSubstring(string v) {
        	map<int ,bool > mymap;
            int n = v.size();
            int maxx=0;
            int currans=0;
            int j=0;
            for(int i=0;i<n;i++){
                int k = v[i];
                if(mymap.find(k)==mymap.end()||mymap[k]==false){
                        mymap[k]=true;
                        currans++;
                        maxx=max(currans,maxx);

                }
                else{        //key exist in map also and map[key]=true also
                     while(v[j]!=k){
                            mymap[v[j]]=false;
                            j++;
                     }
                     
                    
                     currans=(i-j); 
                     j++;


                }
            }
            
        return maxx;
        


        
        
    }
};