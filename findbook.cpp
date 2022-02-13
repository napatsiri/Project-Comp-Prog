#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <fstream>
#include <cstddef>
using namespace std;

string need;
string ans;
string book;
vector<string> A;
int type;

void start(){
    cout << " /)/)\n";
    cout << "( . .)\n";
    cout << "(  Welcome to your library\n";
}

void func(){
    cout << "What do you need to do\n";
    cout << "A - Search for book\n";
    cout << "B - Borrow books\n";
    cout << "C - Return books\n";
    cout << "D - Book a reading room\n";
    cout << "E - Do the quiz\n";
}

void booktype(){
    cout << "Book type                Code\n" <<endl;

    cout << "1  - All of books       (001-506)\n";
    cout << "2  - General            (A01-A50)\n";
    cout << "3  - Science            (B01-B53)\n";
    cout << "4  - Math               (C01-C33)\n";
    cout << "5  - Novel              (D01-D69)\n";
    cout << "6  - Documentary        (E01-E58)\n";
    cout << "7  - Politics           (F01-F52)\n";
    cout << "8  - Linguistics        (G01-G38)\n";
    cout << "9  - Psychology         (H01-H49)\n";
    cout << "10 - Management         (J01-J55)\n";
    cout << "11 - Technology         (K01-K49)\n";
    cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡";
}

void seach(){
    ofstream dest;//เปิดไฟล์เปล่า
    dest.open ("found.txt");
    //หาชื่อหนังสือที่ผู็ใช้พิมมาในtxtแล้วเก็บไว้ในไฟล์เปล่า
    int count = 0;//ให้รีเซ็ตทุกครั้งเวลาหาใหม่
    for(unsigned int i = 0; i < A.size(); i++){
        int check = 0;
        for(unsigned int j = 0; j < book.size(); j++){
             if(book[j] != toupper(A[i][j])){//ทำให้เป็นตัวใหญ่
                check = 1;
                break;
            }
        }
        if(check == 0){
            count++;    //นับจำนวนหนังสือที่เจอ
            dest << A[i] << "\n";
        }
    }
    dest.close();//ปิดไฟล์ dest

    cout << "Number of volumes found : " << count <<endl;
    if (count == 0){
        cout << "Not found";
    }
            
    if(count > 0){ 
        ifstream source;
        source.open("found.txt");
        string textline;
        while (getline(source,textline)){
            cout << textline <<'\n';
            }
    source.close();//จบการค้นหา
    } 
}

