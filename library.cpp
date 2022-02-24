#include "turnbooks.cpp"
#include "Quiz.cpp"
#include "findbook.cpp"
#include "lnwza.cpp"
#include "bookroom.cpp"

int main(){
    srand(time(0));
    
    TimportDataFromFile(filename, id, code, namebooks);
    
    start();
    
    while (true){
        status();
        if(::choice == 1){
            while(true){
                func();
                input();
                if(::choice == 1){
                    find();
                }else if(::choice == 2){
                    rent();
                }else if(::choice == 3){
                    bookroom();
                }else if(::choice == 4){
                    quiz("student");
                }else if(::choice == 5){
                    break;
                }else if(::choice == 6){
                    Texit();
                    break;
                }else{
                    choiceiswrong();
                }
            }
        }else if(::choice == 2){
            while(true){
                if(::bb == 0){
                    passwordforlibrarian();
                }else if(::bb == 1){
                    librarian();
                    if(::choice == 1){
                        turnbooks(id, code, namebooks);
                    }else if(::choice == 2){
                        quiz("librarian");
                    }else if(::choice == 3){
                        look();
                    }else if(::choice == 4){
                        ::bb = 0;
                        break;
                    }else if(::choice == 5){
                        Texit();
                        break;
                    }else{
                        choiceiswrong();
                    }
                }
            }
        }else if(::choice == 3){
            Texit();
        }else{
            choiceiswrong();
        }

        if(::texit == 1) break;
    }
    
    return 0;
}
