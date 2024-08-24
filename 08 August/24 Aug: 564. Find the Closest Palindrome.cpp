class Solution {
public:
    string nearestPalindromic(string n) {
        int length = n.size();
        set<string> candidates;

        if (n == "1") return "0";

        string prefix = n.substr(0, (length + 1) / 2);
        long long prefixNumber = stoll(prefix);

        for (long long i : {-1, 0, 1}) {
            string newPrefix = to_string(prefixNumber + i);
            string candidate;
            if (length % 2 == 0) {
                candidate = newPrefix + string(newPrefix.rbegin(), newPrefix.rend());
            } else {
                candidate = newPrefix + string(newPrefix.rbegin() + 1, newPrefix.rend());
            }
            candidates.insert(candidate);
        }

        candidates.insert(to_string(static_cast<long long>(pow(10, length - 1)) - 1));
        candidates.insert(to_string(static_cast<long long>(pow(10, length)) + 1));
        candidates.erase(n);
        string closestPalindrome;
        long long minDifference = LLONG_MAX;
        long long num = stoll(n);
        for (const string& candidate : candidates) {
            long long candidateNum = stoll(candidate);
            long long difference = abs(candidateNum - num);
            if (difference < minDifference || (difference == minDifference && candidateNum < stoll(closestPalindrome))) {
                minDifference = difference;
                closestPalindrome = candidate;
            }
        }

        return closestPalindrome;
    }
};
