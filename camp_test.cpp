#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::directory_iterator;

string path_parser(string path) {
    
    string last_object;
    for (char i : path){
        if (i == '/'){
            last_object.clear();
        } else{
            last_object += i;
        }}
    return last_object;
}

string path_finder(string file_to_find, string starting_point){
    
    for (const auto & file : directory_iterator(starting_point)){
            
        string path_to_file = file.path();
        cout << path_to_file << endl;
        
        string last_object_in_path = path_parser(path_to_file);

        if (file_to_find == last_object_in_path){
            cout << "Here's the path to your file: " << path_to_file << endl;
        }
        if (last_object_in_path.find(".") == string::npos){
            path_finder(file_to_find, path_to_file);
        }  
    }

}

int main() {
    string user_file;
    cout << "File that you want to find: " << endl;
    cin >> user_file;
    
    string starting_point = "/";

    path_finder(user_file, starting_point);
        
    return EXIT_SUCCESS;
}
