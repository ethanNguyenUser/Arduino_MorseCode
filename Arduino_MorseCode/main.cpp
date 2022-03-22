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

//plugin everything below this into arduino code

const int SHORT = 100;
const int LONG = 400;
const int CHAR_WAIT = 100;
const int LETTER_WAIT = 500;
const int WORD_WAIT = 800;

void morse(char s[]){
    char map[26][2][5] = {
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
        for(int j = 0; j < 26; j++){
            if(c == map[j][0][0]){
                //for each letter in the morse code, shine appropriately
                for(int k = 0; map[j][1][k] != '\0'; k++){
                    digitalWrite(13, HIGH);
                    if(map[j][1][k] == '.'){
                        cout << ".";
                        tone(8, 440, SHORT);
                        delay(SHORT);
                    }
                    else{
                        cout << "-";
                        tone(8, 440, LONG);
                        delay(LONG);
                    }
                    digitalWrite(13, LOW);
                    noTone(0);
                    delay(CHAR_WAIT);
                }
            }
        }
        cout << " ";
        delay(LETTER_WAIT);
    }
    delay(WORD_WAIT);

}

void setup()
{
    pinMode(13, OUTPUT);
    pinMode(8, OUTPUT);
}

void loop()
{
    morse("morse");
}

int main(){
    loop();
}
