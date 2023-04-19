
/*
  Blink:
  Blinks an LED by bit masking.
  The on-board LED on the Arduino UNO is at PortB 5.
 */

#define MASK(x) ((unsigned char) (1<<(x)))

void bin(unsigned char input)
{
    unsigned char mask;
    for (mask = 1 << 7; mask > 0; mask = mask / 2)
    {
        (input & mask) ? Serial.print("1") : Serial.print("0");
    }
    Serial.println();
}

void setup()
{
  Serial.begin(9600);
  DDRB |= MASK(5);   // The LED pin is output. Mask: 00100000
  bin(DDRB);
  bin(PORTB |= MASK(5));
  bin(PORTB &= ~MASK(5));
}

void loop()
{
  PORTB |= MASK(5);  // Turn LED on
  delay(500);
  PORTB &= ~MASK(5); // Turn LED off
  delay(500);
}
