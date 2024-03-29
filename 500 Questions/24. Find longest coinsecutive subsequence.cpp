int findLongestConseqSubseq(int arr[], int N)
{
  vector<int> a(100001, -1);
  int maxEle = INT_MIN;
  for (int i = 0; i < N; i++) {
    a[arr[i]] = 1;
    maxEle = max(maxEle, arr[i]);
  }
  int maxLen = INT_MIN;
  int count = 0;
  for (int i = 0; i <= maxEle + 1; i++) {
    if (a[i] == 1) count++;
    else {
      maxLen = max(maxLen, count);
      count = 0;
    }
  }
  return maxLen;
}