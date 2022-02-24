#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<vector>
#include<cctype>
#include<cstring>
using namespace std;

int choice = 0 ; //ตัวเลือกที่ใช้กับหลายๆอย่าง
int t = 0 ; // ตัวเลือกของบรรณารักษ์
int texit = 0 ; // e = exit เป็นตัวแปรที่เอาไว้เก็บค่าเพื่อออกโปรแกรม
int l = 0 ; // l = librarian เป็นตัวแปรที่บอกว่าใส่รหัสผิดไปแล้ว 3 ครั้ง และจะกรอกรหัสผ่านในฐานะ librarian ไม่ได้อีก ต้องให้คนที่รู้มาปลดล็อค
int bb = 0;
string key;
string key2;
string filename = "pass.txt";
vector<string> namebooks;//ชื่อหนังสือที่ยืมไป
vector<int> id;//รหัสนักศึกษาที่จะใช้ในการค้นหาว่ายืมหรังสืออะไรไปบ้าง
vector<string> code;//รหัสหนังสือที่ติดบนปกหนังสือ

void TimportDataFromFile(string filename,vector<int> &id,vector<string> &code,vector<string> &namebooks){
    ifstream source;
    source.open(filename);
    string textline;
    char format[] = "%d: %[^,],%[^,],%d";
    while(getline(source,textline)){
        char text[100];
        char text1[100];
        int a,b;
        sscanf(textline.c_str(),format,&a,text,text1);
        id.push_back(a);
        code.push_back(text1);
        namebooks.push_back(text);
    }
}

void printdata(vector<int> &id, vector<string> &code, vector<string> &namebooks){
    ofstream dest;
    dest.open("pass.txt");
    for(unsigned int i = 0; i < id.size(); i++){
        dest << id.at(i) << ": " << namebooks.at(i) << "," << code.at(i) << endl;
    }
    dest.close();
}

void choiceiswrong(){
    cout << "\n**************************************\n\n";
    cout << "\tYour choice is wrong.\n\n";
    cout << "    Please enter the new choice.\n\n";
    cout << "\n**************************************\n\n";
    ::choice = 0;
}

void Texit(){
    int choice = 0;
    cout << "\n**************************************\n\n";
    cout << "\tAre you sure ? \n\n" ;
    cout << "\tYou want to leave ? (T_T)\n\n" ;
    cout << "\t1. Yes\n\n";
    cout << "\t2. No\n\n";
    cout << "\n**************************************\n\n";
    cout << "Enter your status (enter only number) : ";
    cin >> choice;
    if(choice == 1){
        cout << "\n**************************************\n\n";
        cout << "\tSee you later. (^_^)/~~ \n\n" ;
        cout << "**************************************\n\n";
        ::texit++;
    }else if(choice == 2){
        cout << "\n**************************************\n\n";
        cout << "\tHm! you brag. (-_-)# \n\n" ;
        cout << "**************************************\n\n";
    }
}

void turnbooks(vector<int> id, vector<string> code, vector<string> namebooks){
    int searchid;
    string codebook;
    int amount = 0;
    int choice = 0;
    int line = 0;
    cout << "\n**************************************\n\n";
    cout << "\tStudent ID : ";
    cin >> searchid;
    cout << "\n**************************************\n\n";
    cout << "\n**************************************\n\n";
    cout << "Which books do you want to return ?\n\n";
    int N = 1;
    for(unsigned int i = 0;i < id.size(); i++){
        if(searchid == id.at(i)){
            cout << "\t" << N << ". " << code.at(i) << "  " << namebooks.at(i) << "\n\n";
            N++;
        }
    }
    cout << "\n**************************************\n\n";
    cout << "Enter the code of book : ";
    cin >> codebook;
    for(unsigned int j = 0; j < id.size(); j++){
        if(codebook == code.at(j) && searchid == id.at(j)){
            line = j;
            amount = 1;
            cout << "\n**************************************\n\n";
            cout << "Do you want to return " << namebooks.at(j) << " ?" << "\n\n";
            cout << "1.Yes\n\n";
            cout << "2.No\n\n";
            cout << "\n**************************************\n\n";
            cout << "\tEnter your choice : ";
            cin >> choice;
            if(choice == 1){
                for(unsigned int i = line; i < id.size(); i++){
                    if(i == id.size()-1){
                        id.pop_back();
                        code.pop_back();
                        namebooks.pop_back();
                    }else{
                        id.at(i) = id.at(i+1);
                        code.at(i) = code.at(i+1);
                        namebooks.at(i) = namebooks.at(i+1);
                    }
                }
                line = 0;
                printdata(id, code, namebooks);
                cout << "\n**************************************\n\n";
                cout << "\tComplete !\n\n";
                cout << "\n**************************************\n\n";
            }else if(choice == 2){
                cout << "\n**************************************\n\n";
                cout << "\tHm! you brag. (-_-)# \n\n" ;
                cout << "**************************************\n\n";
            }
        }
    }
}

