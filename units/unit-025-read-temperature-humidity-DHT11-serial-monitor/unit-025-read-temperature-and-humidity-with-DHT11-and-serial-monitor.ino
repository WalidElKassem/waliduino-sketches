#include <DHT.h>


#define DHTPIN A3      // DHT11 data pin connected to D4
#define DHTTYPE DHT11 // we use the DHT11 sensor


DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);   // start Serial Monitor at 9600 baud
  dht.begin();          // start the DHT11 sensor


  // Optional welcome text
  Serial.println("Waliduino DHT11 Sensor");
  Serial.println("Reading temperature and humidity...");
}
void loop() {
  // DHT11 is a bit slow, so we wait 2 seconds between readings
  delay(2000);


  // Read humidity (%)
  float humidity = dht.readHumidity();


  // Read temperature in Celsius (°C)
  float temperature = dht.readTemperature();


  // Check if the reading failed (returns NaN = Not a Number)
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error: could not read from DHT11 sensor");
    return; // skip the rest of loop
  }


  // Print the values in a nice format
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
