#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#define CMAKE_SOURCE_DIR "/mnt/d/Documents/workspaces/cpp/GitHub/cpp-projects/CMAKE_EXPORT_COMPILE_COMMANDS_demo"
#define CMAKE_BINARY_DIR "/mnt/d/Documents/workspaces/cpp/GitHub/cpp-projects/CMAKE_EXPORT_COMPILE_COMMANDS_demo/cmake-build-debug"

using namespace std;

int main() {
    ifstream input_file("input.txt");
    ofstream output_file("output.txt");
    regex regCmakeSrc(CMAKE_SOURCE_DIR);
    regex regCmakeBin(CMAKE_BINARY_DIR);
    string line;
    while (getline(input_file, line)) {
        string binStr = regex_replace(line, regCmakeBin, "${CMAKE_BINARY_DIR}");
        string srcStr = regex_replace(binStr, regCmakeSrc, "${CMAKE_SOURCE_DIR}");
        output_file << srcStr << endl;
    }
    input_file.close();
    output_file.close();


    return 0;
}
