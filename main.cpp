#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void print_vector(vector<string> vector) {
    string str;
    for(int i = 0; i < vector.size(); i++) {
        str = vector.at(i);
        str.erase(0,1);
        cout << str;
    }
}

void print_all_vector(vector<string> vector) {
    for(int i = 0; i < vector.size(); i++)
        cout << vector.at(i);
}

void apply_commands(vector<string> &vector, int field_num, string fiels_command) {
    for(int i = 0; i < vector.size(); i++) {
        
        string &str = vector.at(i);

        if ((str[0] - '0') == field_num) {
            if (fiels_command == "u") {
                transform(str.begin(), str.end(), str.begin(), ::tolower);
                
            }
            else if (fiels_command == "U") {
                transform(str.begin(), str.end(), str.begin(), ::toupper);
                
            }
            else if (fiels_command[0] == 'R') {
                char in_symbol = fiels_command[1];
                char out_symbol = fiels_command[2];
                replace( str.begin(), str.end(), in_symbol, out_symbol);
            }
            else {
                cout << "Error bad argument in command" << endl;
                return;
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    const char * file_name = argv[1];
    string command;
    string file_field;
    char file_char;
    
    vector<string> field_vector;
    
    ifstream file(file_name);
    if (file.is_open()) {
        int field_num = 0;
        file_field.clear();
        file_field += to_string(0);
        
        // read every char from file
        while (file.get(file_char)) {
            
            file_field += file_char;
            if (file_char == '\t') {
                field_vector.push_back(file_field);
                file_field.clear();
                
                field_num++;
                file_field += to_string(field_num);
                
            }
            else if (file_char == '\n') {
                field_vector.push_back(file_field);
                file_field.clear();
                
                field_num = 0;
                file_field += to_string(field_num);
            }
            else if (file_char == ' ') {
                field_vector.push_back(file_field);
                file_field.clear();
                
                file_field += to_string(field_num);
            }
            
        }
        // check if buffer is not empty, then if true put it in the vector
        if (file_field.length() > 1)
            field_vector.push_back(file_field);
        file.close();
        
    }
    else {
        cout << "Error: file \"" << file_name << "\" could not be opened" << endl;
        return 0;
    }
    
    // now apply all the commands
    for (int i = 2; i <= argc - 1; i++) {
        command = argv[i];
        int field_num = command[0] - '0';
        string field_command = command.substr(2, command.length());
        
        apply_commands(field_vector, field_num, field_command);
    }
    
    print_vector(field_vector);
    return 0;
}
