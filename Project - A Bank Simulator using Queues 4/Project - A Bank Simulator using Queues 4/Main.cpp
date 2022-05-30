#include"Queue.h"
#include"Bank.h"
// preprocess macro to reduce time complir
#define intro(Name) cout << Name<<"  Bank Simulator"; 

int main()
{
    ushort Teller=0;
    ushort coustomer=0;


    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE) ;

    COORD max_size = GetLargestConsoleWindowSize(screen);
    // to take the number of char to make the sentens in the middle of screen 
    char s[] = "Welcome in Bank Simulator";
    COORD pos; // this is typedef of struct 
    max_size.X /= 2;
    pos.X = (max_size.X - sizeof(s)) / 2;
    pos.Y =1;
    SetConsoleCursorPosition(screen, pos);
    intro("Welcome in");
    cout << std::setfill(' ') << std::setw(45) << "\nHow many tellers in the Bank?";
    cin >> Teller;
    cout << std::setfill(' ') << std::setw(40) << "Enter NUmber of Coustomer?";
    cin >> coustomer;
    if (Teller == 0)
    {
        cout << "  teller = 0 ! ,I think the Bank is closed ＼（〇_ｏ）／ ";
    }
    else if (coustomer == 0)
    {
        cout << " Dad Day No coustomer comed use the app when you have coustomer please (*^_^*)";
    }
    else
    {
        Bank B1(Teller, coustomer);
        B1.Enter_coust();
        cout << std::setfill('*') << std::setw(40) << " ";
        intro("This IS the End OF ");
        cout << std::setfill('*') << std::setw(40) << " ";
        // we use the clock know the dely in app 
        double totaltime = (end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTotal time taken " << totaltime;
        cout << "\nsec:" << sec;
    }
    


}