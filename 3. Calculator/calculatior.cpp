// - This Is A Simple Calculaor,
// - Made By RABIUL HASSAN (22170910)

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void setColor(unsigned textColor, unsigned bgColor);
void menu();
void addition();
void subtraction();
void multiplication();
void division();
void mixed();


// mixed functions
void mixedAddition();
void mixedSubtraction();
void mixedMultiplication();
void mixedDivision();

// response msg show functions
void correct();
void wrong();


int main(){

    int input;

    do{
        // show menu
        menu();

        // take input from user
        cout<<"\tPlease Choose:";

        while(!(cin>>input) || (input<=0) || (input>6)){
            cin.clear();
            cin.sync();

            cout<<"\n\tInvalid Input, Please Choose Again:";
        }


        switch(input){
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                mixed();
                break;
            case 6:
                cout<<"\n\t====== Exit Program ======\n\n";
                break;
            default:
                cout<<"\nInvalid Input\n";
                break;
        }


        if(input!=6){
            cout<<"\n\tPress any key to return to the menu:";
            getch();
            cout<<"\n\n";
        }
    }while(1);

}

// set color
void setColor(unsigned textColor, unsigned bgColor){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, textColor%16 | bgColor%16*16);
}

// function to show menu
void menu(){
    cout<<"\t|*|*************************Calculator*********************|*|\n";
    cout<<"\t|*|                                                        |*|\n";
    cout<<"\t|*|                                                        |*|\n";
    cout<<"\t|*|     1. Addition                2. Subtraction          |*|\n";
    cout<<"\t|*|                                                        |*|\n";
    cout<<"\t|*|     3. Multiplication          4. Division             |*|\n";
    cout<<"\t|*|                                                        |*|\n";
    cout<<"\t|*|     5. Mixed                   4. Exit                 |*|\n";
    cout<<"\t|*|                                                        |*|\n";
    cout<<"\t|*|                                                        |*|\n";
    cout<<"\t|*|**************CopyRight2023-RABIUL HASSAN***************|*|\n";
}


// addition
void addition(){
    cout << "\n\t================ Enter 999 to return to the menu =================\n";
    int num1, num2, res = 0;

    while(1){
        num1 = rand() % 10;
        num2 = rand() % 10;

        cout << "\n\t"<<num1<<" + "<<num2<<" = ";
        cin.clear();
        cin.sync();
        cin>>res;

        if(res == 999){
            break;
        }else if(res == num1+num2){
            correct();
        }else{
            wrong();

            while(1){
                cout << "\n\t"<<num1<<" + "<<num2<<" = ";
                cin.clear();
                cin.sync();
                cin>>res;

                if(res == num1+num2){
                    correct();
                    break;
                }else{
                    wrong();
                }
            }
        }
    }
}

// subtraction
void subtraction(){
    cout << "\n\t================ Enter 999 to return to the menu =================\n";
    int num1, num2, res = 0;

    while(1){
        num1 = rand() % 10;
        num2 = rand() % 10;

        cout << "\n\t"<<num1<<" - "<<num2<<" = ";
        cin.clear();
        cin.sync();
        cin>>res;

        if(res == 999){
            break;
        }else if(res == num1-num2){
            correct();
        }else{
            wrong();

            while(1){
                cout << "\n\t"<<num1<<" - "<<num2<<" = ";
                cin.clear();
                cin.sync();
                cin>>res;

                if(res == num1-num2){
                    correct();
                    break;
                }else{
                    wrong();
                }
            }
        }
    }
}

// multiplication
void multiplication(){
    cout << "\n\t================ Enter 999 to return to the menu =================\n";
    int num1, num2, res = 0;

    while(1){
        num1 = rand() % 10;
        num2 = rand() % 10;

        cout << "\n\t"<<num1<<" * "<<num2<<" = ";
        cin.clear();
        cin.sync();
        cin>>res;

        if(res == 999){
            break;
        }else if(res == num1*num2){
            correct();
        }else{
            wrong();

            while(1){
                cout << "\n\t"<<num1<<" * "<<num2<<" = ";
                cin.clear();
                cin.sync();
                cin>>res;

                if(res == num1*num2){
                    correct();
                    break;
                }else{
                    wrong();
                }
            }
        }
    }
}

