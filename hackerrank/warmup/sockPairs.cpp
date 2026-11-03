int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> socks;
    int count = 0;
    for(int color : ar){
        socks[color]++;
        if(socks[color] % 2 == 0)count++;
    }
    return count;
    
}
