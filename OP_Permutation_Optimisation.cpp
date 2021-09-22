Solution 2 Consider the following problem. • Arrange N distinguishable balls in a row. 
How many ways can you arrange two specific balls next to each other? Think of "two specific balls" 
as a group, and arrange these two balls. Considering the order, 
we can see that the answer to this question is 2 (N − 1)! Streets, so that the N! 
Street route in the original problem causes movement between pairs in each town. 
We can see that there are 2 (N − 1)! Routes, which means that the answer 
is 2 * (N−1)!/ N! = (2/N) times the sum of the distances between the pairs 
in each town. The amount of time calculation is O(N^2). 
Example solution by C ++: https://atcoder.jp/contests/abc145/submissions/8474573

int N;
int x[10], y[10];
 
double dist(int i, int j) {
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return pow(dx * dx + dy * dy, 0.5);
}
 
void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> x[i] >> y[i];
    double ans = 0.0;
    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) ans += dist(i, j) * 2 / N;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return;
}