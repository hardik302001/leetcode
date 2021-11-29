//dsu 
//parent indexing is done with repect to indexes of account as we did in https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

// ples dry run first test case example, with soln and you willl get it ,



class Solution {
public:
    
    class UnionFind {
        public:  
            vector<int> parent;
            int count = 0;
            UnionFind(int n){                  //constructor
                count = n;
                for(int i = 0;i<=(n+1);i++){    //path compression
                    parent.push_back(i);
                }
            }

            int find(int x){
                if(parent[x]==x) return x;
                return parent[x] = find(parent[x]);
            }

            void Union(int x,int y){
                int X = find(x);
                int Y = find(y);
                
                // if(X==Y) return true;   //cycle found

                parent[Y]=X;
                count--;
                // return false;
            }
            
            int getCount(){
                return count;
            }
    };
    

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> emailToFirstAccountId;

        // Pass #1: Build a hash map from every email address to the first account ID that contains it. 
        //   Also build a union set of accounts based on shared email addresses.
        for (int i = 0; i < n; ++i) {
            // Iterate over all email addresses for this account (person name is index 0, emails start at index 1)
            for (int e = 1; e < accounts[i].size(); ++e) {
                const string& emailAddress = accounts[i][e];
                if (emailToFirstAccountId.count(emailAddress) == 0) {
                    // This email address is new.  Create a map entry from email address to this account.
                    emailToFirstAccountId[emailAddress] = i;
                }
                else {
                    // This email address has been seen before in a different account.  Union this account
                    // account A with the prior account ID to link all their email addresses together.
                    uf.Union(emailToFirstAccountId[emailAddress], i);
                }
            }
        }
        
        

        
        
        // Pass #2: Build a hash map from the unified set IDs to all email addresses contained within.
        unordered_map<int,vector<string>> unifiedSetIdToEmails;

        for (const pair<string, int>& p : emailToFirstAccountId) {
            int unifiedSetId = uf.find(p.second);                     //find connections
            unifiedSetIdToEmails[unifiedSetId].push_back(p.first);
        }

        
        
        
        // Pass #3: Finalize the results by inserting the name of the account and sorting all emails.
        vector<vector<string>> finalResults;

        for (pair<const int,vector<string>>& p : unifiedSetIdToEmails) {
            // Sort all the email addresses
            sort(p.second.begin(), p.second.end());

            string name = accounts[p.first][0];
            vector<string> row = { name };
            row.insert(row.end(), p.second.begin(), p.second.end());

            finalResults.push_back(row);
        }

        return finalResults;
    }
};