#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &book){
    ifstream source;
    source.open(filename);
    string text;
    while(getline(source,text)){
        book.push_back(text);
        
    }
}

void GetAns(string &ans){
    cin >> ans;
}


void borrowBook(vector<string> &book,vector<string> &borrowed){
    int N=book.size();
    bool k=false;
    string key;
    cout << "Please enter book's name: ";
    getline(cin,key);
    for(int i=0;i<N;i++){
        if(toUpperStr(key) == book[i]){
            k =true;
            if(k == true){
                cout << "---------------------------------\n";
                cout << "This is your " << book[i] << " GL HF\n";
                cout << "---------------------------------\n";
               borrowed.push_back(book[i]);
            }
        }
    }
    if(k==false){
        cout << "---------------------------------\n";
        cout << "Cannot found.\n";
        cout << "---------------------------------\n";  
    }

}   

void pika(vector<string> &book,vector<string> &borrowed){
    
    cout << "Do you want to borrow some books?(Yes/No): ";
    do{
        string ans;
        
        GetAns(ans);
        ans = toUpperStr(ans);
        cin.ignore();
        
        if(ans == "NO"){
            cout << "---------------------------------\n";
            cout << "This are "<< borrowed.size() << " books which you wanna borrowing\n";
            for(int i=0;i<borrowed.size();i++){
                
                cout << borrowed[i] << "\n";
            }
            cout << "Please return those book in due dates.\n";
            cout <<  "Thank you for using us.^_^\n";
            cout << setw(20) <<"Adios\n";            
            cout << "---------------------------------\n";
            break;
        } 
        else if(ans == "YES"){
            borrowBook(book,borrowed);
            cout << "Do you wanna more book?(Yes/No): ";
        }
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
            cout << "Do you want to borrow some books?(Yes/No): ";
        }
        
       
    }while(true);

}




int main()
{
    int id;
    cout << "plz enter your id: ";
    cin >> id;
    string filename = "book.txt";
    string butterfly = "pass.txt";
    vector<string> book,borrowed ;//ตัวแปรหนังสือกับหนังสือที่ถูกยืม
    importDataFromFile(filename,book);
    pika(book,borrowed);
    ofstream dest("pass.txt");
    dest << id;
    for(int i=0;i<borrowed.size();i++){
        dest << "," << borrowed[i]  ;
    }
    dest << ":\n";

    dest.close();
    string o;
    cout << "enter key";
    cin >> o;
    if(o == "y"){
        ifstream source(butterfly);
        string text;
        while(getline(source,text)){
            cout << text;
        }
    }
    
    
    return 0;
}
