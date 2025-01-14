set<string> FindRepeatedSequences(string dna, int k)
{
    // Replace this placeholder return statement with your code
    set<string> output{};
    unordered_map<string,int> hmap;

    for (int i = 0; i < dna.size(); i++) {
             int end = i + k -1;
             //cout << end << "  " << s.size() << endl;
             if (end >= dna.size()) {
                 return output;
             }

             string str = dna.substr(i, k);

             if (hmap.find(str) == hmap.end()) {
                 hmap[str] = 1;
             } else {
                 hmap[str]++;
                 output.insert(str);
             }
    }

    return output;
}
