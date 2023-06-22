// - This Is A Simple Program (Ticketing System) of C++,
// - Made By RABIUL HASSAN (22170910)

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void menu(); // main menu
void setColor(unsigned textColor, unsigned bgColor); // Manage text color and background color

// menu functions
void createTheater(); // create theater with row can column
void showStatus(); // show all ticket status
void reserveTicket(); // reserve ticket with user input
void saleTicket(); // sale ticket with user input
void cancelReservation(); // cancel reserved ticket
void refundTicket(); // cancel sold ticket
void searchTicket(); // check single ticket status

// global variables
char available = 15, reserved = 6, sold = 30;

// Ticket Class
class Ticket {
    private:
    int  row, col, sold, reserved, **seat;

    public:

    Ticket(int row=0,int col=0){ // constructor method
        row=row;
        col=col;
        sold=0;
        reserved=0;

        initTicket(10, 10); // automatic call itself (a theater will be create 10 x 10)
    }
    ~Ticket(){

    }

    bool setRow(int r){
        if(r>0){
            row=r;
            return true;
        }
        return false;
    }
    bool setCol(int c){
        if(c>0){
            col=c;
            return true;
        }
        return false;
    }

    getRow(){
        return row;
    }
    getCol(){
        return col;
    }
    getSold(){
        return sold;
    }
    getReserved(){
        return reserved;
    }

    bool initTicket(int row, int col){
        sold=0;
        reserved=0;

        if(!setRow(row)){
            setColor(12, 0);
            cout << "\n\tNumber of rows must be more than 0!\n";
            setColor(7, 0);
            return false;
        }
        if(!setCol(col)){
            setColor(12, 0);
            cout << "\n\tNumber of column must be more than 0!\n";
            setColor(7, 0);
            return false;
        }

        // set seat
        seat = new int* [row];
        if(!seat){
            setColor(12, 0);
            cout << "\n\tMemory allocated failed!\n";
            setColor(7, 0);
            return false;
        }

        int i,j;
        for(i=0; i<row; i++){
            seat[i] = new int [col];
            if(!seat[i]){
                setColor(12, 0);
                cout << "\n\tMemory allocated faild!\n";
                setColor(7, 0);
                return false;
            }
        }

        for(i=0; i<row; i++){
            for(j=0; j<col; j++){
                seat[i][j] = 0;
            }
        }
        return true;
    }

    // row and column number validate
    bool rowColValidate(int r, int c){
        if(r < 0 || r >= row){
            setColor(12, 0);
            cout << "\n\tThe row is out of bounds!" << endl;
            setColor(7, 0);
            return false;
        }
        if(c < 0 || c >= col){
            setColor(12, 0);
            cout << "\n\tThe col is out of bounds!" << endl;
            setColor(7, 0);
            return false;
        }

        return true;
    }

    // show tickets
    bool showTickets(){
        int i,j, avaiable_t = 0, reserved_t = 0, sold_t = 0;
        char available = 15, reserved = 6, sold = 30;

        cout << "\n";
        for(i=0; i<row; i++){
            cout << "\t";
            for(j=0; j<col; j++){
                if(seat[i][j] == 1){
                    setColor(3, 0);
                    cout << sold << "  ";
                    setColor(7, 0);
                    sold_t++;
                }else if(seat[i][j] == 2){
                    setColor(6, 0);
                    cout << reserved << "  ";
                    setColor(7, 0);
                    reserved_t++;
                }else{
                    cout << available << "  ";
                    avaiable_t++;
                }
            }
            cout << endl;
        }

        setColor(2, 0);
        cout << "\n\t" << available << ": " << avaiable_t << " available   " << reserved << ": " << reserved_t << " reserved   " << sold << ": " << sold_t << " sold" << endl;
        setColor(7, 0);

        return true;
    }

    // sale ticket
    bool saleTicket(int r, int c){
        if(!rowColValidate(r, c)){
            return false;
        }

        if(seat[r][c] != 1){
            seat[r][c] = 1;
            setColor(2, 0);
            cout << "\n\tThe ticket (" << r << ", " << c << ") has been sold successfully." << endl;
            setColor(7, 0);
            return true;
        }else{
            setColor(12, 0);
            cout << "\n\tThe ticket (" << r << ", " << c << ") has been sold already." << endl;
            setColor(7, 0);
            return false;
        }
    }

    // reserve ticket
    bool reserveTicket(int r, int c){

        if(!rowColValidate(r, c)){
            return false;
        }

        if(seat[r][c] == 1){
            setColor(12, 0);
            cout << "\n\tThe ticket (" << r << ", " << c << ") has been sold already. You cannot reserve." << endl;
            setColor(7, 0);
            return false;
        }else if(seat[r][c] != 2){
            seat[r][c] = 2;
            setColor(2, 0);
            cout << "\n\tThe ticket (" << r << ", " << c << ") has been reserved successfully." << endl;
            setColor(7, 0);
            return true;
        }else{
            setColor(12, 0);
            cout << "\n\tThe ticket (" << r << ", " << c << ") has been reserved already." << endl;
            setColor(7, 0);
            return false;
        }
    }

    // cancel reservation
    bool cancelReservation(int r, int c){

        if(!rowColValidate(r, c)){
            return false;
        }

        if(seat[r][c] == 2){
            seat[r][c] = 0;
            setColor(2, 0);
            cout << "\n\tThe reservation (" << r << ", " << c << ") has been  canceled successfully." << endl;
            setColor(7, 0);
            return true;
        }else{
            setColor(12, 0);
            cout << "\n\tThe ticket (" << r << ", " << c << ") have not reserved yet." << endl;
            setColor(7, 0);
            return false;
        }
    }

    // Refund Ticket
    bool refundTicket(int r, int c){
        if(!rowColValidate(r, c)){
            return false;
        }

        if(seat[r][c] == 1){
            seat[r][c] = 0;
            setColor(2, 0);
            cout << "\n\tThe ticket (" << r << ", " << c << ") has been refunded successfully." << endl;
            setColor(7, 0);
            return true;
        }else{
            setColor(12, 0);
            cout << "\n\tThe ticket (" << r << ", " << c << ") have not sold yet." << endl;
            setColor(7, 0);
            return false;
        }

        return true;
    }

    // Search Ticket
    bool searchTicket(int r, int c){
        if(!rowColValidate(r, c)){
            return false;
        }

        setColor(2, 0);
        cout << "\n\tTicket Status: ";
        if(seat[r][c] == 1){
            setColor(3, 0);
            cout << "Sold (" << sold << ")" << endl;
        }else if(seat[r][c] == 2){
            setColor(6, 0);
            cout << "Reserved (" << reserved << ")" << endl;
        }else{
            setColor(7, 0);
            cout << "\n\tAvailable (" << available << ")" << endl;
        }
        setColor(7, 0);

        return true;
    }
};

Ticket t;

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
                createTheater();
                break;
            case 2:
                showStatus();
                break;
            case 3:
                reserveTicket();
                break;
            case 4:
                saleTicket();
                break;
            case 5:
                cancelReservation();
                break;
            case 6:
                refundTicket();
                break;
            case 7:
                searchTicket();
                break;
            case 8:
                setColor(12, 0);
                cout << "\n\n\t===========   EXIT    ========\n" << endl;
                setColor(7, 0);
                break;
            default:
                cout<<"\nInvalid Input" << endl;
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
    cout<<"\t|*|***********Ticketing System***********|*|\n";
    cout<<"\t|*|                                      |*|\n";
    cout<<"\t|*|                                      |*|\n";
    cout<<"\t|*|     1. Create Theater                |*|\n";
    cout<<"\t|*|     2. Show Status                   |*|\n";
    cout<<"\t|*|     3. Reserve Ticket                |*|\n";
    cout<<"\t|*|     4. Sale Ticket                   |*|\n";
    cout<<"\t|*|     5. Cancel Reservation            |*|\n";
    cout<<"\t|*|     6. Refund Ticket                 |*|\n";
    cout<<"\t|*|     7. Search Single Ticket          |*|\n";
    cout<<"\t|*|     8. Exit                          |*|\n";
    cout<<"\t|*|                                      |*|\n";
    cout<<"\t|*|                                      |*|\n";
    cout<<"\t|*|*********CopyRight2023-RABIUL*********|*|\n";
    setColor(2, 0);
    cout<<"\tAvailable (" << available << "), Reserved (" << reserved << "), Sold (" << sold << ")\n\n";
    setColor(7, 0);
}

