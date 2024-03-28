/*
 * test02-7seg.c
 *
 * Created: 2024-03-21 오후 3:34:31
 * Author : SYSTEM-00
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/delay.h>
#include <util/delay.h>

#define __delay_t 500

uint8_t digit[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67,0x77, 0x7C, 0x58, 0x5E, 0x79, 0x71};
	char arr[5]; // 세그먼트 이미지 정보를 담을 안전 영역
	
void TogglePinC(int n, double dl) // p : PORTx의 포인터, n : n 번째 비트, dl : delay in mili-second
{
	char b = 1 << n;
	PORTC |= b; //portA의 0번쨰 비트를 HIGH로 출력
	_delay_ms(__delay_t);
	PORTC &= ~b; //portA의 0번째 비트를 LOW로 출력
	_delay_ms(__delay_t);
}

void LED(char *p, int n) // p : PORTx의 포인터, n : n 번째 비트
{
	char b = 1 << n;
	*p |= b; //portA의 0번쨰 비트를 HIGH로 출력
    _delay_ms(__delay_t);
    *p &= ~b; //portA의 0번째 비트를 LOW로 출력
    _delay_ms(__delay_t);
}

void seg(int sel, uint8_t c)
{
	PORTB != 0X0F;
	PORTB &= ~(1 << (3-sel));
	PORTA = c;
	_delay_ms(10);
}

void FND_4(char *inf) // segment Image 배열
{
	for(int i = 0; i < 4; i++)
	{
		seg(i, *(inf+i));
	}
}

char* Trans(unsigned long num) // 10진 정수 ==> 16진수 문자열 : 56506 ==> 0xDCBA 
                       //         ==> 16진수 segment Image 배열
{
	int n1 = num % 16;          // A (10) : 문자가 아닌 숫자
	int n2 = (num / 16) % 16;   // B (11)
	int n3 = (num / 256 ) % 16; // C (12)
	int n4 = (num / 4096);      // D (13)
	arr[0] = digit[n1];
	arr[1] = digit[n2];
	arr[2] = digit[n3];
    arr[3] = digit[n4];
	
	//FND_4(arr);
	return arr;
}
int main(void)
{
    uint8_t digit[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67,0x77, 0x7C, 0x58, 0x5E, 0x79, 0x71};
		unsigned long j = 0;
		//int i, j = 0;
		//DDRC = 0x07;
		DDRA = 0xFF; //세그먼트 제어 핀 8개를 출력으로 설정
		DDRB = 0x0F;
		int mode = 0;
		 //자릿수 선택 핀 4개를 출력으로 설정
    while (1) 
    {
		//TogglePinC(2,__delay_t);
		//LED(&PORTC, 1);
		if(!(PINC & 0x01 == 1)) // sw가 눌렸을 때 ture
		{
			
			mode++;
		switch(mode)
		{
			case 0:
			
			break;
		} 
		}
	 FND_4(Trans(j++));
	 _delay_ms(10);
	
	
		 
		/*for(i = 0; i < 4; i++)
		{
			// 해당 자리에만 0(GND)을 출력하고 나머지에는 1을 출력하여 자리 선택
			PORTB &= ~0X0F;
			PORTB |= ~(1 << (3-i));
			for(j = 0; j < 16; j++)
			{
				PORTA = digit[j];
				_delay_ms(300);
			}
		}
    }
	return 0;
}*/

