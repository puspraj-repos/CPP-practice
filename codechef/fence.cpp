#include<bits/stdc++.h>
using namespace std;

// struct hash_pair {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const
//     {
//         auto hash1 = hash<T1>{}(p.first);
//         auto hash2 = hash<T2>{}(p.second);
//         return hash1 ^ hash2;
//     }
// };

#include <functional>
// from boost (functional/hash):
// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html template
template <typename T>
inline void hash_combine(std::size_t &seed, const T &val) {
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
// auxiliary generic functions to create a hash value using a seed
template <typename T> inline void hash_val(std::size_t &seed, const T &val) {
    hash_combine(seed, val);
}
template <typename T, typename... Types>
inline void hash_val(std::size_t &seed, const T &val, const Types &... args) {
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types &... args) {
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        return hash_val(p.first, p.second);
    }
};

int main()
{
    int t; 
    cin >> t;
    while(t--)
    {
        int n, m, k, r, c;
        cin >> n >> m >> k;
        int ans = 4*k;
        unordered_set<pair<int, int>, pair_hash> us;
        
        for(int i = 0; i < k; i++)
        {
            cin >> r >> c;
            us.insert({r, c});
        }
        for(unordered_set<pair<int, int>>::iterator i = us.begin(); i != us.end(); i++)
        {
            int row = (*i).first;
            int col = (*i).second;
            if(row + 1 <= n)
            {
                if(us.find({row + 1, col}) != us.end())
                {
                    ans--;
                }
            }
            if(col + 1 <= m)
            {
                if(us.find({row, col + 1}) != us.end())
                {
                    ans--;
                }
            }
            if(row - 1 >= 1)
            {
                if(us.find({row - 1, col}) != us.end())
                {
                    ans --;
                }
            }
            if(col - 1 >= 1)
            {
                if(us.find({row, col -1}) != us.end())
                {
                    ans--;
                }
            }
        }
        cout << ans << endl;
    }
}