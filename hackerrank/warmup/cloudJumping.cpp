int jumpingOnClouds(vector<int> c) {
    int position = 0;
    int jumps = 0;
    while(position < c.size()-1){
        if(position+2 < c.size() && c[position+2] == 0){
            position += 2;
        }
        else position++;
        jumps++;
        
    }
    return jumps;
}