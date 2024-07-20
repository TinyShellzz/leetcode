#include "utils/headers.h"

struct my_hasher {
    size_t operator()(vector<int> const& vec) const {
        hash<int> ha;
        return ha(vec.at(0)) ^ ha(vec.at(1));
    }
};
class DetectSquares {
    unordered_map<vector<int>, int, my_hasher> points;
    unordered_map<int, vector<unordered_map<vector<int>, int>::const_iterator>> umap;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        auto f = points.find(point);
        if(f != points.end()) f->second++;
        else {
            points[point] = 1;
            umap[point[0]].push_back(points.find(point));
        }
    }
    
    int count(vector<int> point) {
        auto f = umap.find(point[0]);
        int ret = 0;
        if(f != umap.end()) {
            for(auto p: f->second) {
                int c1 = p->second;
                int l = abs(p->first[1] - point[1]);
                if(l == 0) continue;

                // condition 1
                auto f2_1 = points.find({point[0]-l, point[1]});
                int c2_1 = f2_1 == points.end() ? 0 : f2_1->second;
                auto f3_1 = points.find({point[0]-l, p->first[1]});
                int c3_1 = f3_1 == points.end() ? 0 : f3_1->second;

                // condition 2
                auto f2_2 = points.find({point[0]+l, point[1]});
                int c2_2 = f2_2 == points.end() ? 0 : f2_2->second;
                auto f3_2 = points.find({point[0]+l, p->first[1]});
                int c3_2 = f3_2 == points.end() ? 0 : f3_2->second;

                ret += c1*c2_1*c3_1 + c1*c2_2*c3_2;
            }
        }

        return ret;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */