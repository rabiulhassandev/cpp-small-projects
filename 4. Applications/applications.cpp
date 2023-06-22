// - This Is A Simple Applications Project,
// - Made By RABIUL HASSAN (22170910)

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>

using namespace std;

void setColor(unsigned textColor, unsigned bgColor);
void menu();

void Chicken100();
void BooksToChildren();
void criminalCarPlate();
void timesTable();
void PrintChessBoard();
void factorization();
void characterAnalysis();


int main(){

    int input;

    do{
        // show menu
        menu();

        // take input from user
        cout<<"\tPlease Choose:";

        while(!(cin>>input) || (input<=0) || (input>8)){
            cin.clear();
            cin.sync();

            cout<<"\n\tInvalid Input, Please Choose Again:";
        }


        switch(input){
            case 1:
                Chicken100();
                break;
            case 2:
                BooksToChildren();
                break;
            case 3:
                criminalCarPlate();
                break;
            case 4:
                timesTable();
                break;
            case 5:
                PrintChessBoard();
                break;
            case 6:
                factorization();
                break;
            case 7:
                characterAnalysis();
                break;
            case 8:
                setColor(2,0);
                cout<<"\n\n\n\t=============EXIT==============\n\n\n";
                setColor(7,0);
                break;
            default:
                cout<<"\nInvalid Input\n";
                break;
        }
        if(input!=8){
            cout<<"\n\tPress any key to return to the menu:";
            getch();
            cout<<"\n\n";
        }
    }while(input!=8);

}

// set color
void setColor(unsigned textColor, unsigned bgColor){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, textColor%16 | bgColor%16*16);
}

// function to show menu
void menu(){
    cout<<"\t=============================I LOVE C++==========================\n\n";

    cout<<"\t|*|*************************Applications***********************|*|\n";
    cout<<"\t|*|                                                            |*|\n";
    cout<<"\t|*|                                                            |*|\n";
    cout<<"\t|*|     1-Hundred Dollars & Hundred Chickens                   |*|\n";
    cout<<"\t|*|                                                            |*|\n";
    cout<<"\t|*|     2-Five Books to Three Children                         |*|\n";
    cout<<"\t|*|                                                            |*|\n";
    cout<<"\t|*|     3-Criminal's Car Plate                                 |*|\n";
    cout<<"\t|*|                                                            |*|\n";
    cout<<"\t|*|     4-Times Table 9x9                                      |*|\n";
    cout<<"\t|*|                                                            |*|\n";
    cout<<"\t|*|     5-Chess Board                                          |*|\n";
    cout<<"\t|*|                                                            |*|\n";
    cout<<"\t|*|     6-Factorization                                        |*|\n";
    cout<<"\t|*|                                                            |*|\n";
    cout<<"\t|*|     7-Character Analysis                                   |*|\n";
    cout<<"\t|*|                                                            |*|\n";
    cout<<"\t|*|     8-Exit                                                 |*|\n";
    cout<<"\t|*|                                                            |*|\n";
    cout<<"\t|*|                                                            |*|\n";
    cout<<"\t|*|****************CopyRight2023-RABIUL HASSAN*****************|*|\n";
}


// Hundred Dollars & Hundred Chickens
void Chicken100() {

     setColor(2,0);
     cout<<"\n\n\tZhang Qiujian, an ancient Chinese mathematician, once put forward"<<endl;

     cout<<"\n\tthe famous problem of \"a hundred dollars buys a hundred chickens\""<<endl;

     cout<<"\n\tA rooster's price is 5 dollars; a hen's price is 3 dollars; "<<endl;

     cout<<"\n\tthree chicks' price is one dollar. Question: To buy 100 chickens"<<endl;

     cout<<"\n\twith 100 dollars, how many are each of the roosters, hens and chickens?"<<endl<<endl;
     setColor(7,0);

     int rooster,hen,chicken,count=0;

     for(rooster=0; rooster<100/5; rooster++){
        for(hen=0; hen<100/3; hen++){
            chicken = 100 - rooster - hen;

            if(rooster*15 + hen *9 + chicken == 300){
                cout<<"\n\tSolution "<< ++count <<": " << "Rooster " << rooster << ", " << "Hen " << hen << ", " << "Chicken " << chicken << "." << endl;
            }
        }
     }
}

// Five Books to Three Children
void BooksToChildren() {

     setColor(2,0);
     cout<<"\n\n\tThere are five books to lend to A, B and C.\n";

     cout<<"\n\tIf everyone could borrow only one book,\n";

     cout<<"\n\thow many different ways could they borrow the books\n\n\n";
     setColor(7,0);

     int i, j, k, count = 0;

     cout<<"\t";
     for (i=1; i<=5; i++) {
        for (j=1; j<=5; j++) {
            for (k=1; k<=5; k++) {
                if ((i!=j) && (j!=k) && (k!=i)) {
                    cout<< "Solution " << setw(2) << ++count <<": "<<i<<","<<j<< ","<<k<<"  ";
                    if(count%3==0) cout<< endl << "\t";
                }
            }
        }
     }
}

// Find The Criminal's Car Plate
void criminalCarPlate() {

     setColor(2,0);
     cout<<"\n\n\tA car hit a man and ran away. No one remembers the\n";
     cout<<"\tcar plate number, only some characteristics of it.\n";

     cout<<"\n\tA said: the first two Numbers of the licence are the same;\n";

     cout<<"\n\tB said: the last two Numbers of the licence are the same,\n";
     cout<<"\tbut different from the first two.\n";

     cout<<"\n\tC is a mathematician, and he said: the four-digit car number\n";
     cout<<"\tis exactly the square of an integer.\n";

     cout<<"\n\tWhat is the car plate number?\n\n\n";
     setColor(7,0);

     int i,j,k,temp;

     for(i=0;i<=9;i++){
        for(j=0;j<=9;j++){
            if(i!=j){
                k=1000*i + 100*i + 10*j +j;
                for(temp=31;temp<=99;temp++){
                    if(temp*temp==k) cout<<"\n\tThe Criminal's Car Plate is: "<<k<<endl;
                }
            }
        }
     }
}

// Times Table 9x9
void timesTable() {
    cout<<"\n\n";
    setColor(2,0);
    int i,j;
    for(i=1; i<=9; i++){
        cout<<"\t";
        for(j=1; j<=i; j++){
          cout<<j<<"x"<<i<<"="<<setw(2)<<left<<i*j<<" ";
        }
        cout<<"\n";
    }
    setColor(7,0);
}

// Print a Chess Board
void PrintChessBoard() {
    cout<<"\n\n\t--------Print a Chess Board--------\n\n";

    int i,j,k;
    for(k=0;k<5;k++){
        cout<<"\t";
        for(i=0;i<9;i++) cout<<""<<static_cast<char>(219)<<""<<static_cast<char>(255);
        cout<<endl<<"\t";
        for(j=0;j<9;j++) cout<<""<<static_cast<char>(255)<<""<<static_cast<char>(219);
        cout<<endl;
    }
    cout<<"\n";
}

// Factorization
void factorization() {
    cout<<"\n\t=============Input 888 to exit=============\n";

    int num, temp, factors[20],i,j;

    do{
       cout<<"\n\tPlease input a valid integer: ";

       while(!(cin>>num) || (num<=0)){
           cin.clear();
           cin.sync();
           cout<<"\n\tInvalid. Please try again:";
       }
       cin.ignore(1000,'\n');
       temp=num;
       i=2, j=0;
       factors[0]=1;

       while(temp!=1){
           if(temp%i==0){
               factors[j]=i;
               temp=temp/i;
               j++;
           }else{ i++; }
        }

        setColor(2,0);
        cout<<"\n\t"<<num<<" = ";
        for(i=0;i<j-1;i++) cout<<factors[i]<<" x ";
        cout<<factors[i]<<endl;
        setColor(7,0);

    } while(num!=888);
}

// Character Analysis
void characterAnalysis() {
    char str;
    setColor(2,0);
    cout<<"\n\tString ending in 8 will return to the menu. "<<endl;
    setColor(7,0);

    do{
        int letters=0,numbers=0,spaces=0,others=0;
        cout<<"\n\tEnter a string:";
        cin >> str;

        while((str=getwchar()) != '\n'){
            if((str>='a' && str<='z') || (str>='A' && str<='Z')){
                letters++;
            }else if((str>='0') && (str<='9')){
                numbers++;
            }else if(str=='  '){
                spaces++;
            }else{ others++; }
        }
        cout<<"\n\tLetters: "<<letters<<endl;

        cout<<"\tNumbers: "<<numbers<<endl;

        cout<<"\tSpaces: "<<spaces<<endl;

        cout<<"\tOthers: "<<others<<endl;

    }while(str!='8');
}


