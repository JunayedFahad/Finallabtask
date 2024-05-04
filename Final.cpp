#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;


set<string> keywords = {"int","double","string","void","else","float","return", "case","while","do","float"} ;
bool isComment(const string& token)
{

    size_t pos = token.find("//");
    return pos !=string::npos ;

}


bool isOperator (char c)
{

    string operators = "+-*/%=<>&|^!?" ;
    return operators.find(c) != string::npos ;
}



bool isPunctuation (char c)
{
    string punctuations = ",;(){}[]";
    return punctuations.find(c) != string::npos;
}

bool isIdentifier(const string& token) {
    char c;
    bool f = false;
    int x = token.size();
    if ((token[0] >= 'A' && token[0] <= 'B') || (token[0] >= 'a' && token[0] <= 'b') || token[0] == '_') {
        for (int i = 1; i < x; i++) {
            if ((token[i] >= 'A' && token[i] <= 'B') || (token[i] >= 'a' && token[i] <= 'b') || token[i] == '_' || (token[i] >= '0' && token[i] <= '9'))
                f = true;
            else {
                f = false;
                c = token[i];
                break;
            }
        }
        if (f)
            return true;
        else {
            cout << "Invalid for character: " << c << endl;
            return false;
        }
    } else {
        cout << "Invalid for " << token[0] << endl;
        return false;
    }
}


bool isDataType(const string& token) {
    set<string> dataTypes = {"int", "float", "double", "char", "string", "void"};
    return dataTypes.find(token) != dataTypes.end();
}


int main() {
    ifstream inputFile("inputFile.txt");
    if (!inputFile.is_open()) {
        cout << "Unable to open file.\n";
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string token;
        while (iss >> token) {
            if (keywords.count(token)) {
                cout << "Keyword: " << token << endl;
            } else if (token == "#include") {
                string header;
                iss >> header;
                cout << "Header file: " << header << endl;
            } else if (isOperator(token[0])) {
                cout << "operator: " << token << endl;
            } else if (isPunctuation(token[0])) {
                cout << "punctuation: " << token << endl;
            } else if (isIdentifier(token)) {
                cout << "identifier: " << token << endl;
            } else if (isDataType(token)) {
                cout << "data yype: " << token << endl;
            }
            else if (isComment(token)) {
            cout << "comment: " << line << endl;
            }

        }
    }

    inputFile.close();

    return 0;
}




