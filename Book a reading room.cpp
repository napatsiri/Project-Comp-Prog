#include<iostream>
#include<string>
#include<ctime>
#include<ctype.h>



using namespace std;

int size = 5;
int n = 3;
int Lprice = 1200;
int Sprice = 700;


struct Detail{ 
    string name;
    string studentID;
    string date;
    Detail* next;

    Detail():name("None"),studentID("None"),date("None"),next(nullptr)
    {}
};

struct Room{ 
    Detail* head;
    char roomSize;
    int roomNo;
    Room():head(nullptr),roomSize('S'),roomNo(0)
    {}

};

void program();

Room** createList();
void createRoom(Room** listRoom);
void summary(Room** listRoom);
void printRoomDetail(Room* eachRoom);
void preserveRoom(Room** listRoom);
void showMenu();
void priceSummary(Room** listRoom);

Room* findRoom(Room** listRoom ,string date , char roomSize);
void addToList(Room* room , string date);
int eachRoomCount(Room* room);
bool dateValidation(string date);



int main(){
    program();

    return 0;
}

void showMenu(){
    cout<<"\nPlease input the following choice.\n"<<endl;
    cout<<" (1) Preserve room"<<endl;
    cout<<" (2) Show Summary"<<endl;
    cout<<" (3) Exit\n"<<endl;
    cout<<"Enter choice:";
}

void program(){
    Room** room = createList();
    createRoom(room);
    cout<<"Welcome to Menu "<<endl;
    while(true){
        showMenu();
        string choice;
        cin >> choice;
        cout<<endl;
        if(choice.at(0) == '1')
            preserveRoom(room);
        else if(choice.at(0) == '2')
            summary(room);
        else if (choice.at(0) == '3'){
            cout<<"/n Exit......"<<endl;
            break;
        }
        else
            cout<<"/n Invalid input return to Menu..../n"<<endl;

        cout<<"---------------------------------\n"<<endl;

    }




}

Room** createList(){
    
    Room **room = new Room*[size];
    createRoom(room);
    return room;
}

void createRoom(Room** listRoom){
    for(int i = 0 ; i < size ; i++){
        listRoom[i] = new Room();
        listRoom[i]->roomNo +=i;

    }
    
    for(int i = 0 ; i < n ; i++)
        listRoom[i]->roomSize = 'L';
}



void summary(Room** listRoom){
    cout<<"Summary: \n"<<endl;
    for(int i = 0 ; i < size ; i++){
        printRoomDetail(listRoom[i]);
        cout<<endl;
    }
    priceSummary(listRoom);

}

void printRoomDetail(Room* eachRoom){
    cout<<"Room No: "<<eachRoom->roomNo<<"("<<eachRoom->roomSize<<")"<<endl;
    if (eachRoom->head == nullptr){
        cout<<"  No preserved yet."<<endl;
        return;
    }
    cout<<"  List:"<<endl;
    for(Detail* now = eachRoom->head ; now != nullptr ; now = now->next)
        cout<<"  Date: "<<now->date<<" Preserved by: "<<now->name<<" ID: "<<now->studentID<<endl;

}

void preserveRoom(Room** listRoom){
    cout<<"Input date (YYYY/MM/DD): ";
    string date , roomSizeString;
    cin >> date;
    cout<<"Input room size (S/L): ";
    cin >> roomSizeString;
    
    char roomSize = roomSizeString.at(0);
    if(roomSize == 's')
        roomSize = 'S';
    if(roomSize == 'l')
        roomSize = 'L';
    
    if(!dateValidation(date)){
        cout<<"Invalid date format size!!!"<<endl;
        return;
    }
    if(roomSize != 'S' && roomSize != 'L'){
        cout<<"Invalid room size!!!"<<endl;
        return;
    }
    Room* room = findRoom(listRoom , date , roomSize);
    
    if(room == nullptr){
        cout<<"There are no room left for this date ("<<date<<")"<<endl;
        return;
    }
    
    addToList(room , date);
}
bool dateValidation(string date){
    
    if(date.size() != 10 || date.at(4) != '/' || date.at(7) != '/')
        return false;
    
    for(int i = 0 ; i < 10; i++){
        
        if(i == 4 || i == 7)
            continue;
        if(!isdigit(date.at(i))){
            return false;
        }
    }
    return true;
}
void addToList(Room* room , string date){
    string studentID;
    string name;
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter Student ID: ";
    cin>>studentID;

    
    if(room->head == nullptr){
        room->head = new Detail();
        room->head->name = name;
        room->head->studentID = studentID;
        room->head->date = date;
        return;
    }

    
    Detail* now = nullptr;
    for(now = room->head ; now->next != nullptr ; now = now->next){}

        now->next = new Detail();
        now->next->name = name;
        now->next->studentID = studentID;
        now->next->date = date;
        return;
}

Room* findRoom(Room** listRoom ,string date , char roomSize){
    
    for(int i = 0 ; i < size ; i++){
        
        if(listRoom[i]->roomSize != roomSize)
            continue;

        
        bool founded = true;
        Detail* now = nullptr;

        for(now = listRoom[i]->head; now != nullptr ; now = now->next){
            if(now->date.compare(date) == 0)
                founded = false;
        }

        
        if(founded)
            return listRoom[i];
    }
    
    return nullptr;

}

void priceSummary(Room** listRoom){
    cout<<"Price summary:"<<endl;
    int sumCount = 0;
    int sumPrice = 0;
    //i < n mean L size
    for(int i = 0 ; i < size ; i++){
        int rate = Sprice;
        if(i < n)
            rate = Lprice;
        cout<<" Room No. "<<listRoom[i]->roomNo<<" Size ("<<listRoom[i]->roomSize<<") "<<"Preserved "<<eachRoomCount(listRoom[i])<<" Total price: "<<eachRoomCount(listRoom[i])*rate<<endl;
    sumCount += eachRoomCount(listRoom[i]);
    sumPrice += eachRoomCount(listRoom[i])*rate;

    }
    //รวม
    cout<<" Total preserve: "<<sumCount<<" Total price: "<<sumPrice<<endl;
}

int eachRoomCount(Room* room){
    int count = 0;
    for(Detail* now = room->head ; now != nullptr ; now = now->next)
        count++;

    return count;
}








