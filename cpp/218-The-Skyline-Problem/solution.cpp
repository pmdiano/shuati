class Solution {
    struct CNode {
        int L, R;
        CNode *pLeft, *pRight;
        int Covers;
        int Len;
    } tree[21000];

    struct CLine {
        int x, h;
        bool bLeft;
        CLine(): x(0), h(0), bLeft(false) {}
        CLine(int xx, int hh, bool b): x(xx), h(hh), bLeft(b) {}
        bool operator<(const CLine& rhs) {
            if (this->x != rhs.x)
                return this->x < rhs.x;
            return this->bLeft;
        }
    } lines[21000];

    int y[11000];
    int yc = 0;
    int lc = 0;
    int nNodeCount = 0;

    template <class F, class T>
    F bin_search(F s, F e, T val) {
        F L = s;
        F R = e-1;
        while (L <= R) {
            F mid = L + (R-L) / 2;
            if (!(*mid < val || val < *mid))
                return mid;
            else if (val < *mid)
                R = mid-1;
            else
                L = mid+1;
        }
        return e;
    }
    
    int Mid(CNode* pRoot) {
        return (pRoot->L + pRoot->R) >> 1;
    }

    void Insert(CNode *pRoot, int L, int R) {
        if (pRoot->L == L && pRoot->R == R) {
            pRoot->Len = y[R+1] - y[L];
            pRoot->Covers++;
            return;
        }
        if (R <= Mid(pRoot))
            Insert(pRoot->pLeft, L, R);
        else if (L >= Mid(pRoot)+1)
            Insert(pRoot->pRight, L, R);
        else {
            Insert(pRoot->pLeft, L, Mid(pRoot));
            Insert(pRoot->pRight, Mid(pRoot)+1, R);
        }
        if (pRoot->Covers == 0) {
            pRoot->Len = pRoot->pLeft->Len + pRoot->pRight->Len;
        }
    }
    
    void Delete(CNode *pRoot, int L, int R) {
        if (pRoot->L == L && pRoot->R == R) {
            pRoot->Covers--;
            if (pRoot->Covers == 0) {
                if (pRoot->L == pRoot->R)
                    pRoot->Len = 0;
                else
                    pRoot->Len = pRoot->pLeft->Len + pRoot->pRight->Len;
            }
            return;
        }
        if (R <= Mid(pRoot))
            Delete(pRoot->pLeft, L, R);
        else if (L >= Mid(pRoot)+1)
            Delete(pRoot->pRight, L, R);
        else {
            Delete(pRoot->pLeft, L, Mid(pRoot));
            Delete(pRoot->pRight, Mid(pRoot)+1, R);
        }
        if (pRoot->Covers == 0) {
            pRoot->Len = pRoot->pLeft->Len + pRoot->pRight->Len;
        }
    }
    void BuildTree(CNode* pRoot, int L, int R) {
        pRoot->L = L;
        pRoot->R = R;
        pRoot->Covers = 0;
        pRoot->Len = 0;
        if (L == R)
            return;
        nNodeCount++;
        pRoot->pLeft = tree + nNodeCount;
        nNodeCount++;
        pRoot->pRight = tree + nNodeCount;
        BuildTree(pRoot->pLeft, L, (L+R)/2);
        BuildTree(pRoot->pRight, (L+R)/2+1, R);
    }

public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> ans;
        if (buildings.empty()) {
            return ans;
        }

        y[yc++] = 0;
        for (auto& building : buildings) {
            lines[lc++] = CLine(building[0], building[2], true);
            lines[lc++] = CLine(building[1], building[2], false);
            y[yc++] = building[2];
        }

        sort(y, y+yc);
        yc = unique(y, y+yc) - y;
        BuildTree(tree, 0, yc-1-1);

        sort(lines, lines+lc);
        for (int i = 0; i < lc; i++) {
            int L = 0;
            int R = bin_search(y, y+yc, lines[i].h) - y;
            if (lines[i].bLeft)
                Insert(tree, L, R-1);
            else
                Delete(tree, L, R-1);

            pair<int, int> p = make_pair(lines[i].x, tree[0].Len);
            if (ans.empty() || (ans.back().first != p.first && ans.back().second != p.second)) {
                ans.push_back(p);
            } else if (ans.back().first == p.first) {
                if (p.second == 0)
                    ans.back().second = 0;
                else
                    ans.back().second = max(ans.back().second, p.second);
            }
        }

        vector<pair<int, int>> ans2;
        ans2.push_back(ans[0]);
        int i = 0;
        for (int j = 1; j < ans.size(); j++) {
            if (ans[j].second != ans2[i].second) {
                ans2.push_back(ans[j]);
                i++;
            }
        }

        return ans2;
    }
};