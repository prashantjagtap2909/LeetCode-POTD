class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();
        for(int i = 0 , j = 0 ;  (i < m) || ( j < n) ; i++, j++){
            int value1 = 0 , value2 = 0;
            while((i < m ) && (version1[i] != '.')) value1 = value1 * 10 + (version1[i++] - '0');
            while ((j < n) && (version2[j] != '.')) value2 = value2 * 10 + (version2[j++] - '0');


            if(value1 < value2) return -1;
            if(value1 > value2) return 1;
        } 
        return 0;
    }
};
