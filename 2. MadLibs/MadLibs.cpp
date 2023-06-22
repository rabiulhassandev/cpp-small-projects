// - This Is A Simple MadLibs Game,
// - Made By RABIUL HASSAN (22170910)

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void setColor(unsigned textColor, unsigned bgColor);
void menu();
void madBoy();
void madPanda();
void madCrime();


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
                madBoy();
                break;
            case 2:
                madPanda();
                break;
            case 3:
                madCrime();
                break;
            case 4:
                cout<<"\n\tExit\n\n";
                break;
            default:
                cout<<"\nInvalid Input\n";
                break;
        }


        if(input!=4){
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
    cout<<"\t|*|***************Mad Lib Game***************|*|\n";
    cout<<"\t|*|                                          |*|\n";
    cout<<"\t|*|                                          |*|\n";
    cout<<"\t|*|     1. MadBoy           2. MadPanda      |*|\n";
    cout<<"\t|*|                                          |*|\n";
    cout<<"\t|*|     3. MadCrime         4. Exit          |*|\n";
    cout<<"\t|*|                                          |*|\n";
    cout<<"\t|*|                                          |*|\n";
    cout<<"\t|*|********CopyRight2023-RABIUL HASSAN*******|*|\n";
}


// mad boy
void madBoy(){

    string girl_name, boy_name, body_part, vehicle, place, food, word, animal;

    cout << "\tInput a girl's name:";
    cin >> girl_name;
    cout << "\tInput a boy's name:";
    cin >> boy_name;
    cout << "\tInput a body part:";
    cin >> body_part;
    cout << "\tInput a vehicle:";
    cin >> vehicle;
    cout << "\tInput a place:";
    cin >> place;
    cout << "\tInput a food:";
    cin >> food;
    cout << "\tSomething you can do with your mouth:";
    cin >> word;
    cout << "\tInput an animal:";
    cin >> animal;

    setColor(2, 0);
    cout  << "\n\n";
    cout << "\t" << girl_name << " went to " << boy_name << " and grabbed his " << body_part << "." << endl << endl;
    cout << "\t" << "\"Come on\", she said, \"We have to take the " << vehicle << " to the " << place << "\"" << endl << endl;
    cout << "\t" << "as quickly as possible where we can eat lots of " << food << "!" << endl << endl;
    cout << "\t" << "\"I hate " << food << "\", he said, \"I would much rather " << word << animal << " poop!\"" << endl;
    setColor(7, 0);
}


// mad panda
void madPanda(){

    string adj, plural_animal, plural_food, verb, single_animal;

    cout << "\tInput an adjective:";
    cin >> adj;
    cout << "\tInput a plural animal:";
    cin >> plural_animal;
    cout << "\tInput a plural food:";
    cin >> plural_food;
    cout << "\tInput a verb:";
    cin >> verb;
    cout << "\tInput a single animal:";
    cin >> single_animal;


    setColor(2, 0);
    cout  << "\n\n";
    cout << "\tThree " << adj << " " << plural_animal << " jump to the " << plural_food << " and then " << verb << "." << endl << endl;
    cout << "\tA nearby " << single_animal << " is unaffected by these events " << endl << endl;
    setColor(7, 0);
}


// mad crime
void madCrime(){

    string number, plural_object, place, body_part1, verb, distance, body_part2;

    cout << "\tInput a number:";
    cin >> number;
    cout << "\tInput a plural object:";
    cin >> plural_object;
    cout << "\tInput a place:";
    cin >> place;
    cout << "\tInput a body part:";
    cin >> body_part1;
    cout << "\tInput a verb ending with ing:";
    cin >> verb;
    cout << "\tInput a distance:";
    cin >> distance;
    cout << "\tInput a body part:";
    cin >> body_part2;


    setColor(2, 0);
    cout  << "\n\n";
    cout << "\tThere waw a second degree robbery." << endl << endl;
    cout << "\t" << number << " eggs were stolen from " << place << "." << endl << endl;
    cout << "\tThe crime scene has your " << body_part1 << " printed all over it." << endl << endl;
    cout << "\tA camera showed you were " << verb << distance << " away from the crime scene." << endl << endl;
    cout << "\tYou need the money to implant your " << body_part2 << "." << endl << endl;
    setColor(7, 0);
}

