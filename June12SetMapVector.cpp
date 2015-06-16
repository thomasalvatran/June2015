#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main() {
  set<string> names;
  names.insert("Romeo");
  names.insert("Juliet");
  names.insert("Henry");
  set<string>::iterator pos;
  for (pos = names.begin(); pos != names.end(); pos++)
    cout << *pos << " ";
  cout << endl;

  vector<int> v(10);
  v.push_back(2);
  v.pop_back();
  v[1] = 111;
  vector<int>::iterator pos1;
  for (int k = 0; k < v.size(); k++) {
    cout << v[k] << ' ';
    //     cout << *pos1 << " ";
  }
  for (int k = 1; k <= 16; k++) {
    if (v.size() < k) {
      cout << "vector size before calling Expand: " << v.size() << endl;
      //        Expand(v);
      cout << "vector size after calling Expand: " << v.size() << endl;
    }
    v[k] = k;
  }
  map<string, long double> scores;
  scores["Tom"] = 90;
  scores["Dick"] = 86;
  scores["Harry"] = 100;
  scores["Tovantran"] = 732-619-2771;
  map<string, long double>::iterator pos2;
  for (pos2 = scores.begin(); pos2 != scores.end(); pos2++) {
    cout << "The score of " << pos2->first << " is " << pos2->second << "\n";
  }
}

