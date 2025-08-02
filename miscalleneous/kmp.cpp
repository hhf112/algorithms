#include <bits/stdc++.h>
using namespace std;

class Solution {
  // lps[i] = length of the longest substring that is a prefix as well as a
  // suffix in the substrign from 0 to i. Entire substring can't be chosen.
  //
  vector<int> lps;
  Solution(int len) { lps.resize(len); }
  int KMP(string& data, string& search) {
    //
    int m = search.length();
    int n = data.length();
    // CONSTRUCT LPS O(m)
    if (search == "") return 0;

    int prevLPS = 0, i = 1;

    while (i < m) {
      if (search[i] == search[prevLPS]) {
        lps[i] = prevLPS + 1;
        prevLPS += 1;
        i += 1;
      }
      // if match fails then we try to go back to find a match. (shorter
      // substring)
      else if (prevLPS == 0) {
        lps[i] = 0;
        i += 1;
      } else
        prevLPS = lps[prevLPS - 1];
    }

    i = 0;
    int j = 0;
    while (i < n) {
      if (data[i] == search[j]) {
        ++i, ++j;
      } else {
        if (j == 0)
          i += 1;
        else
          j = lps[j - 1];
      }
      if (j == m) return i - m;
    }

    return -1;
  }
};
