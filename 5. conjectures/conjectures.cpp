// - This Is A Simple Program (Conjectures) of C++,
// - Made By RABIUL HASSAN (22170910)

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <math.h>

using namespace std;

void menu();
void GoldbachConjecture();
void CollatzConjecture();
void nicoChesterTheorem();
void fourSquareTheorem();
void sieveOfEratosthenes();
int isPrime(int num);
void setColor(unsigned textColor, unsigned bgColor);


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
                GoldbachConjecture();
                break;
            case 2:
                CollatzConjecture();
                break;
            case 3:
                nicoChesterTheorem();
                break;
            case 4:
                fourSquareTheorem();
                break;
            case 5:
                sieveOfEratosthenes();
                break;
            case 6:
                setColor(2, 0);
                cout << "\n\t\tThank You!" << endl;
                setColor(7, 0);
                break;
            case 7:
                setColor(2, 0);
                cout << "\n\t\tThank You!" << endl;
                setColor(7, 0);
                break;
            case 8:
                setColor(12, 0);
                cout << "\n\t\t====== Exit =======\n" << endl;
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
    cout<<"\t|*|*************Conjectures**************|*|\n";
    cout<<"\t|*|                                      |*|\n";
    cout<<"\t|*|                                      |*|\n";
    cout<<"\t|*|     1. Goldbach\'s Conjecture         |*|\n";
    cout<<"\t|*|     2. CollatzConjecture             |*|\n";
    cout<<"\t|*|     3. Nico Chester Theorem          |*|\n";
    cout<<"\t|*|     4. Four Square Theorem           |*|\n";
    cout<<"\t|*|     5. Sieve of Eratosthenes         |*|\n";
    cout<<"\t|*|     6. Bride & Groom                 |*|\n";
    cout<<"\t|*|     7. Truth or Lie                  |*|\n";
    cout<<"\t|*|     8. Exit                          |*|\n";
    cout<<"\t|*|                                      |*|\n";
    cout<<"\t|*|                                      |*|\n";
    cout<<"\t|*|*********CopyRight2023-RABIUL*********|*|\n";

}


void GoldbachConjecture(){
    setColor(2, 0);
    cout << "\n\n\t===========Press 888 to return to the menu==============";
    setColor(7, 0);

    int n;

    do{
        cout << "\n\tPlease input a positive even integer:";

        while(!(cin>>n) || (n<=1) || (n%2!=0) ){
            cout << "\tInvalid. Please input a positive even integer:";
            cin.clear();
            cin.sync();
        }
        int i, count=0;
        for(i=2; i<=n/2; i++){
            if(isPrime(i)){
                if(isPrime(n-i)){
                    count++;
                    cout << "\t" << i << " + " << n-i << " = " << n << endl;
                }
            }
        }
        setColor(2, 0);
        cout << "\n\tThere are " << count << " pair(s) of Prime Numbers that add up to " << n << endl;
        setColor(7, 0);
    }while(n!=888);
}

int isPrime(int num){
    if(num==2) return true;

    if(num%2==0) return false;

    int i;
    for(i=3; i<=sqrt(num); i+=2){
        if(num%i==0) return false;
    }
    return true;
}


void CollatzConjecture(){
    setColor(2, 0);
    cout << "\n\n\t===========Press 888 to return to the menu==============" << endl;
    cout << "\tTake any positive number: if it\'s even you divide it by 2 and if it\'s odd multiply it by 3 and add 1. Repeat this process indefinitely, no matter what number you start with, you will always end up at 1." << endl;
    cout << "\n\tThe conjecture remains stubbornly unproven. Mathematics is not yet ready for such problems." << endl;
    setColor(7, 0);

    int n;

    do{
        cout << "\n\tPlease input an integer:";

        while(!(cin>>n) || (n<=0)){
            cout << "\tInvalid. Please input an integer:";
            cin.clear();
            cin.sync();
        }
        int i, step=0, t=n;
        cout << endl;
        while(t!=1){
            cout << t << "->";
            if(t%2==0){
                t/=2;
                step++;
            }else{
                t= 3*t + 1;
                step++;
            }
        }

        cout << 1;

        setColor(2, 0);
        cout << "\n\n\tThere are " << step << " steps to get to 1 for " << n << endl;
        setColor(7, 0);
    }while(n!=888);
}


// Nico Chester Theorem
void nicoChesterTheorem(){

    setColor(2, 0);
    cout << "\n\n\t===========Press 22 to return to the menu==============" << endl;
    cout << "\tTake any positive number: if it\'s even you divide it by 2 and if it\'s odd multiply it by 3 and add 1. Repeat this process indefinitely, no matter what number you start with, you will always end up at 1." << endl;
    cout << "\n\tThe conjecture remains stubbornly unproven. Mathematics is not yet ready for such problems." << endl;
    setColor(7, 0);

    int n;

    do{
        cout << "\n\tPlease input an integer:";

        while(!(cin>>n) || (n<=0)){
            cout << "\tInvalid. Please input an integer:";
            cin.clear();
            cin.sync();
        }

        int cube = n*n*n;
        int i,j,k,sum=0;

        for(i=1;i<cube;i+=2){
            sum=0;
            for(j=i;j<cube;j+=2){
                sum+=j;
                if(sum==cube){
                    cout << "\n\t" << n << "^3=" << cube << "=";
                    for(k=i; k<j; k+=2){
                        cout << k << "+";
                    }
                    cout << j << "\n";
                }
            }
        }
    }while(n!=22);
}

// Four Square Theorem
void fourSquareTheorem(){
    setColor(2, 0);
    cout << "\n\n\t===========Press 888 to return to the menu==============" << endl;
    cout << "\n\tFour-square Theorem: Each positive integer may be expressed" << endl;
    cout << "\tas the sum of the squares of four integers." << endl;
    setColor(7, 0);

    int n;

    do{
        cout << "\n\tPlease input an integer:";

        while(!(cin>>n) || (n<=0)){
            cout << "\tInvalid. Please input an integer:";
            cin.clear();
            cin.sync();
        }

        cout << endl;
        int i, j, k, l, count = 0;

        for (int i = 0; i * i <= n; i++) {
            for (int j = i; j * j <= n; j++) {
                for (int k = j; k * k <= n; k++) {
                    for (int l = k; l * l <= n; l++) {
                        count++;
                        if (i * i + j * j + k * k + l * l == n) {
                            cout << "\t\t" << n << " = " << i << "*" << i << " + " << j << "*" << j << " + " << k << "*" << k << " + "<< l << "*" << l << endl;
                        }
                    }
                }
            }
        }

        cout << "\n\tThe total loop is " << count << "." << endl;

    }while(n!=888);
}



// Sieve of Eratosthenes
void sieveOfEratosthenes(){
    setColor(2, 0);
    cout << "\n\n\t===========Press 888 to return to the menu==============" << endl;
    setColor(7, 0);

    int n;

    do{
        cout << "\n\tPlease input an integer:";

        while(!(cin>>n) || (n<=0)){
            cout << "\tInvalid. Please input an integer:";
            cin.clear();
            cin.sync();
        }

        cout << endl;

        int i, p, count=0;
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));

        // prime number validate
        for (p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        setColor(2, 0);
        // Print all prime numbers
        for (p = 2; p <= n; p++){
            if (prime[p]){
                count++;
                cout << p << " ";
            }
        }
        setColor(7, 0);
        cout << "\n\n\tThere are total " << count << " prime number." << endl;

    }while(n!=888);
}

