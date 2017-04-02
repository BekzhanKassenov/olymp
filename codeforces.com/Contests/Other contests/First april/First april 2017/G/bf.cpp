#include "testlib.h"
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

void fail(const string& message) {
    cerr << "ERROR: " << message << endl;
    exit(1);
}

string interpretCode(const string& commands)
{
    vector<unsigned char> data(1, 0);
    vector<unsigned char>::iterator dataPtr = data.begin();

    string::const_iterator instructionPtr = commands.begin();
    stack<string::const_iterator> instructionStack;

    int iterationCount = 0;
    string result;

    while (instructionPtr != commands.end())
    {
        iterationCount++;
        if (iterationCount > 50000000)
            fail("Too many instructions");

        switch (*instructionPtr)
        {
        case '<':
        {
            if (dataPtr != data.begin())
                dataPtr--;
            break;
        }
        case '>':
        {
            dataPtr++;
            if (dataPtr == data.end()) {
                if (data.size() < 30000)
                    data.push_back(0);
                dataPtr = data.end()-1;
            }
            break;
        }
        case '+':
        {
            (*dataPtr)++;
            break;
        }
        case '-':
        {
            (*dataPtr)--;
            break;
        }
        case '.':
        {
            result += (unsigned char)(*dataPtr);
            break;
        }
        case '[':
        {
            instructionStack.push(instructionPtr);

            if (*dataPtr == 0)
            {
                string::const_iterator startInstructionPtr = instructionPtr;
                while (++instructionPtr != commands.end())
                {
                    iterationCount++;
                    if (iterationCount > 50000000)
                        fail("Too many instructions");

                    if (*instructionPtr == '[')
                        instructionStack.push(instructionPtr);
                    else if (*instructionPtr == ']')
                    {
                        if (instructionStack.empty())
                            fail("Found a ']' that did not have a matching '['!");

                        string::const_iterator tempInstructionPtr = instructionStack.top();
                        instructionStack.pop();

                        if (startInstructionPtr == tempInstructionPtr)
                            break;
                    }
                }
            }
            break;
        }
        case ']':
        {
            if (instructionStack.empty())
                fail("Found a ']' that did not have a matching '['!");

            if (*dataPtr != 0)
                instructionPtr = instructionStack.top();
            else
                instructionStack.pop();

            break;
        }
        default:
            break;
        }

        if (instructionPtr == commands.end())
            fail("Invalid program");

        instructionPtr++;
    }

    if (!instructionStack.empty())
        fail("Found a '[' that did not have a matching ']'!");

    return result;
}

string readFile(const string& fileName) {
    ifstream in(fileName.c_str());
    string s, nxt;
    while (in >> nxt) {
        s += nxt;
        if (s.length() > 5000000) {
            fail("Too long program");
        }
    }

    return interpretCode(s);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fail("Usage: bf <fileName>");
    }

    cout << readFile(argv[1]);
}
