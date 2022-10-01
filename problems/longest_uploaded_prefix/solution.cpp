
/*
class LUPrefix {
   public:
    set<int> s;
    int t = 1;
    LUPrefix(int n) {
    }

    void upload(int video) {
        s.emplace(video);
    }

    int longest() {
        while (s.count(t)) {   // we need not always start from 1
            t++;
        }
        return t-1;
    }
};
*/


// ----------------------------------------------------------------------

// similar idea



class LUPrefix {
public:
	vector<bool> vis;
	int ind;
	LUPrefix(int n) {
		ind = 0;
		vis.resize(n, false);
	}

	void upload(int video) {
		vis[video - 1] = true;
	}

	int longest() {
		while (ind < vis.size() && vis[ind])
			ind++;
		return ind;
	}
};
