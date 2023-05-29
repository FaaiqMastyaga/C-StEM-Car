const int relay1 = 2;
const int relay2 = 3;
const int voltage_sensor = A0;
float voltage_raw;
float voltage_now;
float voltage_min = -1;

void setup() {
  Serial.begin(9600);
  pinMode(voltage_sensor, INPUT);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  Serial.println("Initializing");
  delay(1000);
}

void loop() {
  move_car();
  move_shaker();
  read_voltage();

  if (voltage_now < voltage_min) {
    stop_car();
    stop_shaker();
    Serial.println("Exiting program");
    delay(3000);
    exit(0);
  }
  delay(300);
}

void read_voltage() {
  voltage_raw = analogRead(voltage_sensor);
  voltage_now = map(voltage_raw, 0, 1023, 0, 2500);
  voltage_now = voltage_now / 100;
  Serial.println("Tegangan terukur: ");
  Serial.println(voltage_now);
}

void move_car() {
  Serial.println("Car moving");
  digitalWrite(relay1, LOW);
}

void stop_car() {
  Serial.println("Car stopping");
  digitalWrite(relay1, HIGH);
}

void move_shaker() {
  Serial.println("Shaker moving");
  digitalWrite(relay2, LOW);
}

void stop_shaker() {
  Serial.println("Shaker stopping");
  digitalWrite(relay2, HIGH);
}
