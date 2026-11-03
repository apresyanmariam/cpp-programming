int countingValleys(int steps, string path) {
    int count = 0;
    int valleys = 0;
    for(const char& c : path){
        if(c == 'U') ++count;
        else --count;
        if(count == 0 && c == 'U')++valleys;
    }
    return valleys;
}