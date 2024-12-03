#include <DHT.h> // DHT library by Adafruit

#define DHTTYPE DHT11  // alternatively DHT 22
#define PIN_DHT 16;  // GPIO pin for sensor

//create dht sensor object
DHT dht(PIN_DHT, DHTTYPE);

void setup() {

  // init serial monitor
  Serial.begin(115200);

  // init dht sensor
  dht.begin();
  
}

void loop() {
  
    // sensor readings may be up to 2 seconds 'old' - dht is a very slow sensor
    delay(2000);

    // read humidity
    float h = dht.readHumidity();
    
    // read temperature as Celsius (default)
    float t = dht.readTemperature();

    // read temperature as Fahrenheit (isFahrenheit = true)
    float f = dht.readTemperature(true);
 
    // nan: not a number
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println("Failed to read from DHT sensor!");

    } else {

      // print to serial monitor
      Serial.println("Humidity: " + String(h));
      Serial.println("Celsius: " + String(t));
      Serial.println("Fahrenheit: " + String(f));

    }

}
