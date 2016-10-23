#include "ncr.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

ncr::ncr(): duplicates(0), nonduplicates(0)
{}

ncr::ncr(string & filename) :
    duplicates(0), nonduplicates(0), invalid(0), mostFreqDuplicat(tree.begin()->second.begin())
{
        myfile.open(filename);
        if(!myfile.is_open())
        {
            cout << "file can not be opened\n";
            return;
        }
        parseFile();
}

int ncr::convertToForwardList(string line, multiset<int> &m)
{
        int num = 0;
        int numOfElements = 0;
         stringstream ss(line);
        char ch;

        while(ss >> num)
        {
            m.insert(num);
            ss >> ch;
            ++numOfElements;
        }
return numOfElements;
}


int ncr::validateInput(string &line,multiset<int> & l )
{
return convertToForwardList(line, l);
}

bool ncr::genericFind( int numOfElements ,multiset<int> & l)
{

            for( std::multiset<int>::iterator it = l.begin(); it != l.end(); ++it)
            {
                cout << *it << ", " ;
            }
            cout << endl;

            if(findElements(numOfElements, l) )
            {
                   return true;
            }

return  false;
}

bool ncr::workHourse(string &line)
{
        bool duplicate = false;
        int numOfElements = 0;
        multiset<int> l;

        if( (numOfElements = validateInput(line, l)) > 0)
        {
            if((  genericFind( numOfElements, l) ) )
            {
                result->second++;
                cout << "number of showing is " << result->second << endl;
                if(mostFreqDuplicat->second < result->second)
                    mostFreqDuplicat = result;
                duplicate = true;
                duplicates++;
            }
            else
            {
                map<multiset<int>, int> mm;
                mm.insert(std::pair<std::multiset<int>, int>(l, 1));
                tree.insert(std::pair<int, map<multiset<int>, int>>(numOfElements, mm));
                ++nonduplicates;
            }
        }
        else
        {
            invalid++;
            invalidInputs.push_front(line);
        }

return duplicate;
}

map<multiset<int>, int>::iterator ncr::getMostFreq(void)
{
    return mostFreqDuplicat;
}

bool ncr::findElements(int numOfElements , multiset<int> &l)
{
            multimap<int, map<multiset<int>, int>>::iterator it = tree.find(numOfElements);
            if(it != tree.end())
            {
                    int theKey = it->first;
                    cout << "Key found with value " << theKey << endl;

                    std::pair<multimap<int, map<multiset<int>, int>>::iterator, multimap<int, map<multiset<int>, int>>::iterator> keyRange;

                     keyRange = tree.equal_range(theKey);
                     // Iterate over all map elements with key == theKey

                    for (multimap<int, map<multiset<int>, int>>::iterator s_it = keyRange.first;  s_it != keyRange.second;  ++s_it)
                    {
                                cout << "Number of elements: " << s_it->first << endl;

                                map<multiset<int>, int>::iterator i = s_it->second.begin();
                                if(i->first == l )
                                {
                                    result = i;
                                    return true;
                                }
                    }
            }
return false;
}

void ncr::parseFile()
{
             string line;

            while( getline(myfile, line))
            {
                        workHourse(line);
            }
}

bool ncr::tryString(string line)
{
    int numOfElements = 0;
    multiset<int> l;

       if( (numOfElements = validateInput(line,l)) > 0)
       {
                if(genericFind(numOfElements, l))
                {
                    return true;
                }
       }
return false;
}

void ncr::printAll(void) const
{
        multimap<int, map<multiset<int>, int>>::const_iterator it = tree.begin();
        int sum = 0;

        for( ; it != tree.end(); ++ it)
        {
                    cout << "Numer of elements = " << it->first << endl;

                    multimap<multiset<int>, int>::const_iterator itt = it->second.begin();
                    cout << "\t\tNumber of duplicates = " << itt->second << "\n";
                    sum += itt->second;
                    cout << "\t\t" ;
                    for(multiset<int>::const_iterator i = itt->first.begin(); i != itt->first.end() ; ++i)
                    {
                        cout << *i << " " ;
                    }

                    cout << endl;
        }

        cout << "There are " << sum << " << elements" << endl;
        cout << "There are " << invalid << " elements" << endl;
}

void ncr::printInvalidInputs(void) const
{
    cout << "These are the invalid inputs found/entered: " << endl;
    for(auto l = invalidInputs.begin(); l != invalidInputs.end() ; ++l)
        cout << *l << endl;
}
