// - This Is A Simple Print Grapics Program,
// - Made By RABIUL HASSAN (22170910)

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void menu();
void book();
void heart();
void car();
void horse();
void kitty();
void setColor(unsigned textColor, unsigned bgColor);

int main()
{
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
                setColor(7, 3);
                car();
                break;
            case 2:
                setColor(7, 4);
                heart();
                break;
            case 3:
                setColor(0, 7);
                book();
                break;
            case 4:
                setColor(7, 2);
                horse();
                break;
            case 5:
                setColor(4, 6);
                kitty();
                break;
            case 6:
                cout<<"\n\tExit\n\n";
                break;
            default:
                cout<<"\nInvalid Input\n";
                break;
        }

        setColor(7, 0);

        if(input!=6){
            cout<<"\n\tPress any key to return to the menu:";
            getch();
            cout<<"\n\n";
        }
    }while(1);
}

// function to show menu
void menu(){
    cout<<"\t|*|****************Menu****************|*|\n";
    cout<<"\t|*|                                    |*|\n";
    cout<<"\t|*|                                    |*|\n";
    cout<<"\t|*|     1. Car           2. Heart      |*|\n";
    cout<<"\t|*|                                    |*|\n";
    cout<<"\t|*|     3. Book          4. Horse      |*|\n";
    cout<<"\t|*|                                    |*|\n";
    cout<<"\t|*|     5. Kitty         6. Exit       |*|\n";
    cout<<"\t|*|                                    |*|\n";
    cout<<"\t|*|                                    |*|\n";
    cout<<"\t|*|*****CopyRight2023-RABIUL HASSAN****|*|\n";
}


