//see python implememntation also, that is easy


// This problem requires us to design a data structure that supports insert, remove, and getRandom in constant time O(1).

// This solution uses two data structures, a Hash Table and a resizable array. The Hash Table maps the values to their respective indices in the array.

// Insert Operation
// This operation can be easily supported by inserting the new value to the end of the resizable array and updating its index in the Hash Table.

// Remove Operation
// This operation is a little tricky. We can easily remove any element from the Hash Table in constant time as long as we know it's value. However, removing an element from the middle of the array is a costly operation. Fortunately, removing the last element of the array can be done in constant time ( using pop_back() ). We will swap the value we want to remove with the last element of the array and then remove the last element of the array.

// getRandom Operation
// This operation can be easily done by using C++ inbuilt rand() on the array.

// The code is as follows.

class RandomizedSet {
    vector<int> numberList;
    unordered_map<int, int> hashTable;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashTable.find(val) != hashTable.end())
        {
            return false;
        }
        hashTable[val] = numberList.size();
        numberList.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hashTable.find(val) == hashTable.end())
        {
            return false;
        }
        swap(numberList[hashTable[val]], numberList[numberList.size() - 1]);
        
        numberList.pop_back();
        
        //now update key value pairs of both last and val in hashmap
        
        //updating index of last(that is currently at index of val) to new index ( that is old index of val in numberList, before swapping, we have this info in hasmap as hashTable[val])
        hashTable[numberList[hashTable[val]]] = hashTable[val];   //numberList[hashTable[val]] gives last element, as eleemnt at old ind of val before swapping, we have this info in hasmap as hashTable[val])
        //removing val
        hashTable.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return numberList[rand() % numberList.size()];
    }
};