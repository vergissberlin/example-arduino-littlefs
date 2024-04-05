#include <Arduino.h>
#include <LittleFS.h>

void setup() {
  Serial.begin(115200);

  if (!LittleFS.begin()) {
    Serial.println("An error has occurred while mounting LittleFS");
    return;
  } else {
    Serial.println("LittleFS mounted successfully");
  }

  // Creates a file and writes data to it
  File file = LittleFS.open("/example.txt", "w");
  if (!file) {
    Serial.println("There was an error opening the file for writing");
    return;
  } else {
    Serial.println("File opened for writing");
  }
  
  if (file.print("Hello World!")) {
    Serial.println("File was written");
  } else {
    Serial.println("File write failed");
  }

  file.close();

  // Reads the data from the file
  file = LittleFS.open("/example.txt", "r");
  
  if (!file) {
    Serial.println("There was an error opening the file for reading");
    return;
  } else {
    Serial.println("File opened for reading");
  }
  
  while (file.available()) {
    Serial.write(file.read());
  }

  file.close();
}

void loop() {
}