// create theater
void createTheater(){
    int row, col;

    setColor(2, 0);
    cout << "\n\n\t===========Create Theater==============\n" << endl;
    setColor(7, 0);
    cout<<"\tEnter row no:";
    while(!(cin>>row) || (row<0)){
        cin.clear();
        cin.sync();
        cout<<"\n\tInvalid Input, Please Choose Again:";
    }
    cout<<"\tEnter col no:";
    while(!(cin>>col) || (col<0)){
        cin.clear();
        cin.sync();
        cout<<"\n\tInvalid Input, Please Choose Again:";
    }

    if(t.initTicket(row, col)){
        t.showTickets();
    }
}


// reserve ticket
void reserveTicket(){
    int row, col;

    setColor(2, 0);
    cout << "\n\n\t===========Reserving Ticket==============" << endl;
    setColor(7, 0);

    cout<<"\tEnter row no:";
    while(!(cin>>row) || (row<0)){
        cin.clear();
        cin.sync();
        cout<<"\n\tInvalid Input, Please Choose Again:";
    }
    cout<<"\tEnter col no:";
    while(!(cin>>col) || (col<0)){
        cin.clear();
        cin.sync();
        cout<<"\n\tInvalid Input, Please Choose Again:";
    }
    if(t.reserveTicket(row, col)){
        t.showTickets();
    }
}

// cancel Reservation
void cancelReservation(){
    int row, col;

    setColor(2, 0);
    cout << "\n\n\t===========Cancel Reservation==============" << endl;
    setColor(7, 0);

    cout<<"\tEnter row no:";
    while(!(cin>>row) || (row<0)){
        cin.clear();
        cin.sync();
        cout<<"\n\tInvalid Input, Please Choose Again:";
    }
    cout<<"\tEnter col no:";
    while(!(cin>>col) || (col<0)){
        cin.clear();
        cin.sync();
        cout<<"\n\tInvalid Input, Please Choose Again:";
    }
    if(t.cancelReservation(row, col)){
        t.showTickets();
    }
}

// sale ticket
void saleTicket(){
    int row, col;

    setColor(2, 0);
    cout << "\n\n\t===========Salling Ticket==============" << endl;
    setColor(7, 0);

    cout<<"\tEnter row no:";
    while(!(cin>>row) || (row<0)){
        cin.clear();
        cin.sync();
        cout<<"\n\tInvalid Input, Please Choose Again:";
    }
    cout<<"\tEnter col no:";
    while(!(cin>>col) || (col<0)){
        cin.clear();
        cin.sync();
        cout<<"\n\tInvalid Input, Please Choose Again:";
    }
    if(t.saleTicket(row, col)){
        t.showTickets();
    }
}

// Refund Ticket
void refundTicket(){
    int row, col;

    setColor(2, 0);
    cout << "\n\n\t===========Refund Ticket==============" << endl;
    setColor(7, 0);

    cout<<"\tEnter row no:";
    while(!(cin>>row) || (row<0)){
        cin.clear();
        cin.sync();
        cout<<"\n\tInvalid Input, Please Choose Again:";
    }
    cout<<"\tEnter col no:";
    while(!(cin>>col) || (col<0)){
        cin.clear();
        cin.sync();
        cout<<"\n\tInvalid Input, Please Choose Again:";
    }
    if(t.refundTicket(row, col)){
        t.showTickets();
    }
}

// Show Status
void showStatus(){
    setColor(2, 0);
    cout << "\n\n\t===========Show All Ticket Status==============" << endl;
    setColor(7, 0);

    t.showTickets();
}

// search Ticket
void searchTicket(){
    int row, col;

    setColor(2, 0);
    cout << "\n\n\t===========Search Ticket==============" << endl;
    setColor(7, 0);

    cout<<"\tEnter row no:";
    while(!(cin>>row) || (row<0)){
        cin.clear();
        cin.sync();
        cout<<"\n\tInvalid Input, Please Choose Again:";
    }
    cout<<"\tEnter col no:";
    while(!(cin>>col) || (col<0)){
        cin.clear();
        cin.sync();
        cout<<"\n\tInvalid Input, Please Choose Again:";
    }

    t.searchTicket(row, col);
}