// Book
void book(){
    cout<<"\t                                                  "<<endl;
    cout<<"\t                                                  "<<endl;
    cout<<"\t          __...--~~~~~-._   _.-~~~~~--...__       "<<endl;
    cout<<"\t        //               `V'               \\      "<<endl;
    cout<<"\t       //                 |                 \\     "<<endl;
    cout<<"\t      //__...--~~~~~~-._  |  _.-~~~~~~--...__\\    "<<endl;
    cout<<"\t     //__.....----~~~~.__\ | /_.~~~~----.....__\\   "<<endl;
    cout<<"\t    ====================__\|//==================== "<<endl;
    cout<<"\t                        `---`                     "<<endl;
    cout<<"\t                                                  "<<endl;
    cout<<"\t                                                  "<<endl;
    cout<<"\n\n";
}
// Heart
void heart(){

    cout<<"\t                                                               "<<endl;
    cout<<"\t                                                               "<<endl;
    cout<<"\t                ******        ******                           "<<endl;
    cout<<"\t              **********    **********                         "<<endl;
    cout<<"\t             ************ * ************                       "<<endl;
    cout<<"\t             ********************     **                       "<<endl;
    cout<<"\t              ****************   ****     ***                  "<<endl;
    cout<<"\t               *************  ******** * ********              "<<endl;
    cout<<"\t                 **********  *********************             "<<endl;
    cout<<"\t                   ********  *********************             "<<endl;
    cout<<"\t                     ******   *******************              "<<endl;
    cout<<"\t                       *****    ***************                "<<endl;
    cout<<"\t                         ****      *********                   "<<endl;
    cout<<"\t                          **           **                      "<<endl;
    cout<<"\t            ***********************************************    "<<endl;
    cout<<"\t                                                               "<<endl;
    cout<<"\t                                                               "<<endl;

}
// Car
void car(){
    cout<<"                                                                   \n";
    cout<<"                                                                   \n";
    cout<<"                      _________________                            \n";
    cout<<"                  _.-'_____  _________ _`.                         \n";
    cout<<"                .` ,'      ||         | `.`.                       \n";
    cout<<"              .` ,'        ||         |   `.`.                     \n";
    cout<<"            .`  /          ||         |  ,' ] `....___             \n";
    cout<<"          _`__.'''''''''''''''''''''''`''''''''|..___ `-.._        \n";
    cout<<"        .'                  [='                '     `'-.._`.      \n";
    cout<<"     ,:/.'''''''''''''''''''|''''''''''''''''''|'''''''''''\'\       \n";
    cout<<"      //||    _..._         |                  '    _..._  |)|     \n";
    cout<<"     /|//   ,',---.`.       |                  |  .',---.`.\>|      \n";
    cout<<"    (':/   //' .-. `\      \_________________/  '/' .-. `\\|_)        \n";
    cout<<"     `-...'||  '-'  ||________,,,,,,,,,,,,,,,__.'||  '-'  ||-'     \n";
    cout<<"           '.'.___.','                           '.'.___.','       \n";
    cout<<"             '-.m.-'                               '-.m.-'         \n";
    cout<<"                                                                   \n";
    cout<<"                                                                   \n";
}
// Horse
void horse(){
    cout<<"\t                                                       \n";
    cout<<"\t                                                       \n";
    cout<<"\t                                   _(\_/)              \n";
    cout<<"\t                                 ,((((^`\              \n";
    cout<<"\t                                ((((  (6 \             \n";
    cout<<"\t                              ,((((( ,    \            \n";
    cout<<"\t          ,,,,              ,(((((  //,_  ,`,          \n";
    cout<<"\t         ((((\\ ,...       ,((((   /    `-.-'          \n";
    cout<<"\t         )))  ;'    `((((((((((   (                    \n";
    cout<<"\t        (((  /            (((      \                   \n";
    cout<<"\t         )) |        ((             |                  \n";
    cout<<"\t        ((  |        .       '     |                   \n";
    cout<<"\t        ))  \     _ '      `t   ,.')                   \n";
    cout<<"\t        (   |   y;- |||||||||\   \/                    \n";
    cout<<"\t        )   / ./  ) /         `\  \                    \n";
    cout<<"\t           |./   ( (           / /'                    \n";
    cout<<"\t           ||     \\          //'|                     \n";
    cout<<"\t           ||      \\       _//'||                     \n";
    cout<<"\t           ||       ))     |_/  ||                     \n";
    cout<<"\t           \_\     |_/          ||                     \n";
    cout<<"\t           `==                  \_\                    \n";
    cout<<"\t                                `==                    \n";
    cout<<"\t                                                       \n";
    cout<<"\t                                                       \n";

}
// kitty
void kitty(){
       cout<<"\t                                                                          \n";
       cout<<"\t                                                                          \n";
       cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!`   `4!!!!!!!!!!~4!!!!!!!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   <~:   ~!!!~   ..  4!!!!!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  ~~~~~~~  '  ud$$$$$  !!!!!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  ~~~~~~~~~: ?$$$$$$$$$  !!!!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!!!`     ``~!!!!!!!!!!!!!!  ~~~~~          **$$$$$k `!!!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!!  $$$$$bu.  '~!~`     .  '~~~~      :~~~~          `4!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!  $$$$$$$$$$$c  .zW$$$$$E ~~~~      ~~~~~~~~  ~~~~~:  '!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!! d$$$$$$$$$$$$$$$$$$$$$$E ~~~~~    '~~~~~~~~    ~~~~~  !!!!!!!!!!\n";
       cout<<"\t!!!!!!!!> 9$$$$$$$$$$$$$$$$$$$$$$$ '~~~~~~~ '~~~~~~~~     ~~~~  !!!!!!!!!!\n";
       cout<<"\t!!!!!!!!> $$$$$$$$$$$$$$$$$$$$$$$$b   ~~~    '~~~~~~~     '~~~ '!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!> $$$$$$$$$$$$$$$$$$$$$$$$$$$cuuue$$N.   ~        ~~~  !!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!! **$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$Ne  ~~~~~~~~  `!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!  J$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$N  ~~~~~  zL '!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!  d$$$$$$$SDW$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$c     z$$$c `!!!!!!!!!\n";
       cout<<"\t!!!!!!!> <$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$> 4!!!!!!!!\n";
       cout<<"\t!!!!!!!  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  !!!!!!!!\n";
       cout<<"\t!!!!!!! <$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$**   ....:!!\n";
       cout<<"\t!!!!!!~ 9$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$e@$N '!!!!!!!\n";
       cout<<"\t!!!!!!  9$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  !!!!!!!\n";
       cout<<"\t!!!!!!  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$""$$$$$$$$$$$~ ~~4!!!!\n";
       cout<<"\t!!!!!!  9$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$Lue  :::!!!!\n";
       cout<<"\t!!!!!!> 9$$$$$$$$$$$$$ '$$$$$$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$  !!!!!!!\n";
       cout<<"\t!!!!!!! '$$*$$$$$$$$E   '$$$$$$$$$$$$$$$$$$$$$$$$$$$u.@$$$$$$$$$E '!!!!!!!\n";
       cout<<"\t!!!!~`   .eeW$$$$$$$$   :$$$$$$$$$$$$$***$$$$$$$$$$$$$$$$$$$$u.    `~!!!!!\n";
       cout<<"\t!!> .:!h '$$$$$$$$$$$$ed$$$$$$$$$$$$Fz$$b $$$$$$$$$$$$$$$$$$$$$F '!h.  !!!\n";
       cout<<"\t!!!!!!!!L '$**$$$$$$$$$$$$$$$$$$$$$$ *$$$ $$$$$$$$$$$$$$$$$$$$F  !!!!!!!!!\n";
       cout<<"\t!!!!!!!!!   d$$$$$$$$$$$$$$$$$$$$$$$$buud$$$$$$$$$$$$$$$$$$$$$  !!!!!!!!!!\n";
       cout<<"\t!!!!!!! .<!  #$$*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  :!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!!!!:   d$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$#  :!!!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!!!~  :  '#$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$**    !!!!!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!!  !!!!!:   ^***$$$$$$$$$$$$$$$$$$$$**##     .:<!!!!!!!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!!!!!!!!!!!!!:...       I LOVE C++     .::!!!!!!!!!!!!!!!!!!!!!!!!\n";
       cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
       cout<<"\t                                                                          \n";
       cout<<"\t                                                                          \n";
}

void heart2()
{
    cout << "\t                                                         "<< endl;
    cout << "\t                                                         "<< endl;
    cout << "\t              ***                    ***                 "<<endl;
    cout << "\t         **********             **********               "<<endl;
    cout << "\t       ****************       ****************           "<< endl;
    cout << "\t     ********************   ********************         "<< endl;
    cout << "\t    *********************************************        "<< endl;
    cout << "\t    *********************************************        "<< endl;
    cout << "\t     *******************************************         "<< endl;
    cout << "\t      *****************************************          "<< endl;
    cout << "\t       ***************************************           "<< endl;
    cout << "\t         ***********************************             "<< endl;
    cout << "\t           *******************************               "<< endl;
    cout << "\t             ***************************                 "<< endl;
    cout << "\t                ***********************                   "<< endl;
    cout << "\t                  *******************                     "<< endl;
    cout << "\t                    ***************                       "<< endl;
    cout << "\t                     ***********                         "<< endl;
    cout << "\t                        *******                           "<< endl;
    cout << "\t                         ***                             "<< endl;
    cout << "\t                         *                              "<< endl;
    cout << "\n                                                         "<< endl;
}

// set color
void setColor(unsigned textColor, unsigned bgColor){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, textColor%16 | bgColor%16*16);
}
