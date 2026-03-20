#define SOIL_SENSOR_PIN 34  
#include <DHT.h>  
DHT dht(4, DHT22);
float temperature ;
float  humidity;
#define pHsensorpin 33 ;
#include <HardwareSerial.h>
//HardwareSerial SerialPort(2);
#define ncom 3 //  number of commands.
char commar[ncom] = {0x5,0x1,0x3}; // Actual commands
// Response Strings can be stored like this
char respar[ncom][30]={"Nitrogen value is: ","Phosphorous value is: ","Potassium value is: "};
uint8_t rtValue[ncom]; // Store the return values from the custom chip in here. you can use the same
//values to forward to the IOT part.
void setup() {
  Serial.begin(9600);
  analogReadResolution(10);  // For ESP32: 0-1023 range
  Serial.begin(115200); // initialize console
  Serial.println("Hello, ESP32!"); 
  Serial2.begin(15200, SERIAL_8N1, 16, 17);
}

void loop() {
  for (uint8_t i = 0; i< ncom;i++)
  {
     Serial2.print((char)commar[i]); // send the command stored in ncom array through serial2
     if (Serial2.available())
    { //if serial2 data is there
      rtValue[i]= Serial2.read();// read serial2 
      Serial2.flush();// flush serial2, very important. otherwise extra bits may interfere with communication
      Serial.print(respar[i]); // print the response array to the console.
      Serial.println(rtValue[i]); // print the return value with newline at console
    }}
  int moistureValue = analogRead(SOIL_SENSOR_PIN);
  float soilPercent = map(moistureValue, 0, 1023, 0, 100);
  Serial.print("Soil Moisture %: ");
  Serial.println(soilPercent);

  temperature  = dht.readTemperature();
  humidity     = dht.readHumidity();
  
  // Print the values of temperature in Celsus
  Serial.print("Temperature:\t");
  Serial.print(dht.readTemperature(false));
  Serial.println("C");
  // print Humidity in percent 
  Serial.println("Humidity: \t"+String(humidity)+ "%");
  int phValue = analogRead(33);
  float voltage = phValue * (5 / 1023.0); 
  float ph = 7 + ((2.5 - voltage) / 0.18);
  Serial.print("ph:\t");
  Serial.println(ph);
  delay(1000);
}

