class Robot {
public:
    
    vector<string>d= {"East", "North", "West", "South"};
    
    int w;
    int h ;
    string dir;
    vector<int> cur;
    int tot;
    
    Robot(int width, int height) {
        w = width -1;
        h = height - 1;
        dir = "East";
        cur = {0,0};
        tot = (w+h)*2;
    }
    
    void move(int num) {
        num = num%(2*tot);
        if(num==0){           //it means after one round it is at same position
            if(dir=="East" and cur[0] == 0 and cur[1] == 0)dir = "South";
            else if(dir=="South" and cur[0] == 0 and cur[1] == h)dir = "West";
            else if(dir=="West" and cur[0] == w and cur[1] == h)dir = "North";
            else if(dir=="North" and cur[0] == 0 and cur[1] == w)dir="East";
        }
        int old = num;
        while(num>0){
            if(dir=="East"){
                if(cur[0]==w){
                    dir = "North";
                }
                else{
                    int dif = w- cur[0];
                    int mi = min(dif, num);
                    num = num - mi;
                    cur[0] = cur[0] + mi;
                }           
            }
            else if(dir=="North"){
                   if(cur[1]==h){
                    dir = "West";
                }
                else{
                    int dif = h - cur[1];
                    int mi = min(dif, num);
                    num = num - mi;
                    cur[1] = cur[1] + mi;
                
                }
            }
            else if(dir=="West"){
                  if(cur[0]==0){
                    dir = "South";
                }
                else{
                    int dif = cur[0]-0;
                    int mi = min(dif, num);
                    num = num - mi;
                    cur[0] = cur[0] - mi;
                }
                
            }
            else{ 
                if(cur[1]==0){
                    dir = "East";
                   
                }
                else{
                    int dif =  cur[1] - 0;
                    int mi = min(dif, num);
                    num = num - mi;
                    cur[1] = cur[1] - mi;//south
                }
            }
           
            
            
        }
         
             cout<<old<<" "<< cur[0]<<" "<<cur[1]<<dir<<endl;
    }
    
    vector<int> getPos() {
        return cur;
    }
    
    string getDir() {
        return dir;
    }
};

