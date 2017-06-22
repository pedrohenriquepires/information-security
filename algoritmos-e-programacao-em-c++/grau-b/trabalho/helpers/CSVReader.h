#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

class CSVReader {
    private:
        fstream fs;

        void writeFile(string filePath, string content) {
            fs.open(filePath, fstream::out | fstream::trunc);

            if(fs.is_open()) {
                fs << content << endl;
            }

            fs.close();
        }

        vector<vector<string>> handleFile(string filePath) {
            string str, resultStr;
            vector<vector<string>> resultVector;

            fs.open(filePath, fstream::in);

            if(fs.is_open()) {
                while(!fs.eof()) {
                    getline(fs, str);

                    if(str != "") {
                        resultVector.push_back(buildLine(str));
                    }
                }
            }

            fs.close();

            return resultVector;
        }

        bool replaceString(string& str, const string& from, const string& to) {
            size_t start_pos = str.find(from);

            if(start_pos == string::npos) {
                return false;
            }

            str.replace(start_pos, from.length(), to);
            return true;
        }

        vector<string> buildLine(string lineStr) {
            int beginArray;
            int endArray;
            int lengthSubstr;

            // array handler
            do {
                beginArray      = lineStr.find('{');
                endArray        = lineStr.find('}');
                lengthSubstr    = (endArray + 1) - beginArray;

                if(beginArray > 0) {
                    lineStr[beginArray]     = 0; //remove {
                    lineStr[endArray]       = 0; //remove }
                    string substr           = lineStr.substr(beginArray, lengthSubstr);
                    string replacedSubstr   = lineStr.substr(beginArray, lengthSubstr);

                    replace(replacedSubstr.begin(), replacedSubstr.end(), ',', '|');
                    replaceString(lineStr, substr, replacedSubstr);
                }
            } while(beginArray > 0);

            vector<string> resultVector;
            stringstream ss(lineStr);
            string buf;

            while (getline(ss, buf, ',')) {
                resultVector.push_back(buf);
            }

            return resultVector;
        }

    public:
        CSVReader() {}

        template <class T>
        void objectParser(T object, string filePath) {
            vector<vector<string>> resultVector = this->handleFile(filePath);

            object->parse(resultVector);
        }

        template <class T>
        void objectWriter(T object, string filePath) {
            this->writeFile(filePath, object->write());
        }
    };
