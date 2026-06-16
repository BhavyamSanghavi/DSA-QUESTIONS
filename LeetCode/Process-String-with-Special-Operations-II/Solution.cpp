// Intution: the result char must come from exisiting chars/letters in s
// So: we can simulate the process backward to find the kth char in s.
// T: O(N), S: O(1). Approach:
// 1. -> get total length of result n.
// 2. <- get the kth char (backward simulation).
char processStr(const string& s, long k, long n = 0) {
    for(const char& c : s) // 1. -> get total length of result n
        if(isalpha(c)) ++n; // append
        else if(c=='#') n*=2; // dup
        else if(c=='*' && n) --n; // remove
    if(k>=n) return '.'; // out of bound
    for(int i = s.size()-1; i>=0; --i) { // 2. <- get the kth char (backward simulation)
        char c = s[i];
        if(isalpha(c)) {
            if(--n==k) return c; // got the char
        }else if(c=='#') { // undo dup: dedup
            n/=2;
            if(k>=n) k-=n; // cut the first half
        }else if(c=='%') k = n-1-k; // undo reverse: mirror k
        else if(c=='*' && n) ++n; // undo remove
    }
    return '.';
}