void student(){
    cout << "\n**************************************\n\n";
    cout << "\tSo what do you want ?\n\n" ;
    cout << "\t1. Search for books.\n\n";
    cout << "\t2. Borrow books.\n\n";
    cout << "\t3. Do quiz.\n\n";
    cout << "\t4. Book a reading room.\n\n";
    cout << "\t5. Or you want to leave ?\n\n";
    cout << "**************************************\n\n";
    cout << "Enter your choice (enter only number) : ";
    cin >> ::choice;
}

void librarian(){
    cout << "\n**************************************\n\n";
    cout << "\tSo what do you want ?\n\n" ;
    cout << "\t1. turnbooks.\n\n";
    cout << "\t2. Quiz.\n\n";
    cout << "\t3. Look list.\n\n";
    cout << "\t4. Back to main.\n\n";
    cout << "\t5. Or you want to leave ?\n\n";
    cout << "**************************************\n\n";
    cout << "Enter your choice (enter only number) : ";
    cin >> ::choice;
    cout << "\n";
    cout << "**************************************\n\n";
}

void status(){
    cout << "**************************************\n\n";
    cout << "\tWhat is your status ?\n\n";
    cout << "\t1. Student\n\n";
    cout << "\t2. Librarian\n\n";
    cout << "\t3. Or you want to leave ?\n\n";
    cout << "**************************************\n\n";
    cout << "Enter your status (enter only number) : ";
    cin >> ::choice;
    cout << "\n";
    cout << "**************************************\n\n";
}

void welcome(){
    cout << "**************************************\n\n";
    cout << "   Welcome to the library \\(^ 3 ^)/ \n\n";
    cout << "\t Press the Enter key\n\n";
    cout << "**************************************\n\n";
    cin.get();
}

void input(){
    cout << "**************************************\n\n";
    cout << "Enter your choice (enter only number) : ";
    cin >> ::choice;
    cout << "\n";
    cout << "**************************************\n\n";
}

void look(){
    cout << "\n**************************************\n\n";
    for(unsigned int i = 0; i < id.size(); i++){
        if(i <= 8){
            cout << i+1 << ".  " << id.at(i) << "  " << code.at(i) << "  " << namebooks.at(i) << "\n\n";
        }else{
            cout << i+1 << ". " << id.at(i) << "  " << code.at(i) << "  " << namebooks.at(i) << "\n\n";
        }
    }
    cout << "\n**************************************\n\n";
}

void passwordforlibrarian(){
    int count = 0;
    string password = "iAmlibrarian";
    string lock = "Iamsosorry";
    cout << "\n**************************************\n\n";
    cout << "\t Oh are you librarian ?\n\n";
    cout << "**************************************\n\n";
    while(true){
        if(::l == 1){
            cout << "\n**************************************\n\n";
            cout << "\tProgram is locked.\n\n";
            cout << "Enter password for unlock the program.\n\n";
            cout << "\n**************************************\n\n";
            cout << "\n**************************************\n\n";
            cout << "Enter the password : ";
            cin >> key2;
            if(key2 == "Iamsosorry"){
                cout << "\n**************************************\n\n";
                cout << "\tUnlock the program.\n\n";
                cout << "\n**************************************\n\n";
                ::l--;
            }else{
                cout << "\n**************************************\n\n";
                cout << "\tAre you sure ? (*_*)\n\n";
                cout << "      Password is not correct.\n\n";
                cout << "   Please input the new password.\n\n";
                cout << "\n**************************************\n\n";
            }
        }else{
            cout << "\n**************************************\n\n";
            cout << "Enter the password : ";
            cin >> key;
            cout << "\n**************************************\n\n";
            if(key == password){
                cout << "\n**************************************\n\n";
                cout << "\tPassword is correct.\n\n";
                cout << "     You are librarian. (^-^*)/\n\n";
                cout << "\n**************************************\n\n";
                ::bb = 1;
                break;
            }else{
                cout << "\n**************************************\n\n";
                cout << "\tAre you sure ? (*_*)\n\n";
                cout << "      Password is not correct.\n\n";
                cout << "   Please input the new password.\n\n";
                cout << "\n**************************************\n\n";
                count++;
            }
            if(count == 3){
                cout << "\n**************************************\n\n";
                cout << "\tYou are not librarian !\n\n";
                cout << "\tLock program.\n\n";
                cout << "\n**************************************\n\n";
                ::l++;
                break;
            }   
        }
    } 

}
