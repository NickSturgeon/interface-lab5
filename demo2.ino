int SER = 16;
int RCLK = 15;
int SRCLK = 14;

int delayTime = 250;

byte val;
bool forward;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  
  digitalWrite(RCLK, LOW);
  digitalWrite(SRCLK, LOW);
  
  val = 0xff;
  forward = true;
  displayByte(0x00, 0x00);
}

void loop() {
	for (int i = 0; i < 8; i++) {
		displayByte(val << (8 - i - 1), 0x00);
		delay(delayTime);
	}
	
	for (int i = 0; i < 8; i++) {
		displayByte(0xff, val << (8 - i - 1));
		delay(delayTime);
	}
	
	for (int i = 0; i < 8; i++) {
		displayByte(0xff, val << (i + 1));
		delay(delayTime);
	}
	
	for (int i = 0; i < 8; i++) {
		displayByte(val << (i + 1), 0x00);
		delay(delayTime);
	}
}

void displayByte(byte input1, byte input2) {
	digitalWrite(RCLK, LOW);
	shiftOut(SER, SRCLK, LSBFIRST, input2);
	shiftOut(SER, SRCLK, LSBFIRST, input1);
	digitalWrite(RCLK, HIGH);
}
