/*

The Dot(.) operator is used to normally access members of a structure or union.
as we do in dsu, we have class, and we access member using '.'.

The Arrow(->) operator exists to access the members of the structure or the unions using pointers.
as we do in link lists, we have pointer to ListNode pointer, so we use '->' to access next, prev member


*/

class Solution {
public:
    unordered_map<int, Employee*> emap;
    
    int getImportance(vector<Employee*> employees, int id) {
        for(auto& emp : employees){
            emap[emp->id] = emp;
        }
        return dfs(id);
    }
    
    
    int dfs(int id){
        Employee* emp = emap[id];
        int result = emp->importance;
        for(auto& s : emp->subordinates){
            result += dfs(s);
        }
        return result;
    }
};