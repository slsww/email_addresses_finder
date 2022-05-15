#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <set>
#include <vector>
using namespace std;
//yinwei sun
//vector of chars in loop -> set processes the data -> push_back back to a 2d vector -> output
int main() {
    bool found = false;
    set<vector<char>> name_set = {};
    vector<char> v_char;
    vector<vector<char>> v_chars;
    string output_file_name = "copyPasteMyEmails.txt";
    cout<<"Please name the output file, press enter continue with the default name: ";
    getline(cin,output_file_name);
    if(int(output_file_name[0]) == '\0'){
        output_file_name = "copyPasteMyEmails.txt";
    }
    string file_name = "fileContainingEmails.txt";
    cout<<"Are you going to get the emails from\n" << file_name << "?\nIf not,please enter a new file name to start the program;\n If so, just "
     "press enter key : ";
    getline(cin,file_name);
    if(int(file_name[0]) == '\0'){
        file_name = "fileContainingEmails.txt";
    }
    ifstream Read;
    ofstream Write;
    Read.open("D:\\COMSC110_final\\"+file_name);
    if(Read.is_open()){
        string line;
        int emailPerLine = 0;
        while(getline(Read, line)){
            for(int i =0; line[i]!='\0'; i++){
                if(line[i]=='@'){
                    v_char={};
                    stack<char> name;
                    int at = i;
                    for(int i=at,minus=1;minus!=16;minus++){
                        if((line[i-minus]!=' ')&&(line[i-minus]!='\t')&&(line[i-minus]!=58)
                        &&(line[i-minus]!=62)&&(line[i-minus]!=59)&&(line[i-minus]!=21)
                        &&(line[i-minus]!=26)){
                            name.push(line[i-minus]);
                        }else{
                            break;
                        }
                    }
                    while(!name.empty()){
                        v_char.push_back(name.top());
                        name.pop();
                    }
                    for(int i=at,adder=0;adder!=8;adder++) {
                        v_char.push_back(line[i+adder]);
                    }
                    name_set.insert(v_char);
                }
            }
        }
        Read.close();
        Write.open("D:\\COMSC110_final\\"+output_file_name);
        for(const auto & it : name_set)
        {
            v_chars.push_back(it);
        }
        for(auto & v_char : v_chars){
            for (char j : v_char){
                Write<<j;
                cout<<j;
            }Write<<"; ";
            cout<<"; ";
            emailPerLine++;
            found = true;
            if(emailPerLine>=4){
                Write<<"\n";
                cout<<"\n";
                emailPerLine=0;
            }
        }
        if(found) {
            cout << "\n" << name_set.size() << " emails addresses found.\n";
            cout<< "\nPlease open the output file, copy and paste the data into bcc field\n";
            Write << "\n" << name_set.size() << " emails addresses found.\n";
        }
        else
            Write<<"\n"<<" Sorry, we didn't find any email address.\n";
    }Write.close();
}
