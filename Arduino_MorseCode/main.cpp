#include <iostream>
using namespace std;

const int LOW = 0;
const int HIGH = 1;
const int OUTPUT = 1;

void digitalWrite(int port, int state){}

void delay(int wait){}

void pinMode(int port, int state){}

void tone(int port, int pitch, int duration){}

void noTone(int port){}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
///Paste everything below this into Arduino code
/////////////////////////////////////////////////////////////////////////////////////////////////////////

const int SHORT = 100;
const int LONG = 400;
const int CHAR_WAIT = 100;
const int LETTER_WAIT = 500;
const int WORD_WAIT = 800;
const int MAP_SIZE = 26;
const int MAX_MORSE_SIZE = 5;
const int LED_PORT = 13;
const int SOUND_PORT = 8;
const int PITCH = 440;

void morse(char s[]){
    char map[MAP_SIZE][2][MAX_MORSE_SIZE] = {
        {"a", ".-"},
        {"b", "-..."},
        {"c", "-.-."},
        {"d", "-.."},
        {"e", "."},
        {"f", "..-."},
        {"g", "--."},
        {"h", "...."},
        {"i", ".."},
        {"j", ".---"},
        {"k", "-.-"},
        {"l", ".-.."},
        {"m", "--"},
        {"n", "-."},
        {"o", "---"},
        {"p", ".--."},
        {"q", "--.-"},
        {"r", ".-."},
        {"s", "..."},
        {"t", "-"},
        {"u", "..-"},
        {"v", "...-"},
        {"w", ".--"},
        {"x", "-..-"},
        {"y", "-.--"},
        {"z", "--.."}
    };

    //loop through each letter in s
    for(int i = 0; s[i] != '\0'; i++){
        char c = s[i];
        //for each letter, consult map
        for(int j = 0; j < MAP_SIZE; j++){
            if(c == map[j][0][0]){
                //for each letter in the morse code, shine appropriately
                for(int k = 0; map[j][1][k] != '\0'; k++){
                    digitalWrite(LED_PORT, HIGH);
                    if(map[j][1][k] == '.'){
//                        cout << ".";
                        tone(SOUND_PORT, PITCH, SHORT);
                        delay(SHORT);
                    }
                    else{
//                        cout << "-";
                        tone(SOUND_PORT, PITCH, LONG);
                        delay(LONG);
                    }
                    digitalWrite(LED_PORT, LOW);
                    delay(CHAR_WAIT);
                }
            }
        }
//        cout << " ";
        delay(LETTER_WAIT);
    }
    delay(WORD_WAIT);

}

void setup()
{
    pinMode(LED_PORT, OUTPUT);
    pinMode(SOUND_PORT, OUTPUT);
}

void loop()
{
    morse("testing");
}

///////////////////////////////////////////
///Don't paste main()
///////////////////////////////////////////

int main(){
    loop();
}
