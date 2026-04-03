class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        if(s.length !== t.length) return false;
        const dict_s = {};
        const dict_t = {};
        for(let i = 0; i < s.length; i++){
            dict_s[s[i]] = (dict_s[s[i]] || 0) + 1;
            dict_t[t[i]] = (dict_t[t[i]] || 0) + 1;
        }
        for(const key in dict_s){
            if(dict_s[key] !== dict_t[key]){
                return false;
            }
        }
        return true;
    }
}
