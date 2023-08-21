// DHT22 Library
#include "DHT.h"

// NewPing Library
#include "NewPing.h"

// Input pins

#define DHTPIN 7          // Output DHT-22 
#define DHTTYPE DHT22     // Modelo DHT 22 (AM2302)
#define TRIGGER_PIN  10   // Trigger Ultrassom
#define ECHO_PIN     13   // Echo Ultrassom


#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

float hum;    // Humidity
float temp;   // Temperature in celsius
float duration; // Ultrassound pulse duration
float distance; // Distance
float sound;  // Speed of Sound (m/s)
float soundcm;  // Speed of Sound (cm/ms)
int iterations = 5;

// Initializing DHT

DHT dht(DHTPIN, DHTTYPE); 

void setup() {
  Serial.begin (9600);
  dht.begin();
}

void loop()
{

  delay(1000);
   
    hum = dht.readHumidity();  // Le humidade
    temp= dht.readTemperature();  // Le temperatura
    
    // Speed of Sound calculation m/s
    sound = 331.4 + (0.606 * temp) + (0.0124 * hum);

    // Speed of Sound in cm/ms
    
    soundcm = sound / 10000;
    
  duration = sonar.ping_median(iterations);
  
  // Calculating the distance - ping duration in ms
  distance = (duration / 2) * soundcm;
  
  // Printando os resultados
  
    //Serial.print("Sound Speed: ");
    Serial.print(sound);
    Serial.print(",");
    //Serial.print("Hum: ");
    Serial.print(hum);
    Serial.print(",");
    Serial.print(temp);
    Serial.print(",");

    //Serial.print("Distance: ");
    if (distance >= MAX_DISTANCE || distance <= 2) {
    Serial.print("Out of Range");
    }
    else {
    Serial.print(distance);
    //Serial.print(" cm");
    delay(500);
    }
  
  Serial.println(" ");
}
