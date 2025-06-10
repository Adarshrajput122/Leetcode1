class Solution {
public:
   vector<int> findAnagrams(string s, string p) {
    vector<int> result;                      // Stores indices where anagram is found
    int sLen = s.length(), pLen = p.length();

    if (sLen < pLen) return result;          // If p is longer, no match possible

    vector<int> pHash(26, 0);                // Frequency count of p
    vector<int> sHash(26, 0);                // Frequency count of current window in s

    // Step 1: Build frequency maps for p and for the first window of s
    for (int i = 0; i < pLen; ++i) {
        pHash[p[i] - 'a']++;                 // Increase count for each char in p
        sHash[s[i] - 'a']++;                 // Do same for first pLen characters of s
    }

    // Step 2: Check if first window matches p
    if (pHash == sHash) result.push_back(0); // If maps are same, add index 0

    // Step 3: Slide the window through s
    for (int i = pLen; i < sLen; ++i) {
        sHash[s[i - pLen] - 'a']--;          // Remove character going out of window
        sHash[s[i] - 'a']++;                 // Add character coming into window

        if (sHash == pHash) {                // If new window matches p
            result.push_back(i - pLen + 1);  // Store starting index
        }
    }

    return result;
}

};