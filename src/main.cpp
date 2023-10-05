/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       UwU A Useles Someone                                      */
/*    Created:      9/25/2023, 4:55:54 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace vex;
using namespace std;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
motor one = motor(PORT1,true);

int framenum =1;
std::string png = ".png";
std::string files = "Frames0";
std::string addzeros ="0";

template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}



/*needs help
std::string str;
int a = 10;
char *intStr = itoa(a,"f",a);
std::string str = std::string(intStr);
needs help*/



void framecounter(){
    std::string s = "String";
    s = to_string( framenum );
    files = "Frames0";
    if(framenum>999){
        addzeros="";
    }else if(framenum>99){
        addzeros="0";
    }else if(framenum>9){
        addzeros="00";
    }else{
        addzeros="000";
    }
    
    
    files = "Frames0"+addzeros+s+".png";
    framenum++;
}






int main() {
    
    //Brain.Screen.drawImageFromFile("Aphototwo.png",0,0);
    
   
    


    
    //vex::Gif gif("world.gif", 120, 0 );
    while(1){
    //Brain.Screen.clearScreen();
    //Brain.Screen.clearLine();
    framecounter();
    const char * c = files.c_str();
    //Brain.Screen.print(c);
    Brain.Screen.drawImageFromFile(c,0,0);
    

    wait(0.006,seconds);

    }

    while(1) {
        
        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}
