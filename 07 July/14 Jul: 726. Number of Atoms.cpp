class Solution {
public:
    int i;

    int convertToInteger(string s)
    {
        if(s == "")
        {
            return 1;
        }
        return stoi(s);
    }
    map<string,int> calc(string s)
    {
        int n=s.size(),j;
        map<string,int> mp;
        while(i < n)
        {
            if(isupper(s[i])) 
            {
                j = i;
                string element,cnt;
                element+=s[j++];
                while(j < n && islower(s[j]))
                {
                    element+=s[j];
                    j++;
                }
                while(j < n && isdigit(s[j]))
                {
                    cnt+=s[j];
                    j++;
                }
                i = j;
                mp[element]+=convertToInteger(cnt);
            }
            else if(s[i] == '(')
            {
                i++;
                auto temp = calc(s);
                for(auto p : temp)
                {
                    mp[p.first]+=p.second;
                }
            }
            else //if s[i] == ')'
            {
                i++;
                string cnt;
                while(i < n && isdigit(s[i]))
                {
                    cnt+=s[i];
                    i++;
                }
                if(cnt == "")
                {
                    continue;
                }
                int count = convertToInteger(cnt);
                for(auto p : mp)
                {
                    mp[p.first]*=count;
                }
                return mp;
            }
        }
        return mp;
    }
    string countOfAtoms(string s) 
    {
        i = 0;
        auto mp = calc(s);
        string ans;
        for(auto p : mp)
        {
            ans+=p.first;
            if(p.second == 1)
            {
                continue;
            }
            ans+=to_string(p.second);
        }
        return ans;
    }
};
