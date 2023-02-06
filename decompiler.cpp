#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<string> ReadTable()
{
    ifstream CharTable("CharTable.fcT");
    string falseCharTable;
    vector<string> tableContents;

    while (getline(CharTable, falseCharTable))
    {
        tableContents.push_back(falseCharTable);
    }

    CharTable.close();

    return tableContents;
}

int clip(int n, int lower, int upper)
{
    return std::max(lower, std::min(n, upper));
}

int main(int argc, char **argv)
{
    ifstream CharTable("CharTable.fcT");

    if (!CharTable.good())
    {
        cout << "Error: CharTable cannot be found!" << endl;
        return 1;
    }
    else if (argc < 2)
    {
        cout << "No input .fc file argument detected!" << endl;
        return 1;
    }

    vector<string> charTable = ReadTable();
    cout << argv[1] << endl;

    vector<string> finalDecode;
    ifstream MyReadFile(argv[1]);
    string falseChar;
    string argument = "";

    while (getline(MyReadFile, falseChar))
    {
        cout << falseChar << endl;
        argument += falseChar;
    }

    cout << argument << endl;

    MyReadFile.close();

    int count = 0;

    bool inClosure = false;
    string currentClosureCount = "";

    for (int i = 0; i < argument.size(); i++)
    {
        falseChar = argument[i];

        if (falseChar != "(" && falseChar != ")" && inClosure)
        {
            currentClosureCount += falseChar;
        }
        else if (!inClosure && falseChar == ">")
        {
            finalDecode.push_back(charTable[0]);
        }

        if (falseChar == "(" && !inClosure)
        {
            inClosure = true;
        }
        else if (falseChar == ")" && inClosure)
        {
            inClosure = false;
            int decode = stoi(currentClosureCount);
            if (currentClosureCount == "")
            {
                decode = 0;
            }
            decode = clip(decode, 1, charTable.size());
            finalDecode.push_back(charTable[decode-1]);
            currentClosureCount = "";
        }
        count++;
    }

    string result = "";

    unsigned int vecSize = finalDecode.size();

    for (unsigned int i = 0; i < vecSize; i++)
    {
        result += finalDecode[i];
    }

    cout << result << endl;
    cout << "writing fc-output.txt..." << endl;
    
    ofstream OutputFile("fc-output.txt");
    OutputFile << result;
    OutputFile.close();

    cout << "success!" << endl;

    system("pause");

    return 0;
}