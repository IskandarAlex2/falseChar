#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Modal
{
public:
    string context;
    int index;
};

string sliceString(string str, int start, int end)
{
    string output = "";

    for (int i = start; i <= end; i++)
    {
        output += str[i];
    }

    return output;
}

vector<Modal> ReadTable()
{
    ifstream CharTable("CharTable.fcT");
    string falseCharTable;
    int CIndex = 0;
    vector<Modal> tableContents;

    while (getline(CharTable, falseCharTable))
    {
        Modal modal;

        modal.context = falseCharTable;
        modal.index = CIndex;

        tableContents.push_back(modal);
        CIndex++;
    }

    CharTable.close();

    return tableContents;
}

int LongestModalLength(vector<Modal> Table)
{
    int longest = 1;

    for (int i = 0; i < Table.size(); i++)
    {
        string str = Table[i].context;
        if (str.length() > longest)
        {
            longest = str.length();
        }
    }

    return longest;
}

int clip(int n, int lower, int upper)
{
    return std::max(lower, std::min(n, upper));
}

void sort(Modal modal[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Modal temp = modal[i];

        // Insert s[j] at its correct position
        int j = i - 1;
        while (j >= 0 && temp.context.length() > modal[j].context.length())
        {
            modal[j + 1] = modal[j];
            j--;
        }
        modal[j + 1] = temp;
    }
}

string input(string path)
{
    ifstream MyReadFile(path);
    string trueChar;
    string input = "";

    while (getline(MyReadFile, trueChar))
    {
        input += trueChar;
    }

    MyReadFile.close();
    return input;
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
        cout << "No input file argument detected!" << endl;
        return 1;
    }

    vector<Modal> Table = ReadTable();
    const int size = Table.size();
    Modal modals[size];
    int longestModal = LongestModalLength(Table);

    for (int i = 0; i < size; i++)
    {
        modals[i] = Table[i];
    }

    sort(modals, size);

    string inputArg = input(argv[1]);
    int OriLength = inputArg.length();
    string output = "";

    for (int i = 0; i < OriLength; i++)
    {
        for (int j = 0; j < size; j++)
        {
            Modal modal = modals[j];
            int length = modal.context.length();
            string process = sliceString(inputArg, i, clip(i + (length - 1), 0, OriLength));

            if (process == modal.context)
            {
                i += length - 1;
                if (modal.index == 0)
                {
                    output += (">");
                }
                else
                {
                    output += ("(" + to_string(modal.index + 1) + ")");
                }
                break;
            }
        }
    }

    cout << output << endl;
    cout << "writing fc-output.fc..." << endl;
    
    ofstream OutputFile("fc-output.fc");
    OutputFile << output;
    OutputFile.close();
    cout << "success!" << endl;

    system("pause");

    return 0;
}