// division
void division(){
    cout << "\n\t================ Enter 999 to return to the menu =================\n";
    int num1, num2, res = 0;

    while(1){
        num1 = rand() % 100;
        num2 = rand() % 10;

        cout << "\n\t"<<num1<<" / "<<num2<<" = ";
        cin.clear();
        cin.sync();
        cin>>res;

        if(res == 999){
            break;
        }else if(res == num1/num2){
            correct();
        }else{
            wrong();

            while(1){
                cout << "\n\t"<<num1<<" / "<<num2<<" = ";
                cin.clear();
                cin.sync();
                cin>>res;

                if(res == num1/num2){
                    correct();
                    break;
                }else{
                    wrong();
                }
            }
        }
    }
}

// mixed
void mixed(){
    do{
        int a = rand() % 5;

        if(a>0 && a<=4){
            switch(a){
                case 1:
                    mixedAddition();
                    break;
                case 2:
                    mixedSubtraction();
                    break;
                case 3:
                    mixedMultiplication();
                    break;
                case 4:
                    mixedDivision();
                    break;
                default:
                    cout<<"\nInvalid\n";
                    break;
            }
        }
    }while(1);
}

// mixed addition
void mixedAddition(){
    int num1, num2, res=0;
    num1 = rand() % 10;
    num2 = rand() % 10;

    cout << "\n\t"<<num1<<" + "<<num2<<" = ";
    cin.clear();
    cin.sync();
    cin>>res;

    if(res == num1+num2){
        correct();
    }else{
        wrong();

        while(1){
            cout << "\n\t"<<num1<<" + "<<num2<<" = ";
            cin.clear();
            cin.sync();
            cin>>res;

            if(res == num1+num2){
                correct();
                break;
            }else{
                wrong();
            }
        }
    }
}


// mixed subtraction
void mixedSubtraction(){
    int num1, num2, res = 0;

    num1 = rand() % 10;
    num2 = rand() % 10;

    cout << "\n\t"<<num1<<" - "<<num2<<" = ";
    cin.clear();
    cin.sync();
    cin>>res;

    if(res == num1-num2){
        correct();
    }else{
        wrong();

        while(1){
            cout << "\n\t"<<num1<<" - "<<num2<<" = ";
            cin.clear();
            cin.sync();
            cin>>res;

            if(res == num1-num2){
                correct();
                break;
            }else{
                wrong();
            }
        }
    }
}

// mixed multiplication
void mixedMultiplication(){
    int num1, num2, res = 0;

    num1 = rand() % 10;
    num2 = rand() % 10;

    cout << "\n\t"<<num1<<" * "<<num2<<" = ";
    cin.clear();
    cin.sync();
    cin>>res;

    if(res == num1*num2){
        correct();
    }else{
        wrong();

        while(1){
            cout << "\n\t"<<num1<<" * "<<num2<<" = ";
            cin.clear();
            cin.sync();
            cin>>res;

            if(res == num1*num2){
                correct();
                break;
            }else{
                wrong();
            }
        }
    }
}

// mixed division
void mixedDivision(){
    int num1, num2, res = 0;

    num1 = rand() % 100;
    num2 = rand() % 10;

    cout << "\n\t"<<num1<<" / "<<num2<<" = ";
    cin.clear();
    cin.sync();
    cin>>res;

    if(res == num1/num2){
        correct();
    }else{
        wrong();

        while(1){
            cout << "\n\t"<<num1<<" / "<<num2<<" = ";
            cin.clear();
            cin.sync();
            cin>>res;

            if(res == num1/num2){
                correct();
                break;
            }else{
                wrong();
            }
        }
    }
}

// to print correct msg
void correct(){
    setColor(10, 0);
    cout << "\t\t--Right";
    setColor(7, 0);
}
// to print wrong msg
void wrong(){
    setColor(12, 0);
    cout << "\t\t--Wrong. Please Try Again...";
    setColor(7, 0);
}
