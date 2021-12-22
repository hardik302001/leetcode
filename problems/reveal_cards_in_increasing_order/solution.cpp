// simulate on the reveresed queue

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> myQueue;
        vector<int> res(deck.size());
        for (int i = 0; i < deck.size(); ++i) myQueue.push(i);

        for (int i = 0; i < deck.size(); ++i) {
            res[myQueue.front()] = deck[i];
            myQueue.pop();
            int val = myQueue.front();
            myQueue.pop();
            myQueue.push(val);
        }

        return res;
    }
};


