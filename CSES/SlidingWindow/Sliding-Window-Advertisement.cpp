#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
class LiChaoTree {
    struct Line {
        ll m, b;
        Line(ll m = 0, ll b = 0) : m(m), b(b) {}
        ll eval(ll x) const { return m * x + b; }
    };
 
    struct Node {
        Line line;
        Node *left, *right;
        Node(Line line = Line()) : line(line), left(nullptr), right(nullptr) {}
    };
 
    Node* root;
    ll X_LEFT, X_RIGHT;
 
    void insert_line(Node*& node, Line new_line, ll l, ll r) {
        if (!node) {
            node = new Node(new_line);
            return;
        }
        ll mid = (l + r) / 2;
        bool left_better = new_line.eval(l) > node->line.eval(l);
        bool mid_better = new_line.eval(mid) > node->line.eval(mid);
 
        if (mid_better) swap(node->line, new_line);
        if (l == r) return;
 
        if (left_better != mid_better)
            insert_line(node->left, new_line, l, mid);
        else
            insert_line(node->right, new_line, mid + 1, r);
    }
 
    void add_segment(Node*& node, Line new_line, ll l, ll r, ll seg_l, ll seg_r) {
        if (seg_r < l || r < seg_l) return;
        if (seg_l <= l && r <= seg_r) {
            insert_line(node, new_line, l, r);
            return;
        }
        if (!node) node = new Node();
        ll mid = (l + r) / 2;
        add_segment(node->left, new_line, l, mid, seg_l, seg_r);
        add_segment(node->right, new_line, mid + 1, r, seg_l, seg_r);
    }
 
    ll query(Node* node, ll x, ll l, ll r) {
        if (!node) return 0;
        ll res = node->line.eval(x);
        if (l == r) return res;
        ll mid = (l + r) / 2;
        if (x <= mid)
            res = max(res, query(node->left, x, l, mid));
        else
            res = max(res, query(node->right, x, mid + 1, r));
        return res;
    }
 
public:
    LiChaoTree(ll x_left, ll x_right) : X_LEFT(x_left), X_RIGHT(x_right), root(nullptr) {}
 
    void add_line(ll m, ll b, ll l, ll r) {
        add_segment(root, Line(m, b), X_LEFT, X_RIGHT, l, r);
    }
 
    ll query(ll x) {
        return query(root, x, X_LEFT, X_RIGHT);
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
 
    // Compute left[i]: index of previous element with height < h[i]
    vector<int> left(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
 
    while (!st.empty()) st.pop();
 
    // Compute right[i]: index of next element with height < h[i]
    vector<int> right(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
 
    LiChaoTree lct(0, n - k);
 
    for (int i = 0; i < n; i++) {
        ll H = h[i];
        int L = left[i] + 1;   // first index where H is the minimum
        int R = right[i] - 1;  // last index where H is the minimum
 
        // Valid window starts that include board i
        int s_low = max(0, i - k + 1);
        int s_high = min(n - k, i);
 
        if (s_low > s_high) continue;
 
        // Region I: s <= min(L, R-k+1)
        // Area = H*(s + k - L) = H*s + H*(k-L)
        {
            int rgn_end = min(L, R - k + 1);
            if (s_low <= rgn_end) {
                int seg_l = s_low;
                int seg_r = min(s_high, rgn_end);
                if (seg_l <= seg_r) {
                    ll slope = H;
                    ll intercept = H * (k - L);
                    lct.add_line(slope, intercept, seg_l, seg_r);
                }
            }
        }
 
        // Region II: s >= L and s <= R-k+1
        // Area = H*k (constant)
        {
            int seg_l = max(s_low, L);
            int seg_r = min(s_high, R - k + 1);
            if (seg_l <= seg_r) {
                lct.add_line(0, H * k, seg_l, seg_r);
            }
        }
 
        // Region III: s <= L and s >= R-k+1 (only if R-k+1 <= L)
        // Area = H*(R-L+1) (constant)
        if (R - k + 1 <= L) {
            int seg_l = max(s_low, R - k + 1);
            int seg_r = min(s_high, L);
            if (seg_l <= seg_r) {
                lct.add_line(0, H * (R - L + 1), seg_l, seg_r);
            }
        }
 
        // Region IV: s >= max(L, R-k+1)
        // Area = H*(R - s + 1) = -H*s + H*(R+1)
        {
            int seg_l = max(s_low, max(L, R - k + 1));
            int seg_r = min(s_high, R);
            if (seg_l <= seg_r) {
                ll slope = -H;
                ll intercept = H * (R + 1);
                lct.add_line(slope, intercept, seg_l, seg_r);
            }
        }
    }
 
    for (int i = 0; i <= n - k; i++) {
        cout << lct.query(i) << " \n"[i == n - k];
    }
 
    return 0;
}