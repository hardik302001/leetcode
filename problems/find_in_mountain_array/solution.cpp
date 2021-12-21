
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mount) {
        int l = 0;
        int r = mount.length()-1;
        int peak;
        while (l<r){
            int m = l + (r-l)/2;
            int midvalue = mount.get(m);
            if(midvalue > mount.get(m+1)){
                if(midvalue>mount.get(m-1)){
                    peak = m;
                    break;
                }
                else{
                    r = m;
                }
            }else{
                l = m+1;
            }
        }
        if(mount.get(peak)==target){
            return peak;
        }
        // cout<<peak<<endl;
        
        int ans1 = check1(0 , peak, target, mount);
        // cout<<ans1<<endl;
        if(ans1 != -1){return ans1;}
        int ans2 = check2(peak, mount.length(), target, mount);
        // cout<<ans2<<endl;
        if(ans2 != -1){return ans2;}
        
        return -1;
    }
    
    int check1(int l, int r, int target, MountainArray &mount){   //increasing
        while(l<r){
            int m = l + (r-l)/2;
            int midvalue = mount.get(m);
            if(midvalue ==target){
                return m;
            }
            else{
                if(midvalue>target){
                    r = m;  
                }
                else{
                    l = m+1;
                }
            }
        }
        return -1;
    }
    
    int check2(int l, int r, int target,MountainArray &mount){    //decreasing
        while(l<r){
            int m = l + (r-l)/2;
            int midvalue = mount.get(m);
            if(midvalue ==target){
                return m;
            }
            else{
                if(midvalue >target){
                    l = m+1;  
                }
                else{
                    r = m;
                }
            }
        }
        return -1;
    }
    
    
};
