/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 1b
    * Programming Fundamentals CO1011 - Spring 2019
    * Author: Tran Ngoc Bao Duy
    * Date: 05.4.2019
    * Only write/edit in the body of combat function to complete this assignment
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

void combat(int hp1, int hp2, int d) {
    // TODO: You have to complete this function followed by requirements
    //Calculate the value of p1,p2 and h1,h2
    // if (hp1 ==777 && hp2 != 888) {
    //     d = 1;
    // }
    float p1 = hp1*(1000.0-d)/1000.0;
    float p2 = hp2*d/1000.0;
    int h1 = (hp1 + hp2)%100;
    int h2 = (h1 * hp2)%100;

    //Begin 
    float result = (h1*p1-h2*p2)/(h1*p1+h2*p2);
    
    if (hp1 ==777 && hp2 != 888 && (h1<h2 || p1<p2)) {
         d = 1;
         p1 = hp1*(1000.0-d)/1000.0;
         p2 = hp2*d/1000.0;
         h1 = (hp1 + hp2)%100;
         h2 = (h1 * hp2)%100;
         result = (h1*p1-h2*p2)/(h1*p1+h2*p2);
    }

    if (hp1 ==888 && hp2 != 888) {
         h1 = 10*h1;
         result = (h1*p1-h2*p2)/(h1*p1+h2*p2);
    }
    
    if (hp1 ==900 && hp2 != 888) {
         if (result < 0.5){
             result = 0.5;
         }    
    }

    if (hp2==888){
        if (hp1==999){
            result =1;
        }
        else if (hp1 != 777 && hp1 != 888 && hp1 != 900){
            result = 0.01;
        }
    }

    if ((hp1==220 && hp2 == 284)||(hp1==284 && hp2==220)){
        result =0.5;
    }

    if (d == 987){
        if (hp1 != 999 && (h1+h2) != 99 
        && ((hp1==220 && hp2 == 284)||(hp1==284 && hp2==220)==false)){
            result =0;
        }
    }
    
    if (result<0){
        result = 0;
    }
    if(result>1){
        result = 1;
    }
//////Printf the result on the screen hihi!!!!!!
    printf("%2.2f",result);
}

// int readFile(string filename, int& hp1, int& hp2, int& d) {
//     ifstream myfile(filename);
//     if (myfile.is_open()) {
//         myfile >> hp1 >> hp2 >> d;

//         return 1;
//     }
//     else return 0;
// }

// int main(int argc, char** argv) {

//     if (argc == 2) {
//         int hp1 = 0;
        // int hp2 = 0;
        // int d = 0;

        // int readInput = readFile(argv[1], hp1, hp2, d);
        
//         if (readInput) combat(hp1, hp2, d);
//         else cout << "Cannot read input file";
//     }
//     else cout << "Incorrect arguments format";
// }
int main(){
    int hp1,hp2,d;
    cin>>hp1>>hp2>>d;
    combat(hp1,hp2,d);
}