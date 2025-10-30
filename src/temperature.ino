#include <DHT.h>

#define DHTPIN 12
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(hum) || isnan(temp)) {
    Serial.println("Invalid reading!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println("%");
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println("°C");

}
