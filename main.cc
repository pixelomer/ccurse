#include <cstdlib>
#include <iostream>
#include <queue>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char **argv) {
    istream *in;
    if (argc == 1) {
        in = &cin;
    }
    else if ((argc == 3 && strcmp(argv[1], "--") == 0 &&
        (swap(argv[1], argv[2]), true)) || (argc == 2 &&
        (argv[1][0] != '-' || argv[1][1] == '\0')))
    {
        if (strcmp(argv[1], "-") == 0) {
            in = &cin;
        }
        else {
            auto file = new ifstream;
            file->open(argv[1]);
            if (file->fail()) {
                cerr << argv[0] << ": failed to open file" << endl;
                delete file;
                return EXIT_FAILURE;
            }
            in = file;
        }
    }
    else {
        cerr << "Usage: " << argv[0] << " [file]" << endl;
        return EXIT_FAILURE;
    }
    queue<string> lines;
    size_t lineLen = 0;
    string line;
    while (getline(*in, line)) {
        size_t pos;
        while ((pos = line.find('\t')) != string::npos) {
            line = line.substr(0, pos) + "    " + line.substr(pos+1);
        }
        lineLen = max(lineLen, line.size());
        lines.push(line);
    }

    string suffix;
    while (!lines.empty()) {
        auto &line = lines.front();
        if (line.size() == 0) {
            cout << endl;
            lines.pop();
            continue;
        }
        size_t start = line.size() - 1;
        static const string filter = ";{} ";
        while (start < line.size() && filter.find(line[start]) != string::npos) {
            char c = line[start--];
            if (c != ' ') {
                suffix = c + suffix;
            }
        }
        line.resize(start + 1);
        line.resize(lineLen, ' ');
        line += suffix;
        suffix.clear();
        cout << line << endl;
        lines.pop();
    }

    if (in != &cin) {
        delete in;
    }
    return EXIT_SUCCESS;
}
