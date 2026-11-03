long repeatedString(string s, long n) {
    long count = 0;
    for(const char& c : s){
        if(c == 'a')++count;
    }
    int len = s.size();
    count *= n / len;
    if(len != 1){
        int remains = n % s.size();
        while (remains > 0){
            if(s[--remains] == 'a')++count;
        }  
    }
    
    return count;
    
}