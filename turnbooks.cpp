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
int b = 0 ; 
int t = 0 ; // ตัวเลือกของบรรณารักษ์
int e = 0 ; // e = exit เป็นตัวแปรที่เอาไว้เก็บค่าเพื่อออกโปรแกรม
int l = 0 ; // l = librarian เป็นตัวแปรที่บอกว่าใส่รหัสผิดไปแล้ว 3 ครั้ง และจะกรอกรหัสผ่านในฐานะ librarian ไม่ได้อีก ต้องให้คนที่รู้มาปลดล็อค
int s = 0 ;

void student();
void librarian();

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<int> &id,vector<string> &code,vector<string> &namebooks,vector<int> &numbers){
    ifstream source;
    source.open(filename);
    string textline;
    char format[] = "%d,%[^,],%[^,],%d";
    while(getline(source,textline)){
        char text[100];
        char text1[100];
        int a,b;
        sscanf(textline.c_str(),format,&a,text1,text,&b);
        id.push_back(a);
        code.push_back(text1);
        namebooks.push_back(text);
        numbers.push_back(b);
    }
}

template <typename T>
T popbackdata(T &x){
    T y = x;
    return 0;
}

void choiceiswrong(){
    cout << "\n\t**************************************\n\n";
    cout << "\t\tYour choice is wrong.\n\n";
    cout << "\t    Please enter the new choice.\n\n";
    cout << "\n\t**************************************\n\n";
    ::choice = 0;
}

void exit(){
    int choice = 0;
    cout << "\n\t**************************************\n\n";
    cout << "\t\tAre you sure ? \n\n" ;
    cout << "\t\tYou want to leave ? (T_T)\n\n" ;
    cout << "\t\t1. Yes\n\n";
    cout << "\t\t2. No\n\n";
    cout << "\n\t**************************************\n\n";
    cout << "\tEnter your status (enter only number) : ";
    cin >> choice;
    if(choice == 1){
        cout << "\n\t**************************************\n\n";
        cout << "\t\tSee you later. (^_^)/~~ \n\n" ;
        cout << "\t**************************************\n\n";
        ::e++;
    }else if(choice == 2){
        cout << "\n\t**************************************\n\n";
        cout << "\t\tHm! you brag. (-_-)# \n\n" ;
        cout << "\t**************************************\n\n";
    }
}

void turnbooks(vector<int> &id, vector<string> &code, vector<string> &namebooks, vector<int> &numbers){
    ofstream dest;
    int searchid;
    string codebook;
    int amount;
    int choice;
    int line;
    cout << "\n\t**************************************\n\n";
    cout << "\t\tStudent ID : ";
    cin >> searchid;
    cout << "\n\t**************************************\n\n";
    cout << "\n\t**************************************\n\n";
    cout << "\tWhich books do you want to return ?\n\n";
    int N = 1;
    for(unsigned int i = 0;i < id.size(); i++){
        if(searchid == id.at(i)){
            cout << "\t" << N << ". " << code.at(i) << "  " << namebooks.at(i) << "  " << numbers.at(i) << "\n\n";
            N++;
        }
    }
    cout << "\n\t**************************************\n\n";
    cout << "\tEnter the code of book : ";
    cin >> codebook;
    for(unsigned int j = 0; j < id.size(); j++){
        if(codebook == code.at(j) && searchid == id.at(j)){
            line = j;
            cout << line;
            while(numbers.at(j) > 1){
                cout << "\n\t**************************************\n\n";
                cout << "\tHow many books do you want to return ?\n\n";
                cout << "\tEnter the amount : ";
                cin >> amount;
                cout << "\n\n\t**************************************\n\n";
                if(amount > numbers.at(j)){
                    cout << "\n\t**************************************\n\n";
                    cout << "\t\tError!! please new enter.\n\n";
                    cout << "\n\t**************************************\n\n";
                }else{
                    break;
                }
            }
            cout << "\n\t**************************************\n\n";
            cout << "\tDo you want to return " << namebooks.at(j) << " ?" << "\n\n";
            cout << "\t1.Yes\n\n";
            cout << "\t2.No\n\n";
            cout << "\n\t**************************************\n\n";
            cout << "\t\tEnter your choice : ";
            cin >> choice;
            if(numbers.at(j) - amount != 0) choice = 0 ;
            if(choice == 0){
                numbers.at(j) -= amount;
            }
            if(choice == 1){
                for(unsigned int i = line; i < id.size(); i++){
                    if(i == id.size()){
                        id.pop_back();
                        code.pop_back();
                        namebooks.pop_back();
                        numbers.pop_back();
                    }else{
                        id.at(i) = id.at(i+1);
                        code.at(i) = code.at(i+1);
                        namebooks.at(i) = namebooks.at(i+1);
                        numbers.at(i) = numbers.at(i+1);
                    }
                }
                line = 0;
                dest.open("rentbooks - Copy.txt");
                for(unsigned int i = 0; i < id.size(); i++){
                    dest << id.at(i) << "," << code.at(i) << "," << namebooks.at(i) << "," << numbers.at(i);
                }
                dest.close();
            }else if(choice == 2){
                cout << "\n\t**************************************\n\n";
                cout << "\t\tHm! you brag. (-_-)# \n\n" ;
                cout << "\t**************************************\n\n";
            }
        }
    }
}

