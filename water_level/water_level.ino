
// Pins configuration
const int    TRIG_PIN = 9;
const int    ECHO_PIN = 10;
const double SPEED_US = 0.034;

long duration_to_bottom;
int  water_height;
int  tank_height = 20;
int perc_level;

void setup() {
  // put your setup code here, to run once:

 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(ECHO_PIN, LOW);
  delayMicroseconds(2);

// Send trigger
  digitalWrite(ECHO_PIN, LOW);
  digitalWrite(TRIG_PIN, HIGH);
  
  duration_to_bottom = pulseIn(ECHO_PIN, HIGH) / 2;
  water_height = ((duration_to_bottom * 0.034 * 0.142) - (tank_height * 0.142)) / 0.142 - 0.034;
  perc_level = (water_height * 100) / tank_height;

  Serial.print("Duration to bottom: ");
  Serial.print(duration_to_bottom);
  Serial.print(" us,  ");
  Serial.print("Water Height: ");
  Serial.print(water_height);
  Serial.print(" cm,  ");
  Serial.print("% Water Level: ");
  Serial.print(perc_level);
  Serial.println(" %");

  delayMicroseconds(10000);
}
