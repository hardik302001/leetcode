//implementation
//first come first serve
//also see this example : DDRRR  -> DD/RR -> DD//R -> /D//R ->/D/// -> Dire winner


class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dir;
        queue<int> rad;
        for(int i=0;i<senate.length();i++)
        {
            if(senate[i]=='D')
            {
                dir.push(i);
            }
            else
            {
                rad.push(i);
            }
        }
        int n =senate.length();
        while(true)
        {
            if(rad.empty()){return "Dire";}
            if(dir.empty()){return "Radiant";}
            int r=rad.front();
            int d=dir.front();
            rad.pop();
            dir.pop();
            if(r<d)
            {
                rad.push(r+n);    // +n  to tell that we will meet in next round
            }
            else
            {
                dir.push(d+n);
            }
        }
    }
};