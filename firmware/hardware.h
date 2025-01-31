extern volatile uint16_t ticks;

#define LED PORTD,5

#define UART_TX PORTD,1

#define NO_OF_POLES 4

#define SDA PORTC,4
#define SCL PORTC,5

#define P_UP_PIN_BV _BV(3)	// A_top, HS_A
#define P_UP PORTD,3
#define P_VP_PIN_BV _BV(4)	// B_top, HS_B
#define P_VP PORTD,4
#define P_WP_PIN_BV _BV(5)	// C_top, HS_C
#define P_WP PORTD,5

#define P_UN_PIN_BV _BV(0)	// A_bot, LS_A
#define P_UN PORTB,0
#define P_VN_PIN_BV _BV(1)	// B_bot, LS_B
#define P_VN PORTB,1 // OC1A
#define P_WN_PIN_BV _BV(2)	// C_bot, LS_C
#define P_WN PORTB,2 // OC1B

#define PHASE_U_IN PORTD,7	// SENSE_A
#define PHASE_V_IN PORTC,4	// SENSE_B
#define PHASE_W_IN PORTC,5	// SENSE_C
				// SENSE_X is not used

#define ID0 PORTD,0
#define ID1 PORTD,1
#define ID2 PORTD,2

// funcs
#define ADMUX_U 0
#define ADMUX_V _BV(MUX0)
#define ADMUX_W _BV(MUX1)

#define UN_TCCR2  (_BV(COM21))
#define UN_TCCR1A 0

#define VN_TCCR2  0
#define VN_TCCR1A (_BV(COM1B1))

#define WN_TCCR2  0
#define WN_TCCR1A (_BV(COM1A1))

#define ENABLE_UN TCCR2 |= (_BV(COM21)/* | _BV(COM20)*/)
#define DISABLE_UN TCCR2 &= ~(_BV(COM21)/* | _BV(COM20)*/)

#define ENABLE_UP IO_HIGH(P_UP)
#define DISABLE_UP IO_LOW(P_UP)

#define ENABLE_VN TCCR1A |= (_BV(COM1B1)/* | _BV(COM1B0)*/)
#define DISABLE_VN TCCR1A &= ~(_BV(COM1B1)/* | _BV(COM1B0)*/)

#define ENABLE_VP IO_HIGH(P_VP)
#define DISABLE_VP IO_LOW(P_VP)

#define ENABLE_WN TCCR1A |= (_BV(COM1A1)/* | _BV(COM1A0)*/)
#define DISABLE_WN TCCR1A &= ~(_BV(COM1A1)/* | _BV(COM1A0)*/)

#define ENABLE_WP IO_HIGH(P_WP)
#define DISABLE_WP IO_LOW(P_WP)

#define DISABLE_ALL() { DISABLE_UP; DISABLE_UN; DISABLE_VP; DISABLE_VN; DISABLE_WP; DISABLE_WN; }
