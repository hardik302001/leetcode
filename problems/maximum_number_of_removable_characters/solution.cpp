class Solution {
public:
    
    int get(string s, string &p, vector<int> &rem, int k ){
		for(int i = 0; i < k; i++){			//change chars to keep track
            s[ rem[i] ] = '?';
        }
			int n1 = s.length(), n2 = p.length();   //check subsequence
			int i = 0, j = 0;
			while( i < n1 and j < n2 ){
				if( s[i] == p[j] ) j++;
				i++;
			}
			return j == n2;
		}

    
    int maximumRemovals(string s, string p, vector<int>& removable) {

			int ans = 0, st = 0, en = removable.size();
			while( st <= en ){
				int mid = (st + en)/2;
				if( get(s ,p, removable, mid) ) ans = mid, st = mid + 1;
				else en = mid - 1;
			}
			return ans;
		}
    
};