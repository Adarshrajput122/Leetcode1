class Solution {
public:
bool checkInclusion(string s1, string s2) {
    int len1 = s1.length(), len2 = s2.length();
    if (len1 > len2) return false;

    vector<int> s1Map(26, 0), s2Map(26, 0);

    // Count frequency of characters in s1 and first window of s2
    for (int i = 0; i < len1; ++i) {
        s1Map[s1[i] - 'a']++;
        s2Map[s2[i] - 'a']++;
    }

    // If first window matches, return true
    if (s1Map == s2Map) return true;

    // Slide the window
    for (int i = len1; i < len2; ++i) {
        // Remove the character going out of the window
        s2Map[s2[i - len1] - 'a']--;

        // Add the new character coming into the window
        s2Map[s2[i] - 'a']++;

        // Check if frequency maps match
        if (s1Map == s2Map) return true;
    }

    return false;
}

};