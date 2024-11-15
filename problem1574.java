class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
      final int n = arr.length;
      int l = 0;
      int r = n - 1;
  
      // arr[0..l] is non-decreasing prefix.
      while (l < n - 1 && arr[l + 1] >= arr[l])
        ++l;
      // arr[r..n - 1] is non-decreasing suffix.
      while (r > 0 && arr[r - 1] <= arr[r])
        --r;
      // To Remove arr[l + 1..n - 1] or arr[0..r - 1]
      int ans = Math.min(n - 1 - l, r);
  
      int i = l;
      int j = n - 1;
      while (i >= 0 && j >= r && j > i) {
        if (arr[i] <= arr[j])
          --j;
        else
          --i;
        ans = Math.min(ans, j - i);
      }
  
      return ans;
    }
  }