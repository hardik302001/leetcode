// courtesy ; striver yt video


class node{
public:
    int key; 
    int val;
    node* next;
    node* prev;
    node(int key , int val){
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    
    node* head = new node(-1 , -1);
    node* tail = new node(-1 , -1);
    
    int cap;
    
    unordered_map<int, node*>mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode){  // add after head
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode){   // delete before tail
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    
    // whenever delete , remove from map, whenever add, add it to map
    
    int get(int key) {
        if(mp.count(key)){
            node* resnode = mp[key];
            int res = resnode->val;
            mp.erase(key);
            deletenode(resnode);       // delete it from link list
            addnode(resnode);          // add new address node in linklist
            mp[key] = head->next;      // add new address key in map
            return res;        
       }else{
            return -1;
        }
    }
    
    
    void put(int key, int value) {
        if(mp.count(key)){             // key already exists , so for the time being just remove the previous address node
            node* existingnode = mp[key];
            mp.erase(key);
            deletenode(existingnode);   // we need to update value for current key, so dlete it, add it, and update address in map
        }
        
        if(mp.size()==cap){    // remove LRU
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key, value));
        mp[key] = head->next;
     }
};

