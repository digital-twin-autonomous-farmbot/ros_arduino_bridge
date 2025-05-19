#define ARDUINO_ENC_COUNTER

#ifdef USE_BASE

volatile long left_enc_pos = 0L;
static const int8_t ENC_STATES[] = {0,1,-1,0,-1,0,0,1,1,0,0,-1,0,-1,1,0};

// Interrupt for LEFT encoder
ISR (PCINT2_vect){
  static uint8_t enc_last = 0;
  enc_last <<= 2;
  enc_last |= (PIND & (3 << 2)) >> 2;
  left_enc_pos += ENC_STATES[(enc_last & 0x0f)];
}

// Return encoder count (only LEFT)
long readEncoder(int i) {
  return left_enc_pos;
}

// Reset encoder (only LEFT)
void resetEncoder(int i) {
  left_enc_pos = 0L;
}

// Reset all encoders (only LEFT in use)
void resetEncoders() {
  resetEncoder(LEFT);
}

#endif
