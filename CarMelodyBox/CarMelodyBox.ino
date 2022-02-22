/**
 * @file CarMelodyBox.ino
 *
 * @brief Code required for playing an MP3 on startup
 *
 * @author Sasha Ryder
 *
 */

#include "Arduino.h"
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

SoftwareSerial softwareSerial(11, 10); // RX pin (Reciever), TX pin (Transmitter)
DFRobotDFPlayerMini audioPlayer;

void setup()
{
  softwareSerial.begin(9600);
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("Car Melody Player"));
  Serial.println(F("Connecting to MP3 module, this may take 3-5 seconds"));
  if (!audioPlayer.begin(softwareSerial)) // Try connect to Mini MP3 module
  {
    Serial.println(F("Unable to connect to MP3 Module."));
    return;
  }
  Serial.println(F("Connected to Mini MP3 module."));

  audioPlayer.volume(30); // Set max volume
  audioPlayer.play(1);    // Play main MP3
}

void loop()
{
}
