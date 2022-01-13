#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int buttonPin = 2;
const int ledPin =  13;
int buttonState = 0;
const int buzzer = 3;

int currCapacity = 0; //variable
int maxCapacity = 5;
String text = "Current Capacity";
bool alert = true;

void buzzerScream(){
  for(int i =0; i<3; i++){
    tone(buzzer, 450);
    delay(500);
    noTone(buzzer);
    delay(500);
  }
}

void setup() {
    // set up the LCD's number of columns and rows:
    pinMode(buttonPin, INPUT);
    lcd.begin(16, 2);
    
    lcd.setRGB(150, 255, 150);
    // Print a message to the LCD.
    lcd.print("     Welcome");
    delay(1000);
    
    lcd.setCursor(0, 1);
    lcd.print("   Counter-19");
    delay(2000);
    lcd.clear(); //Clearing the screen

    // print the capacity:
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 0);
    lcd.print(text);
    lcd.setCursor(0, 1);
    lcd.print(String(currCapacity)+'/'+String(maxCapacity));
}

void loop() {

    buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH) {
      currCapacity++;
    }

    // current Capacity is less than maximum
    if (currCapacity < maxCapacity){
      lcd.clear(); //Clearing the screen
      text = "Current Capacity";
      lcd.setCursor(0, 0);
      lcd.print(text);
      lcd.setCursor(0, 1);
      lcd.print(String(currCapacity)+'/'+String(maxCapacity));
      lcd.setRGB(150, 255, 150);
    }
    // current Capacity is at maximum    
    else if (currCapacity == maxCapacity){
      lcd.clear(); //Clearing the screen
      text = "Capacity FULL";
      lcd.setCursor(0, 0);
      lcd.print(text);
      lcd.setCursor(0, 1);
      lcd.print(String(currCapacity)+'/'+String(maxCapacity));
      lcd.setRGB(255, 0, 0);
    
    }
    
    // current Capacity is more than maximum
    else if(currCapacity > maxCapacity){
      lcd.clear(); //Clearing the screen
      text = "Please Wait";
      lcd.setCursor(0, 0);
      lcd.print(text);
      lcd.setCursor(0, 1);
      lcd.print(String(currCapacity)+'/'+String(maxCapacity));
      lcd.setRGB(255, 0, 0);
      //Alert goes off
      if(alert) {
        buzzerScream();
        noTone(buzzer);
        alert = false;
      }
    }
    
    else{
      lcd.setRGB(150, 255, 150);
    }
    delay(100);
} //rawr