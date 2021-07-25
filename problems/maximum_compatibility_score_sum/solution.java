class Solution {
    public int maxCompatibilitySum(int[][] students, int[][] mentors) {
        int answ = 0;
        return answer(mentors, students, 0 , new boolean[students.length], 0);
    }
    
    public int answer(int[][] m, int[][] s, int i , boolean[] vis, int cc ){
        int rese = Integer.MIN_VALUE;
        if(i>=s.length){
            return 0;
        }
        
        for(int j = 0;j<s.length;j++){
            if(!vis[j]){
                vis[j] = true;
                int counter = 0;
                for(int kk = 0;kk<s[0].length;kk++){
                    if(s[i][kk]==m[j][kk]){
                        counter++;
                    }
                }
                
                int inbetween = answer(m, s , i+1, vis,0);
                
                inbetween +=counter;
                vis[j] = false;
                rese = Math.max(inbetween, rese);
                
            }
        }
        
        return rese;
        
    }
}