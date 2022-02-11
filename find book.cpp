#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <fstream>
#include <cstddef>
using namespace std;

int main()
{
    cout << " /)/)\n";
    cout << "( . .)\n";
    cout << "( つ♡ Welcome to your library\n";

    cout << "What do you need to do\n";
    cout << "A - Search for book\n";
    cout << "B - Borrow books\n";
    cout << "C - Return books\n";
    cout << "D - Book a reading room\n";
    cout << "E - Do the quiz\n";
    cout << "You need to : \n";
    string need;
    cin >> need;

    if(need == "A"){
       
        cout << "Book type            Code\n" <<endl;
        cout << "- General            (A01-A50)\n";
        cout << "- Science            (B01-B53)\n";
        cout << "- Math               (C01-C33)\n";
        cout << "- Novel              (D01-D69)\n";
        cout << "- Documentary        (E01-E58)\n";
        cout << "- Politics           (F01-F52)\n";
        cout << "- Linguistics        (G01-G38)\n";
        cout << "- Psychology         (H01-H49)\n";
        cout << "- Management         (J01-J55)\n";
        cout << "- Technollogy        (K01-K49)\n";
        
        while(true){
        cout << "\nWhat kind of books do you want to find?\n";

        string ans;
        cout << "Do you know the type of books? (Y/N) : \n";
        cin >> ans;
        cin.ignore();

        if(ans == "N"){  //ไม่รู้ประเภทหนังสือรู้แต่ชื่อ
            cout << "What is the name of the desired book?\n";
            cout << "Name book : ";
            string book;
            getline(cin,book);  //รับชื่อหนัง
            for(unsigned int i = 0;i < book.size(); i++){    //-----------------Edit-----------------------
                book[i] = toupper(book[i]);// ทำให้ book เป็นตัวใหญ่หมด
            }

            ifstream source;
            source.open("All.txt"); //ไฟล์ที่ใช้หา
            string textline;
            vector<string> A;
            while(getline(source,textline)){
                A.push_back(textline); 
            }
            source.close();//-----------------Edit-----------------------ปิดไฟล์ source ไม่งั้นมันจะไปซ้ำกับไฟล์ข้างล่าง

            //เปิดไฟล์เปล่า
            ofstream dest;
            dest.open ("found.txt");
            //หาชื่อหนังสือที่ผู็ใช้พิมมาในtxtแล้วเก็บไว้ในไฟล์เปล่า
            int count = 0;//-----------------Edit----------------------- ให้รีเซ็ตทุกครั้งเวลาหาใหม่
            for(unsigned int i = 0; i < A.size(); i++){
                int check = 0;
                for(unsigned int j = 0; j < book.size(); j++){  //-----------------Edit-----------------------
                    if(book[j] != toupper(A[i][j])){//-----------------Edit----------------------- ทำให้เป็นตัวใหญ่
                        check = 1;
                        break;
                    }
                }
                if(check == 0){
                    count++;    //-----------------Edit----------------------- นับจำนวนหนังสือที่เจอ
                    dest << A[i] << "\n";
                }
            }
            dest.close();//-----------------Edit-----------------------ปิดไฟล์ dest

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
            source.close();
            } 

            //จบการค้นหา
            string ans;
            cout << "Do you want to search again? (Y/N) : ";
            cin >> ans;

            if(ans == "Y") continue;
            //ไปเริ่มที่บรรทัดที่39
            

            if(ans == "N"){
                cout << "What do you need to do\n";
                cout << "B - Borrow books\n";
                cout << "C - Return books\n";
                cout << "D - Book a reading room\n";
                cout << "E - Do the quiz\n";
                cout << "X - Close program\n";
                cout << "You need to : \n";
                cin >> need;

                //if(need == 'X') หยุดทุกฟังก์ชัน;
                if(need == "X") break;
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
        }
        
        if(ans == "Y"){

            cout << "Book type            Code\n" <<endl;
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
            
            string ans;
            cout << "\nWould you like to see a list of books in this genre? (Y/N) : " <<endl;
            cin >> ans;

            if(ans == "Y"){

                int type;
                cout << "What kind of book do you want?\n";
                cout << "Please enter your answer in number\n";
                cout << "type : ";
                cin >> type;    
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
                        source.open("Linguisics.txt");
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
                }
           
                //ถามว่าคุณต้องการดูหนังสือประเภทอื่นอีกหรือไม่
                cout << "Would you like to see other types of book? (Y/N) : ";
                cin >> ans;

                    if(ans == "Y") continue;

                    if(ans == "N"){
                        cout << "What do you need to do\n";
                        cout << "B - Borrow books\n";
                        cout << "C - Return books\n";
                        cout << "D - Book a reading room\n";
                        cout << "E - Do the quiz\n";
                        cout << "X - Close program\n";
                        cout << "You need to : \n";
                        cin >> need;

                        if(need == "X") break;
                    }

            }

            if(ans == "N"){
                
                int type;
                cout << "What kind of book do you want?\n";
                cout << "Please enter your answer in number\n";
                cout << "type : ";
                cin >> type;
                cin.ignore();
                cout << "What is the name of the desired book?\n";
                cout << "Name book : ";
                string book;
                getline(cin,book);  //รับชื่อหนัง
                for(unsigned int i = 0;i < book.size(); i++){    //-----------------Edit-----------------------
                book[i] = toupper(book[i]);// ทำให้ book เป็นตัวใหญ่หมด
            }

            ifstream source;
            source.open("All.txt"); //ไฟล์ที่ใช้หา
            string textline;
            vector<string> A;
            while(getline(source,textline)){
                A.push_back(textline); 
            }
            source.close();//-----------------Edit-----------------------ปิดไฟล์ source ไม่งั้นมันจะไปซ้ำกับไฟล์ข้างล่าง

            //เปิดไฟล์เปล่า
            ofstream dest;
            dest.open ("found.txt");
            //หาชื่อหนังสือที่ผู็ใช้พิมมาในtxtแล้วเก็บไว้ในไฟล์เปล่า
            int count = 0;//-----------------Edit----------------------- ให้รีเซ็ตทุกครั้งเวลาหาใหม่
            for(unsigned int i = 0; i < A.size(); i++){
                int check = 0;
                for(unsigned int j = 0; j < book.size(); j++){  //-----------------Edit-----------------------
                    if(book[j] != toupper(A[i][j])){//-----------------Edit----------------------- ทำให้เป็นตัวใหญ่
                        check = 1;
                        break;
                    }
                }
                if(check == 0){
                    count++;    //-----------------Edit----------------------- นับจำนวนหนังสือที่เจอ
                    dest << A[i] << "\n";
                }
            }
            dest.close();//-----------------Edit-----------------------ปิดไฟล์ dest

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
            source.close();
            }
                //ค้นหาชื่อหนังสือในเฉพาะไทป์ที่เลือกให้ขึ้นตัวอักษรนำหน้าที่มีทกบรรทัดไม่ใช่ที่เจอแค่บรรทัดแรกแล้วหยุด
                //ถ้ามีมีให้ขึ้นว่าคุรต้องการหนังสืออื่นอีกมั้ยแล้วกลับไปที่หน้าไทป์ หรือถามว่าต้องการไปฟังชันคืนยืมหรือไม้
                //ถ้าไม่มีให้ขึ้นหาไม่เจออาจอยู่ในไทปือื่นหรือไม่มี
                //ถามว่าคุณต้องการดูหนังสือประเภทอื่นอีกหรือไม่
                //ถามว่าคุณต้องการดูหนังสือประเภทอื่นอีกหรือไม่
                cout << "Would you like to see other types of book? (Y/N) : ";
                cin >> ans;

                    if(ans == "Y") continue;

                    if(ans == "N"){
                        cout << "What do you need to do\n";
                        cout << "B - Borrow books\n";
                        cout << "C - Return books\n";
                        cout << "D - Book a reading room\n";
                        cout << "E - Do the quiz\n";
                        cout << "X - Close program\n";
                        cout << "You need to : \n";
                        cin >> need;

                        if(need == "X") break;
                    }

                //ถ้าต้องการหาหนังสืออีกให้กลับไปหน้าไทป์

            }
        }
        
    }  
}
//ใดๆควรทำประวัติการค้นหา
                //else{
                //cout << "Please answer according to the options./n";
                //แล้วก็วนลูปไปถามว่า "Would you like to see a list of books in this genre? (Y/N) : " <<endl;
            