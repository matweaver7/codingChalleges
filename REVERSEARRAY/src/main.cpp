#include <iostream>
#include <string>
using namespace std; 

const int lowUpperCase = 97;
const int highUpperCase = 122;
const int lowLowerCase = 65;
const int highLowerCase = 90;

void swapCharacters(int pos1, int pos2, string& message) {
    char tmpChar = message[pos2];    
    message[pos2] = message[pos1];
    message[pos1] = tmpChar;

}
bool isAsciiInRange(int num){

    if ((num <= highUpperCase && num >= lowUpperCase) ||
        (num <= highLowerCase & num >= lowLowerCase)) {
            return true;
    }
    return false;
}

void getNextCharacter(bool goDown, int& pos, string& message) {
    int change = 1;
    int currPos = pos;
    bool foundAscii = false;
    if (goDown) {
        change = -1;
    }
    
    while(!foundAscii) {
        currPos = currPos + change;
        foundAscii = isAsciiInRange((int) message[currPos]);
    }
    pos = currPos;
}



void inverterHandler(string& message) {
    int startPos = 0; 
    int endPos = message.length() - 1;

    // this is to offset the message initiall if first letters are changing
    if (isAsciiInRange((int)message[startPos]) || isAsciiInRange((int)message[startPos])) {
        startPos = -1;
        endPos = message.length();
    }
    while (startPos < endPos) {
        getNextCharacter(false, startPos, message);
        getNextCharacter(true, endPos, message);
        swapCharacters(startPos, endPos, message);
    }
    
}

string invertMessage(string message) {

    inverterHandler(message);

    return message;
}


int main() 
{ 
    string message = "be%3dy88r";
    cout << "original message: " << message << endl;
    cout << invertMessage(message) << endl;

    return 0; 
} 