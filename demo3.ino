// 0	0	0	0	0	0	0	0
// mm	tl	tm	tr	bl	bm	br	d

// Globals
const int dataPin = 16;  // blue wire to 74HC595 pin 14
const int latchPin = 15; // green to 74HC595 pin 12
const int clockPin = 14; // yellow to 74HC595 pin 11

int i, j;
 
void setup() {
  // initialize I/O pins
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			displayBytes(toSegment(i), toSegment(j));
			delay(100);
		}
	}
}

void displayBytes(byte left, byte right) {
  left  ^= 0xff;
  right ^= 0xff;
  
  
  digitalWrite(latchPin, LOW);                  // prepare shift register for data
  shiftOut(dataPin, clockPin, LSBFIRST, right); // send data
  shiftOut(dataPin, clockPin, LSBFIRST, left);  // send data
  digitalWrite(latchPin, HIGH);                 // update display
}

byte toSegment(int someNumber) {
  switch (someNumber) {
    case 0:
      return 0b01111110;
      break;
    case 1:
      return 0b00010010;
      break;
    case 2:
      return 0b10111100;
      break;
    case 3:
      return 0b10110110;
      break;
    case 4:
      return 0b11010010;
      break;
    case 5:
      return 0b11100110;
      break;
    case 6:
      return 0b11101110;
      break;
    case 7:
      return 0b00110010;
      break;
    case 8:
      return 0b11111110;
      break;
    case 9:
      return 0b11110110;
      break;
    default:
      return 0b10010010; // Error condition, displays three vertical bars
      break;   
  }
}