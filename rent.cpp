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
        if(key == book[i]){
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



int main()
{
    string filename = "book.txt";
    vector<string> book,borrowed;
    importDataFromFile(filename,book);
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
        }
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
        cout << "Do you wanna more book?(Yes/No): ";
       
    }while(true);

    return 0;
}