#include <iostream>
#include "ncr.h"
using namespace std;

int main(int argc, char *argv[])
{

    string inputFile("input.txt");
    ncr dupl(inputFile);
    string line;
    char ch;
    bool forever = true;

    dupl.printAll();


    while(forever)
    {
        cout << "1. Try new string\n";
        cout << "2. Print number of duplicates/non duplicates seen so far" << endl;
        cout << "3. Print most frequent froup " << endl;
        cout << "4. Print invalid inputs" << endl;
        cout << "q to quit the program " << endl;
        cout << "Enter choice: ";

        cin.get(ch).ignore(1, '\n');
        cout << endl << endl;

        switch (ch) {
                case '1':
                {
                            cout << "Enter patern: ";
                            getline(cin, line);
                            bool t = dupl.tryString(line);
                            if(t )
                                cout << "Already exists" << endl;
                            else
                                    cout << "New entry" << endl;
                              cout << endl << endl;
                            break;
                 }
                case '2':
                {
                            cout << "There are " << dupl.getNumOfDuplicates() << " duplicate sets" << endl;
                            cout << "There are " << dupl.getNumOfNonDuplicates() << " nonDuplicate sets" << endl;
                            cout << endl << endl;
                    break;
                }
                case '3':
                {
                            auto x = dupl.getMostFreq();
                            cout << "Numer of repeats of same set: " << x->second << endl;
                            cout << "Elements : ";
                            for(const auto &l : x->first)
                                   cout << l << " " ;
                              cout << endl << endl;
                            break;
                }
                case '4':
                {
                             dupl.printInvalidInputs();
                             cout << endl << endl;
                    break;
                }
                case 'q':
                            forever = false;
                    break;
        }
    }


    return 0;
}
