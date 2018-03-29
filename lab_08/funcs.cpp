#include <iostream>
#include <cctype>
#include <string>
#include <fstream> //ifstream include


using namespace std;

//task A
string removeLeadingSpaces(string line){

    for(int i = 0; i < line.length(); i++){
        if(isspace(line[i])){
            // Not sure if we are allowed to use .erase()
            line.erase(line.begin()+i);
        } else {
            return line;
        }
    }

}

/*
Here is Quymbee's old code
//task B
// This name should be different
string countChar(string line, char c){
    int count = 0;
    bool openBlock = false;


    ifstream fin("tests.txt");

    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }

    while(fin >> line){
        for(int i = 0; i < fin.length(); i++){
            string line2 = removeLeadingSpaces(line);

            if(line2[i] == '{'){
                count++;
                openBlock = true;
            } else if(line2[i] == '}'){
                openBlock = false;
            }
            if(openBlock){
              // This should be a /t instead of several spaces
                line2.insert(0, "    ");
            }

            return line;
        }
    }

    fin.close();
}
*/

// Jordan's code
int countChar(string line, char c){
  int count = 0;
  for(int i = 0; i < line.length(); i++){
    if(line[i]==c){
      count++;
    }
  }
  return count;
}

string addspace(string line,int block){
  string ans = "";
  for(int i = 0; i < block; i++){
    ans += "\t";
  }
  return ans + line;
}


int main(){
  string line;
  string ans = "";
  int blocks = 0;
  while(getline(cin, line)){
    blocks -= countChar(line, '}');
    ans +=  addspace(line, blocks);
    blocks += countChar(line, '{');
    ans += "\n";
  }
  cout << ans << endl;
  return 0;
}