void student(){
    ::s = 1;
    cout << "\n\t**************************************\n\n";
    cout << "\t\tSo what do you want ?\n\n" ;
    cout << "\t\t1. Search for books.\n\n";
    cout << "\t\t2. Borrow books.\n\n";
    cout << "\t\t3. Play quiz.\n\n";
    cout << "\t\t4. Rent readind room.\n\n";
    cout << "\t\t5. Or you want to leave ?\n\n";
    cout << "\t**************************************\n\n";
    cout << "\tEnter your choice (enter only number) : ";
    cin >> ::choice;
}

void librarian(){
    ::b = 1;
    int count = 0;
    string key;
    string key2;
    string password = "iAmlibrarian";
    string lock = "Iamsosorry";
    cout << "\n\t**************************************\n\n";
    cout << "\t\t Oh are you librarian ?\n\n";
    cout << "\t**************************************\n\n";
    while(true){
        if(::l == 1){
            cout << "\n\t**************************************\n\n";
            cout << "\t\tProgram is locked.\n\n";
            cout << "\tEnter password for unlock the program.\n\n";
            cout << "\n\t**************************************\n\n";
            cout << "\n\t**************************************\n\n";
            cout << "\tEnter the password : ";
            cin >> key2;
            if(key2 == "Iamsosorry"){
                cout << "\n\t**************************************\n\n";
                cout << "\t\tUnlock the program.\n\n";
                cout << "\n\t**************************************\n\n";
                ::l--;
            }else{
                cout << "\n\t**************************************\n\n";
                cout << "\t\tAre you sure ? (*_*)\n\n";
                cout << "\t      Password is not correct.\n\n";
                cout << "\t   Please input the new password.\n\n";
                cout << "\n\t**************************************\n\n";
            }
        }else{
            cout << "\n\t**************************************\n\n";
            cout << "\tEnter the password : ";
            cin >> key;
            cout << "\n\t**************************************\n\n";
            if(key == password){
                cout << "\n\t**************************************\n\n";
                cout << "\t\tPassword is correct.\n\n";
                cout << "\t     You are librarian. (^-^*)/\n\n";
                cout << "\n\t**************************************\n\n";
                cout << "\n\t**************************************\n\n";
                cout << "\t\tSo what do you want ?\n\n" ;
                cout << "\t\t1. turnbooks.\n\n";
                cout << "\t\t2. Quiz.\n\n";
                cout << "\t\t3. Or you want to leave ?\n\n";
                cout << "\t**************************************\n\n";
                cout << "\tEnter your choice (enter only number) : ";
                cin >> ::choice;
                break;
            }else{
                cout << "\n\t**************************************\n\n";
                cout << "\t\tAre you sure ? (*_*)\n\n";
                cout << "\t      Password is not correct.\n\n";
                cout << "\t   Please input the new password.\n\n";
                cout << "\n\t**************************************\n\n";
                count++;
            }
            if(count == 3){
                cout << "\n\t**************************************\n\n";
                cout << "\t\tYou are not librarian !\n\n";
                cout << "\t\tLock program.\n\n";
                cout << "\n\t**************************************\n\n";
                ::l++;
                break;
            }   
        }
    } 
}

void status(){
    cout << "\t**************************************\n\n";
    cout << "\t\tWhat is your status ?\n\n";
    cout << "\t\t1. Student\n\n";
    cout << "\t\t2. Librarian\n\n";
    cout << "\t\t3. Or you want to leave ?\n\n";
    cout << "\t**************************************\n\n";
    cout << "\tEnter your status (enter only number) : ";
    cin >> ::choice;
}

void welcome(){
    cout << "\t**************************************\n\n";
    cout << "\t   Welcome to the library \\(^ 3 ^)/ \n\n";
    cout << "\t\t Press the Enter key\n\n";
    cout << "\t**************************************\n\n";
    cin.get();
}

int main(){
    string filename = "rentbooks.txt";
    vector<int>numbers;//จำนวนหนังสือที่ยืมไป
    vector<string> namebooks;//ชื่อหนังสือที่ยืมไป
    vector<int> id;//รหัสนักศึกษาที่จะใช้ในการค้นหาว่ายืมหรังสืออะไรไปบ้าง
    vector<string> code;//รหัสหนังสือที่ติดบนปกหนังสือ
    importDataFromFile(filename, id, code, namebooks, numbers);

    welcome();

    while (true){
        status();
        if(::choice == 1){
            student();
            if(::choice == 1){
        
            }else if(::choice == 2){
        
            }else if(::choice == 3){

            }else if(::choice == 4){
                
            }else if(::choice == 5){
                exit();
                if(::s == 1){

                }
            }else{
                choiceiswrong();
            }
        }else if(::choice == 2){
            librarian();
            if(::choice == 1){
                turnbooks(id, code, namebooks, numbers);
            }else if(::choice == 2){

            }else if(::choice == 3){
                exit();
                if(::b == 1){
                    
                }
            }else{
                choiceiswrong();
            }
        }else if(::choice == 3){
            exit();
        }else{
            choiceiswrong();
        }

        if(::e == 1) break;
    }
    
    return 0;
}