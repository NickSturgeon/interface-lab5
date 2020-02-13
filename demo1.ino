int SER = 16;
int RCLK = 15;
int SRCLK = 14;

byte val;
bool forward;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  
  digitalWrite(RCLK, LOW);
  digitalWrite(SRCLK, LOW);
  
  val = 0b10000000;
  forward = true;
  displayByte(val);
}

void loop() {
	if (val == 0b10000000 || val == 0b00000001) {
		forward = !forward;
	}

	if (forward) {
		val = val << 1;
	} else {
		val = val >> 1;
	}

	displayByte(val);
	delay(250);
}

void displayByte(byte input) {
	digitalWrite(RCLK, LOW);
	shiftOut(SER, SRCLK, LSBFIRST, input);
	digitalWrite(RCLK, HIGH);
}
