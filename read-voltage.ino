const int voltage_sensor = A0;
float voltage_raw;
float voltage_real;

void setup() {
  Serial.begin(9600);
  pinMode(voltage_sensor, INPUT);
  Serial.println("Mengukur tegangan");
  delay(2000);
}

void loop() {
  read_voltage();
  Serial.println("Tegangan terukur: ");
  Serial.println(voltage_real);
  delay(1000);
}

void read_voltage() {
  voltage_raw = analogRead(voltage_sensor);
  voltage_real = map(voltage_raw, 0, 1023, 0, 2500);
  voltage_real = voltage_real / 100; 
}
