#ifndef NCR_H
#define NCR_H
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <forward_list>

using namespace std;

class ncr
{
public:
    ncr(void);
    ncr(string &filename);
    void parseFile(void);
    bool tryString(string line);
    void printAll(void) const;
    void printInvalidInputs(void) const;
    bool findLine(string& line);
    map<multiset<int>, int>::iterator getMostFreq(void);
    int getNumOfDuplicates(void);
    int getNumOfNonDuplicates(void);

private:
      int convertToForwardList(string line, multiset<int> &l);
      int convertToForwardList(string line);
      bool workHourse(string &line);
      bool findElements(int numOfElements, multiset<int> &l);
      ifstream myfile;
      int duplicates, nonduplicates;
      int invalid;
      int numOfSets;
      multimap<int, map<multiset<int>, int>>  tree;
      map<multiset<int>, int>::iterator mostFreqDuplicat;


      forward_list<string> invalidInputs;

      map<multiset<int>, int>::iterator result;
      bool genericFind(int numOfelements, multiset<int> &l);
      int validateInput(string &line);
      int validateInput(string &line,multiset<int> & l );


};

#endif // NCR_H
