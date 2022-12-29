// O(n) + O(120*120)

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> count;
        for (int &age : ages)
            count[age]++;
        int res = 0;
        for (auto &a : count)
            for (auto &b : count)
                if (request(a.first, b.first)){
                    if(a.first==b.first){
                        res += a.second * (b.second - 1);
                    }else{
                        res += a.second * b.second;
                    }
                }
        return res;
    }

    bool request(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
};