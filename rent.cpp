#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;

int aidee;
vector<string> gbook,borrowed,a,b,c,d,e,f,g,h,i,j,codes,oldbook ;//ตัวแปรสำคัญๆ

string toUpperStrX(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void old_book(vector<string> &oldbook){
    ifstream source;
    source.open("pass.txt");
    string text;
    while(getline(source,text)){
        oldbook.push_back(text);
        
    } 
}
void allbook(vector<string> &gbook){
    ifstream source;
    source.open("All.txt");
    string text;
    while(getline(source,text)){
        gbook.push_back(text);
        
    } 
}
void general(vector<string> &a){
    ifstream source;
    source.open("General.txt");
    string text;
    while(getline(source,text)){
        a.push_back(text);
        
    } 
}
void science(vector<string> &b){
    ifstream source;
    source.open("Science.txt");
    string text;
    while(getline(source,text)){
        b.push_back(text);
        
    } 
}
void math(vector<string> &c){
    ifstream source;
    source.open("Math.txt");
    string text;
    while(getline(source,text)){
        c.push_back(text);
        
    } 
}
void novel(vector<string> &d){
    ifstream source;
    source.open("Novel.txt");
    string text;
    while(getline(source,text)){
        d.push_back(text);
        
    } 
}
void documentary(vector<string> &e){
    ifstream source;
    source.open("Documentary.txt");
    string text;
    while(getline(source,text)){
        e.push_back(text);
        
    } 
}
void politic(vector<string> &f){
    ifstream source;
    source.open("Politics.txt");
    string text;
    while(getline(source,text)){
        f.push_back(text);
        
    } 
}
void language(vector<string> &g){
    ifstream source;
    source.open("Language.txt");
    string text;
    while(getline(source,text)){
        g.push_back(text);
        
    } 
}
void psycho(vector<string> &h){
    ifstream source;
    source.open("Phychology.txt");
    string text;
    while(getline(source,text)){
        h.push_back(text);
        
    } 
}
void manage(vector<string> &i){
    ifstream source;
    source.open("Management.txt");
    string text;
    while(getline(source,text)){
        i.push_back(text);
        
    } 
}
void techno(vector<string> &j){
    ifstream source;
    source.open("Technology.txt");
    string text;
    while(getline(source,text)){
        j.push_back(text);
        
    } 
}


void getAns(string &ans){
    cin >> ans;
    ans=toUpperStrX(ans);
}


void borrowBook(vector<string> &gbook,vector<string> &borrowed){ //โค้ดยืมหนังสือ ไว้ใส่ในปิกาจู
    int N=gbook.size();
    bool k=false;
    string key,i;
    cout << "Please enter book's name: ";
    getline(cin,key);
    for(int i=0;i<N;i++){
        if(toUpperStrX(key) == gbook[i]){
            k =true;
            if(k == true){
                cout << "............................................................................\n\n";
                cout << " This is your " << gbook[i] << " Good Luck Have Fun.\n\n";
                cout << "............................................................................\n";
                borrowed.push_back(gbook[i]);
                
            }
        }
    }
    if(k==false){
        cout << "............................................................................\n\n";
        cout << "                            Cannot found.\n\n";
        cout << "............................................................................\n";
    }

}   


void pikachu(vector<string> &gbook,vector<string> &borrowed,int &aidee){ //โค้ดตัวหลัก
    string ans;
    bool k=true;
    cout << "Please enter your id: ";
    cin >> aidee;
    cout << "Before we start do you know the name of book which you desired?(Yes/No): ";
    do{
        getAns(ans);
        cin.ignore();
        if(ans=="YES"){
            do{
                borrowBook(gbook,borrowed);
                cout << "Do you want to borrow any?(Key No to exit,Key any to continue): ";    
                getAns(ans);
                
                cin.ignore();
                if(ans=="NO"){
                    if(borrowed.size()==1){
                        cout << "............................................................................\n\n";
                    cout << "\t\tThis is "<< borrowed.size() << " books which you wanna borrowing\n";
                    for(int i=0;i<borrowed.size();i++){
                        cout << setw(39) << borrowed[i]  <<"\n";
                    }
                    cout << "                   Please return those book in due dates.\n";
                    cout << "                       Thank you for using us.^_^\n";
                    cout << "                                 Adios\n\n";            
                    cout << "............................................................................\n\n";
                    k=false;
                    break;
                    }else{
                        cout << "............................................................................\n\n";
                        cout << "\t\tThis are "<< borrowed.size() << " books which you wanna borrowing\n";
                        for(int i=0;i<borrowed.size();i++){
                            cout << "                       " << borrowed[i]  <<"\n";
                        }
                        cout << "                   Please return those book in due dates.\n";
                        cout << "                       Thank you for using us.^_^\n";
                        cout << "                                 Adios\n\n";            
                        cout << "............................................................................\n\n";
                        k=false;
                        break;
                    }
                } 
            }while(true);
            break;
        }else if(ans=="NO"){
            cout << "............................................................................\n\n";
            cout << "                   You must \"SEACH BOOKS\" before borrow.\n\n";
            cout << "............................................................................\n\n";
            break;
        }else{
            cout << "............................................................................\n\n";
            cout << "                           Invalid command.\n\n";
            cout << "............................................................................\n";
            cout << "Before we start do you know the name of book which you desired?(Yes/No): ";
        }
    }while(true);

    
}

vector<string> getCodes(vector<string> &book,vector<string> &borrowed,vector<string> &a,vector<string> &b,vector<string> &c,vector<string> &d,vector<string> &e
        ,vector<string> &f,vector<string> &g,vector<string> &h,vector<string> &i,vector<string> &j){//โค้ดรับค่ารหัสหนังสือ
    string x;
    vector<string> codes;
    for(int y=0;y<borrowed.size();y++){
        for(int z=0;z<100;z++){
            if(borrowed[y]==a[z]){
                x = "A-"+to_string((z+1));
                codes.push_back(x);
                
            }else if(borrowed[y]==b[z]){
                x = "B-"+to_string(z+1);
                codes.push_back(x);
                
            }else if(borrowed[y]==c[z]){
                x = "C-"+to_string(z+1);
                codes.push_back(x);
                
            }else if(borrowed[y]==d[z]){
                x = "D-"+to_string(z+1);
                codes.push_back(x);
                
            }else if(borrowed[y]==e[z]){
                x = "E-"+to_string(z+1);
                codes.push_back(x);
                
            }else if(borrowed[y]==f[z]){
                x = "F-"+to_string(z+1);
                codes.push_back(x);
                
            }else if(borrowed[y]==g[z]){
                x = "G-"+to_string(z+1);
                codes.push_back(x);
                
            }else if(borrowed[y]==h[z]){
                x = "H-"+to_string(z+1);
                codes.push_back(x);
                
            }else if(borrowed[y]==i[z]){
                x = "I-"+to_string(z+1);
                codes.push_back(x);
               
            }else if(borrowed[y]==j[z]){
                x = "J-"+to_string(z+1);
                codes.push_back(x);
              
            }
        }
    }
    return codes;
}

void pass(vector<string> &borrowed,vector<string> &codes,vector<string> &oldbook,int id){//ส่งข้อมูลเข้าไฟล์pass.txt
    ofstream dest("pass.txt");

    for(int j=0;j<oldbook.size();j++){
        dest << oldbook[j] << "\n";
    }
    for(int i=0;i<borrowed.size();i++){
            dest << id << ": " << borrowed[i] << "," << codes[i] << "\n" ;
    } 
    dest.close();
}
 
int main()
{
    old_book(oldbook);
    allbook(gbook);
    general(a);
    science(b);
    math(c);
    novel(d);
    documentary(e);
    politic(f);
    language(g);
    psycho(h);
    manage(i);
    techno(j);
    pikachu(gbook,borrowed,aidee);
   
    codes = getCodes(gbook,borrowed,a,b,c,d,e,f,g,h,i,j);
    pass(borrowed,codes,oldbook,aidee);
    
   
    
    return 0;
}
