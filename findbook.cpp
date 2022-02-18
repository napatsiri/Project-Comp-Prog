#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <fstream>
#include <cstddef>
using namespace std;

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
    cout << "///////////////////////////////\n";
    cout << "/    What do you need to do   /\n";
    cout << "/    A - Search for book      /\n";
    cout << "/    B - Borrow books         /\n";
    cout << "/    C - Return books         /\n";
    cout << "/    D - Book a reading room  /\n";
    cout << "/    E - Do the quiz          /\n";
    cout << "///////////////////////////////\n";
}

void booktype(){
    cout << "\nBook type               Code\n";

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
    cout << "11 - Technology         (K01-K49)\n" << "\n";

}

void exit(){
    cout << "\nWhich one would you like to continue?\n";
    cout << "Please enter numbers (1-4)\n";
    cout << "1 - Search for books\n";
    cout << "2 - Search for a list of books in each genre.\n";
    cout << "3 - Search for book in each genre.\n";
    cout << "4 - Exit\n";
    cout << ": ";
}

void inall(){
    ifstream source;
            source.open("All.txt"); //ไฟล์ที่ใช้หา
            string textline;
            while(getline(source,textline)){
                A.push_back(textline); 
            }
            source.close();//ปิดไฟล์ source ไม่งั้นมันจะไปซ้ำกับไฟล์ข้างล่าง
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

    cout << "\nNumber of volumes found : " << count << "\n" <<endl;
    if (count == 0){
        cout << "Not found";
        cout << "...................................\n";
    }
            
    if(count > 0){ 
        ifstream source;
        source.open("found.txt");
        string textline;
        while (getline(source,textline)){
            cout << textline <<'\n';
            }
    source.close();//จบการค้นหา
    cout << ".......................................\n";
    } 
}

void list(){
                cout << "What kind of book do you want?\n";
                cout << "Please enter your answer in numbers (1-11)\n";
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
                        cout << "\n------------- End of All file ---------------";
                        source.close();
                }else if(type == 2){
                        ifstream source;
                        source.open("General.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "\n------------- End of General file ---------------";
                        source.close();
                }else if(type == 3){
                        ifstream source;
                        source.open("Science.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "\n------------- End of Science file ---------------";
                        source.close();
                }else if(type == 4){
                        ifstream source;
                        source.open("Math.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "\n------------- End of Math file ---------------";
                        source.close();
                }else if(type == 5){
                        ifstream source;
                        source.open("Novel.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "\n------------- End of Novel file ---------------";
                        source.close();
                }else if(type == 6){
                        ifstream source;
                        source.open("Documrntary.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "\n------------- End of Documrntary file ---------------";
                        source.close();
                }else if(type == 7){
                        ifstream source;
                        source.open("Politics.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "\n------------- End of Politics file ---------------";
                        source.close();
                }else if(type == 8){
                        ifstream source;
                        source.open("Language.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "\n------------- End of Linguistics file ---------------";
                        source.close();
                }else if(type == 9){
                        ifstream source;
                        source.open("Phychology.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "\n------------- End of Psychology file ---------------";
                        source.close();
                }else if(type == 10){
                        ifstream source;
                        source.open("Management.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "\n------------- End of Management file ---------------";
                        source.close();
                }else if(type == 11){
                        ifstream source;
                        source.open("Technology.txt");
                        string textline;
                        while (getline(source,textline)){
                            cout << textline <<'\n';
                        }
                        cout << "\n------------- End of Technology file ---------------";
                        source.close();
                        }
                else{
                    cout << "SORRY, SOMETHING WENT WRONG\n";
                    cout << "Please try again and enter the numbers (1-11)\n";
                }
            cout << "\n";
}//จบการดูรายชื่อหนังสือ  

void namebook(){
    cout << "\nWhat is the name of the desired book?\n";
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
                source.open("Phycology.txt"); //ไฟล์ที่ใช้หา
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

void nametype(){
    if(type == 1){
        cout << "\nType is all book";
    }else if(type == 2){
        cout << "\nType is General book";
    }else if(type == 3){
        cout << "\nType is Science book";
    }else if(type == 4){
        cout << "\nType is Math book";
    }else if(type == 5){
        cout << "\nType is Novel book";
    }else if(type == 6){
        cout << "\nType is Documentary book";
    }else if(type == 7){
        cout << "\nType is Politics book";
    }else if(type == 8){
        cout << "\nType is Linguistics book";
    }else if(type == 9){
        cout << "\nType is Psychology book";
    }else if(type == 10){
        cout << "\nType is Management book";
    }else if(type == 11){
        cout << "\nType is Technology book";
    }
}

int main()
{
    start();
    cout << "\n";
    func();
    cout << "\n";
    
    string need;
    cout << "You need to : ";
    cin >> need;
    cout << "---------------------------------\n";

    if(need == "A"){
        
        int choice;
        exit();
        cin >> choice;

        do{
        
        switch(choice){
        case 1:{ 
            
            cout << ".................................\n";
            namebook();
            inall();
            seach();
            exit();
            cin >> choice;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
            break;
        }
        case 2:{ //ดูรายชื่อ

            cout << ".................................\n";
            booktype();
            list();
            exit();
            cin >> choice;
            break;
        }
        case 3:{ //ดูชื่อในไทป์

            cout << ".................................\n";
            booktype();
            namebook();
            cout << "\n";
            puttype();
            findintype();
            nametype();
            seach();
            exit();
            cin >> choice;
            break;
        }   
        case 4:{
            cout << ".................................\n";
            cout << "\nHave fun with the book your find\n";
            exit(0);
        }
        default:
            exit();
            cin >> choice;
        }
        }while (choice != 4);
        
    }

}                   