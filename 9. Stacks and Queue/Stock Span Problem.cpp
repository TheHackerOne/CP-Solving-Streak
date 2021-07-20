class Solution
{
public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
        stack<int> s;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (s.empty()) ans.push_back(1);

            if (s.size() > 0 && arr[s.top()] > arr[i]) {
                ans.push_back(i - s.top());
            }

            if (s.size() > 0 && arr[s.top()] <= arr[i]) {
                while (s.size() > 0 && arr[s.top()] <= arr[i]) {
                    s.pop();
                }
                if (s.empty()) ans.push_back(i - (-1));
                else ans.push_back(i - s.top());
            }

            s.push(i);
        }
        return ans;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector <int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}