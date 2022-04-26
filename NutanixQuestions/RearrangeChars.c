#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

struct Key {
    int freq; // store frequency of character
    char ch;

    // function for priority_queue to store Key
    // according to freq
    bool operator<(const Key& k) const
    {
        return freq < k.freq;
    }

    Key(char c, int f) {
        freq = f;
        ch = c;
    }

    Key() {
       freq = 0;
       ch = '\0';
    }
};


void reArrangeChars(string str) {

  priority_queue<Key> pq;
  unordered_map<char,int> cmap;
  string restr;
  Key k1,k2;

  for (auto c : str) {
       if (cmap.find(c) == cmap.end()) {
           cmap[c] = 1;
       } else {
           cmap[c]++;
       }
  }

  for (auto i : cmap) {
       Key k(i.first,i.second);
       pq.push(k);
  }

  bool is_possible = true;
  char prev,curr;
  prev = '$';
  while (!pq.empty()) {
      // get key with highest freq
      k1 = pq.top();
      restr += k1.ch;
      k1.freq--;
      pq.pop();

      if (pq.empty()) {
          break;
      }

      // get key with Second highest freq
      k2 = pq.top();
      //cout << "key " << k2.ch << " "<< k2.freq << endl;
      restr += k2.ch;
      k2.freq--;
      pq.pop();


      // Re Insert them both if their freq is > 0
      if (k1.freq) {
          pq.push(k1);

      }

      if (k2.freq) {
          pq.push(k2);
      }

  }

  if (restr.size() == str.size())
      cout << restr << endl;
  else
      cout << "Not Possible, Shrinking" << endl;
      cout << restr << endl;
}

int main (int arg, char **argv) {
  string str = argv[1];
  cout << str << endl;
  reArrangeChars(str);
}
