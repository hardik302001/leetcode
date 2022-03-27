class Solution {

public:

    vector<long long> kthPalindrome(vector<int>& qu, int l) {

        int len = l - l/2;

        long long num = 1, val, mxnum = 0;;

        int q = qu.size();

        vector<long long> ans(q);

            

        int lll = len - 1;

        while(lll--){

            num *= 10;

        }

        

        mxnum = num*10 - 1;

        

        for(int i = 0; i < q; i++){

            long long temp = num + qu[i] - 1;

            if(temp > mxnum){

                ans[i] = -1;

                continue;

            }

            

            val = temp;

            if(l % 2)

                val /= 10;

            

            while(temp){

                val = val * 10 + temp % 10;

                temp /= 10;

            }

            

            ans[i] = val;

        }

        

        return ans;

    }

};