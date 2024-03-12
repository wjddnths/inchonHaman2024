#include <stdio.h>
#include <conio.h>
int test01(); // 함수의 prototype
void test02(int a);
main()
{
	//test01();
	test02(1);
}
int test01()
{
	// 변수의 선언
	//char vchar;
	//int vint;
	//long vlong;
	//float vfloat;
	//double vdouble;

	// 변수의 초기화
	//vchar = 'f';
	//vint = 10;
	//vlong = 4000000000;
	//vfloat = 3.14159265;
	//vdouble = 314159265.123456789;

    //printf("\n안녕하세요?\n");
	//printf("%8x \n%8x \n%8x \n%8x\n", &vchar, &vint, &vlong, &vfloat);
	//scanf("%c %d %d %f", &vchar, &vint, &vlong, &vfloat);
	//printf("정수 출력 테스트 : [%12d]\n", vint); // 4byte
	//printf("실수 출력 테스트 : [%12.8f]\n", vfloat); // 4
	//printf("지수 출력 테스트 : [%12e]\n", vdouble); // 4byte
	
	//printf("8진수 출력 테스트 : [%12o]\n", vint); // 4byte
	//printf("16진수 출력 테스트 : [%12x]\n", vint); // 4byte

	//printf("문자 출력 테스트 : [%c]\n", vchar); // 1byte
	//printf("문자 연산 테스트 : [%c]\n", vchar + 1); // 4byte
	//안녕하세요?
	char* str[] = {"Zero","One","Two","Three","Four","Five",
		"Six","Seven","Eight","Nine"}; //문자열 포인터 배열
	printf("숫자 키를 입력하세요. 해당하는 영단어를 알려드리겠습니다.\n");
	printf("프로그램을 끝내시려면 'Q' 키를 입력하세요. \n\n");
	int n = 1;
     while (n)
	{
		printf(">");
		char c = getch(); //no echo : 키값을 출력하지 않고 반환 
		/*char c1 = getchar(); // [enter] 필요.

		//if (c == '1') printf("%c : One\n", c);
		//else if (c == '2') printf("%c : Two\n", c);
		//else if (c == '3') printf("%c : Three\n", c);
		//else if (c | 0x20 == 'q') break; //40H 60H

		//switch (c)
		{
		case '1': printf("%c : One\n", c); break;
		case '2': printf("%c : Two\n", c); break;
		case '3': printf("%c : Three\n", c); break;
		case 'q':
		case 'Q': n = 0; break;
		}*/
		//int m = c - 0x30; //ASCII --> num
        printf("%c : %s\n", c, str[c - 0x30]);
	}
}
void test02(int a) //문자열과 문자배열
{
	char ca[] = "HELLO"; //ca[0]:'H' ...ca[4]:'o' ca[5]:\0
	for (int i = 0; i < 10; i++) // 0 ~ 5
	{
		printf("ca[%d] : %c(%02x)\n", i, ca[i], ca[i]);
	}
	ca[2] -= 1;
	ca[3] -= 1;
	for (int i = 0; i < 10; i++) // 0 ~ 5
	{
		printf("ca[%d] : %c(%02x)\n", i, ca[i], ca[i]);
	}
}
