#include <iostream>
#include <cctype>
#include <string>
#include <fstream> //ifstream include
#include <cstdlib> //declares exit in the scope


using namespace std;

//task A
string removeLeadingSpaces(string line){
    
    for(int i = 0; i < line.length(); i++){
        if(isspace(line[i])){
            line.erase(line.begin()+i);
        } else {
            return line;
        }
    }

}

//task B
string countChar(string line, char c){
    int count = 0;
    bool openBlock = false;
    
    ifstream fin("test.txt");
    
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }    
    
    while(fin >> line){
        for(int i = 0; i < line.length(); i++){
            

            if(line[i] == '{'){
                count++;
                openBlock = true;
            } else if(line[i] == '}'){
                openBlock = false;
            }
            if(openBlock){
                line.insert(0, "    ");
            }

            return line;
        }
    }

    fin.close();
}


int main(){

    cout << countChar("tests.txt", '{');
   
    return 0;
}