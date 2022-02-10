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
    string need;
    cout << "Welcome to your library\n";
    cout << "What do you need to do\n";
    cout << "A - Search for book\n";
    cout << "B - Borrow books\n";
    cout << "C - Return books\n";
    cout << "D - Book a reading room\n";
    cout << "E - Do the quiz\n";
    cout << "You need to : \n";
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
        //cout << "type : ";
        
        while(true){
        cout << "\nWhat kind of books do you want to find?\n";
        string ans;
        cout << "Do you know the type of books? (Y/N) : \n";
        cin >> ans;
        cin.ignore();

        if(ans == "N"){
            cout << "What is the name of the desired book?\n";
            cout << "Name book : ";
            string book;
            getline(cin,book);  //รับชื่อหนัง
            vector<string> B;            
            while(getline(cin,book)){   //ทำให้ชื่อหนังสือเป็นตัวใหญ่ทั้งหมด
                int i = 0;
                B[i] = toupper(book[i]);
                i++;
            }

            ifstream source;
            source.open("All.txt"); //ไฟล์ที่ใช้หา
            string textline;
            vector<string> A;
            while(getline(source,textline)){
                A.push_back(textline); 
            }

            //เปิดไฟล์เปล่า
            ofstream dest;
            dest.open ("found.txt");
            //หาชื่อหนังสือที่ผู็ใช้พิมมาในtxtแล้วเก็บไว้ในไฟล์เปล่า
            int count;
            for(unsigned int i = 0; i < A.size(); i++){
                int check = 0;
                for(unsigned int j = 0; j < sizeof(B); j++){
                    if(book[j] != A[i][j]){
                        check = 1;
                        break;
                    }
                }
                if(check == 0){
                    dest << A[i] << "\n";
                }
            }

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
            cout << "1 - All of books       (001-506)\n";
            cout << "2 - General            (A01-A50)\n";
            cout << "3 - Science            (B01-B53)\n";
            cout << "4 - Math               (C01-C33)\n";
            cout << "5 - Novel              (D01-D69)\n";
            cout << "6 - Documentary        (E01-E58)\n";
            cout << "7 - Politics           (F01-F52)\n";
            cout << "8 - Linguistics        (G01-G38)\n";
            cout << "9 - Psychology         (H01-H49)\n";
            cout << "10 - Management         (J01-J55)\n";
            cout << "11 - Technology        (K01-K49)\n";
            cout << "Please enter your answer in number";
            cout << "type : ";
            

            string ans;
            cout << "\nWould you like to see a list of books in this genre? (Y/N) : " <<endl;
            cin >> ans;

            if(ans == "Y"){

                int type;
                cout << "What kind of book do you want?\n";
                cin >> type;    //ต้องทำเป็นcaseมั้ยสไลด์9
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

                    if(ans == "Y"){
                        //ไปที่บรรทัดที่120
                    }
                //ถ้าเอาอีกก็เอาอีกถ้าไม่ก็ถามว่าคุณต้องการไปทำไรต่อยืมคืนหรือควิซบลาๆ

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
                    }

            }

            if(ans == "N"){
                
                int type;
                cout << "What kind of book do you want?\n";
                cin >> type;
                cin.ignore();
                string Namebook;
                cout << "The name of book you want to serch?\n";
                cout << "Name : " <<endl;
                getline(cin,Namebook);

                //ค้นหาชื่อหนังสือในเฉพาะไทป์ที่เลือกให้ขึ้นตัวอักษรนำหน้าที่มีทกบรรทัดไม่ใช่ที่เจอแค่บรรทัดแรกแล้วหยุด
                //ถ้ามีมีให้ขึ้นว่าคุรต้องการหนังสืออื่นอีกมั้ยแล้วกลับไปที่หน้าไทป์ หรือถามว่าต้องการไปฟังชันคืนยืมหรือไม้
                //ถ้าไม่มีให้ขึ้นหาไม่เจออาจอยู่ในไทปือื่นหรือไม่มี
                //ถามว่าคุณต้องการดูหนังสือประเภทอื่นอีกหรือไม่
                cout << "Would you like to see other types of book? (Y/N) : ";
                cin >> ans;

                    if(ans == "Y"){
                        //ไปที่บรรทัดที่120
                    }
                //ถ้าเอาอีกก็เอาอีกถ้าไม่ก็ถามว่าคุณต้องการไปทำไรต่อยืมคืนหรือควิซบลาๆ

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
            