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
                            break;
                 }
                case '2':
                {
                    break;
                }
                case '3':
                {
                            auto x = dupl.getMostFreq();
                            cout << "Nyum of repeats " << x->second << endl;
                            for(const auto &l : x->first)
                                   cout << l << endl;
                            break;
                }
                case '4':
                {
                             dupl.printInvalidInputs();
                    break;
                }
                case 'q':
                            forever = false;
                    break;
        }
    }


    return 0;
}
