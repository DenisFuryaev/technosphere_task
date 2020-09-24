#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    const char * file_name = "text.txt";//argv[1];
    //const char * command = argv[2];
    string file_field;
    char file_char;
    
    ifstream file(file_name);
    if (file.is_open()) {
        int field_num = 0;
        file_field.clear();
        // read every char from file
        while (file.get(file_char)) {
            
            if (file_char == '\t') {
                cout << file_field;
                file_field.clear();
                field_num++;
                cout << "(this is tab)\n";
            }
            else if (file_char == '\n') {
                cout << file_field;
                file_field.clear();
                field_num = 0;
                cout << "(this is new line)\n";
            }
            else {
                // put new char in buffer for field
                file_field += file_char;
            }
        }
        file.close();
        
    }
    else {
        cout << "Error: file \"" << file_name << "\" could not be opened" << endl;
    }
    
    return 0;
}
