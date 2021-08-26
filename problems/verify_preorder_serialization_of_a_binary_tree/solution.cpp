class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return false; 
        vector<string>pre;
        
        stringstream check(preorder);
        string intermediate;
        // Tokenizing w.r.t. space ','
        while(getline(check, intermediate, ','))
        {
            pre.push_back(intermediate);
        }
        
        int capacity=1;
        
        for (auto it: pre){
            if(capacity==0){
                return false;
            }

            if (it == "#") capacity-=1;
            else           capacity+=1;
            
        }
        return capacity==0;
    }
};



/*
We just need to remember how many empty slots we have during the process.

Initially we have one ( for the root ).

for each node we check if we still have empty slots to put it in.

a null node occupies one slot.
a non-null node occupies one slot before he creates two more. the net gain is one.
class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        # remember how many empty slots we have
        # non-null nodes occupy one slot but create two new slots
        # null nodes occupy one slot
        
        p = preorder.split(',')
        
        #initially we have one empty slot to put the root in it
        slot = 1
        for node in p:
            
            # no empty slot to put the current node
            if slot == 0:
                return False
                
            # a null node?
            if node == '#':
                # ocuppy slot
                slot -= 1
            else:
                # create new slot
                slot += 1
        
        #we don't allow empty slots at the end
        return slot==0
*/