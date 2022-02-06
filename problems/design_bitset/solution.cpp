class Bitset {
public:
    string s = "", fliped = "";
    
    int cnt1 = 0;
    int size = 0;
    
    Bitset(int size) 
    {
        for(int i=0; i<size; i++)
        {
            s.push_back('0');
            fliped.push_back('1');
        }
        
        this->size = size;
    }
    
    void fix(int ind) 
    {
        if(s[ind] == '0')
            cnt1++;
        
        s[ind] = '1';
        fliped[ind] = '0'; 
    }
    
    void unfix(int ind) 
    {
        if(s[ind] == '1')
            cnt1--;
        s[ind] = '0';
        fliped[ind] = '1';
    }
    
    void flip() 
    {
        swap(s, fliped);
        cnt1 = size - cnt1;
    }
    
    bool all() 
    {
        return cnt1 == size;
    }
    
    bool one() 
    {
        return cnt1;
    }
    
    int count() 
    {
        return cnt1;
    }
    
    string toString() 
    {
        return s;
    }
};