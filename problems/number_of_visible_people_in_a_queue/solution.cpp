//OKEY SO PREETY GOOD QUES!!..
/*
logic is same as NGE.. the common thing  is   ||  while cur>=stack.top()   do stack.pop()  ||
this is the main logic , second thing is you can iterate from starting and from end also, doesn't natter..it will work..
IN NGE also you can start from left or right , you will get answer


in this code, we are starting from left, previous to previous code was from right, se that also
*/



class Solution{
public:
	vector<int> canSeePersonsCount(vector<int>& A) {
        int n = A.size();
        vector<int> res(n), stack;
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && A[stack.back()] <= A[i])
                res[stack.back()]++, stack.pop_back();
            if (!stack.empty())
                res[stack.back()]++;
            stack.push_back(i);
        }
        return res;
    }
};