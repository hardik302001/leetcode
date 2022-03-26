// either you sort and make cases or , use pq and avoid headache



class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
        while (K--) {
            int x = pq.top();
            pq.pop();

            pq.push(-1 * x);
        }
        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};