void list(){
                cout << "What kind of book do you want?\n";
                cout << "Please enter your answer in number\n";
                cout << "type : ";
                cin >> type;  
                cout << endl;
                if(type == 1){
                        ifstream source;
                        source.open("All.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "------------- End of 1st file ---------------";
                        source.close();
                }else if(type == 2){
                        ifstream source;
                        source.open("General.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "------------- End of 1st file ---------------";
                        source.close();
                }else if(type == 3){
                        ifstream source;
                        source.open("Science.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "------------- End of 1st file ---------------";
                        source.close();
                }else if(type == 4){
                        ifstream source;
                        source.open("Math.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "------------- End of 1st file ---------------";
                        source.close();
                }else if(type == 5){
                        ifstream source;
                        source.open("Novel.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "------------- End of 1st file ---------------";
                        source.close();
                }else if(type == 6){
                        ifstream source;
                        source.open("Documrntary.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "------------- End of 1st file ---------------";
                        source.close();
                }else if(type == 7){
                        ifstream source;
                        source.open("Politics.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "------------- End of 1st file ---------------";
                        source.close();
                }else if(type == 8){
                        ifstream source;
                        source.open("Language.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "------------- End of 1st file ---------------";
                        source.close();
                }else if(type == 9){
                        ifstream source;
                        source.open("Psychology.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "------------- End of 1st file ---------------";
                        source.close();
                }else if(type == 10){
                        ifstream source;
                        source.open("Management.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "------------- End of 1st file ---------------";
                        source.close();
                }else if(type == 11){
                        ifstream source;
                        source.open("Technology.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "------------- End of 1st file ---------------";
                        source.close();
                        }
}//จบการดูรายชื่อนังสือ  

void namebook(){
    cout << "What is the name of the desired book?\n";
    cout << "Name book : ";
    cin.ignore();
    getline(cin,book);  //รับชื่อหนัง
    for(unsigned int i = 0;i < book.size(); i++){ 
        book[i] = toupper(book[i]);// ทำให้ book เป็นตัวใหญ่หมด
    }
}

void puttype(){
    cout << "What kind of book do you want?\n";
    cout << "Please enter your answer in number\n";
    cout << "type : ";
    cin >> type;
    cin.ignore();
}

void findintype(){
    if(type == 1){
                ifstream source;
                source.open("All.txt"); //ไฟล์ที่ใช้หา
                string textline;
                while(getline(source,textline)){
                A.push_back(textline); 
                }
            source.close();    
            }else if(type == 2){
               ifstream source;
                source.open("General.txt"); //ไฟล์ที่ใช้หา
                string textline;
                while(getline(source,textline)){
                A.push_back(textline); 
                }
            source.close();   
            }else if(type == 3){
                ifstream source;
                source.open("Science.txt"); //ไฟล์ที่ใช้หา
                string textline;
                while(getline(source,textline)){
                A.push_back(textline); 
                }
            source.close();    
            }else if(type == 4){
                ifstream source;
                source.open("Math.txt"); //ไฟล์ที่ใช้หา
                string textline;
                while(getline(source,textline)){
                A.push_back(textline); 
                }
            source.close();  
            }else if(type == 5){
                ifstream source;
                source.open("Novel.txt"); //ไฟล์ที่ใช้หา
                string textline;
                while(getline(source,textline)){
                A.push_back(textline); 
                }
            source.close();    
            }else if(type == 6){
                ifstream source;
                source.open("Documentary.txt"); //ไฟล์ที่ใช้หา
                string textline;
                while(getline(source,textline)){
                A.push_back(textline); 
                }
            source.close();    
            }else if(type == 7){
                ifstream source;
                source.open("Politics.txt"); //ไฟล์ที่ใช้หา
                string textline;
                while(getline(source,textline)){
                A.push_back(textline); 
                }
            source.close();    
            }else if(type == 8){
                ifstream source;
                source.open("Language.txt"); //ไฟล์ที่ใช้หา
                string textline;
                while(getline(source,textline)){
                A.push_back(textline); 
                }
            source.close();    
            }else if(type == 9){
                ifstream source;
                source.open("Psycology.txt"); //ไฟล์ที่ใช้หา
                string textline;
                while(getline(source,textline)){
                A.push_back(textline); 
                }
            source.close();    
            }else if(type == 10){
                ifstream source;
                source.open("Managemant.txt"); //ไฟล์ที่ใช้หา
                string textline;
                while(getline(source,textline)){
                A.push_back(textline); 
                }
            source.close();    
            }else if(type == 11){
                ifstream source;
                source.open("Technology.txt"); //ไฟล์ที่ใช้หา
                string textline;
                while(getline(source,textline)){
                A.push_back(textline); 
                }
            source.close();
            }
}

int main()
{
    start();
    cout << "\n";
    func();
    cout << "\n";
    cout << "You need to : ";
    cin >> need;

    if(need == "A"){
        
        cout << "\n" << "\n";
        booktype();

        cout << "\nWhat kind of books do you want to find?\n";
        cout << "Do you know the type of books? (Y/N) : ";
        cin >> ans;
        cin.ignore();
        cout << "\n";

        if(ans == "N"){  //ไม่รู้ประเภทหนังสือรู้แต่ชื่อ
            
            namebook();

            ifstream source;
            source.open("All.txt"); //ไฟล์ที่ใช้หา
            string textline;
            while(getline(source,textline)){
                A.push_back(textline); 
            }
            source.close();//ปิดไฟล์ source ไม่งั้นมันจะไปซ้ำกับไฟล์ข้างล่าง

            seach();
            
            //ถามว่าคุณต้องการดูหนังสือประเภทอื่นอีกหรือไม่ void exit();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        }//จบการค้นหาในAll
        
        if(ans == "Y"){

            booktype();

            cout << "\nWould you like to see a list of books in this genre? (Y/N) : ";
            cin >> ans;

            if(ans == "Y"){

                list();
                //ถามว่าคุณต้องการดูหนังสือประเภทอื่นอีกหรือไม่ void exit();
            }

            if(ans == "N"){
        
            namebook();
            puttype();
            findintype();
            seach();
            }
        }
    }

    return 0;
}                   

            
        
        
    

//ใดๆควรทำประวัติการค้นหา
                //else
                //cout << "Please answer according to the options./n";
                //แล้วก็วนลูปไปถามว่า "Would you like to see a list of books in this genre? (Y/N) : " <<endl;

//void exit(){
    //cout << "Would you like to see other types of book? (Y/N) : ";
    //cin >> ans;

        //if(ans == "Y") //continue;

        //if(ans == "N"){
           // func();
           // cout << "You need to : \n";
            //cin >> need;

            //if(need == "X") break;
//}