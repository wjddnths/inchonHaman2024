#include <stdio.h>

void test01(); // 함수의 prototype
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();

void Dump(char* p, int len); // 메모리 공간 출력용 범용함수

// -----함수의 설계 -----
// Prototype : void copy(char* p1, char* p2);
// 함수명 : Copy
// 기능 : p2 문자열을 인수로 받아서 p1 문자열로 복사
// 인수 : 타겟문자열,소스문자열 - char *p1, char *p2
// 리턴값 : void
void Copy(char* p1, char* p2);

// -----함수의 설계 -----
// Prototype : int Lenght(char* str)
// 함수명 : Length
// 기능 : 문자열을 인수로 받아서 문자열의 길이를 반환
// 인수 : 문자열 - char *str
// 리턴값 : 문자열의 길이 - int len
int Length(char* str);






main()
{
	int n;
	void* pF[] = { test01, test02, test03, test04, test05, test06, test07 };
	void (*pFunc) ();
	while (1)
	{
		printf("\n\n\n\n\n");
		printf("1, 숫자키에 대한 문자열 출력 미션\n");
		printf("2, 문자열과 문자 배열\n");
		printf("3, 포인터 위치 지정\n");
		printf("4, 포인터를 이용한 문자열 입출력 함수\n");
		printf("5, 구조체 테스트\n");
		printf("6, 표준함수 테스트\n");
		printf("7, Length 함수 테스트\n");
		printf("0, 종  료\n");
		printf("=====================================\n");
		scanf("%d", &n);
		if (n == 0) return;
		pFunc = pF[n - 1];
		pFunc();
	}
	//test01();
	//test02(1);
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();

}
void test01()
{
	// 변수의 선언
	char vchar;
	int vint;
	long vlong;
	float vfloat;
	double vdouble;

	// 변수의 초기화
	/*vchar = 'f';
	vint = 10;
	vlong = 4000000000;
	vfloat = 3.14159265;
	vdouble = 314159265.123456789;

	printf("\n안녕하세요?\n");
	printf("%8x \n%8x \n%8x \n%8x\n", &vchar, &vint, &vlong, &vfloat);
	scanf("%c %d %d %f", &vchar, &vint, &vlong, &vfloat);
	printf("정수 출력 테스트 : [%12d]\n", vint); // 4byte
	printf("실수 출력 테스트 : [%12.8f]\n", vfloat); // 4
	printf("지수 출력 테스트 : [%12e]\n", vdouble); // 4byte

	printf("8진수 출력 테스트 : [%12o]\n", vint); // 4byte
	printf("16진수 출력 테스트 : [%12x]\n", vint); // 4byte

	printf("문자 출력 테스트 : [%c]\n", vchar); // 1byte
	printf("문자 연산 테스트 : [%c]\n", vchar + 1); */ // 4byte
	//안녕하세요?
	char* str[] = { "Zero","One","Two","Three","Four","Five",
		"Six","Seven","Eight","Nine" }; //문자열 포인터 배열
	printf("숫자 키를 입력하세요. 해당하는 영단어를 알려드리겠습니다.\n");
	printf("프로그램을 끝내시려면 'Q' 키를 입력하세요. \n\n");
	int n = 1;
	while (n)
	{
		printf(">");
		char c = getch(); //no echo : 키값을 출력하지 않고 반환 
		/*char c1 = getchar(); // [enter] 필요.

		if (c == '1') printf("%c : One\n", c);
		else if (c == '2') printf("%c : Two\n", c);
		else if (c == '3') printf("%c : Three\n", c);
		else if (c | 0x20 == 'q') break; //40H 60H

		switch (c)
		{
		case '1': printf("%c : One\n", c); break;
		case '2': printf("%c : Two\n", c); break;
		case '3': printf("%c : Three\n", c); break;
		case 'q':
		case 'Q': n = 0; break;
		}*/
		//int m = c - 0x30; //ASCII --> num
		if ((c | 0x20) == 'p') break; // 40H 60H
		printf("%c : %s\n", c, str[c - 0x30]); //str[n][m]
	}
}
void test02() //문자열과 문자배열
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
void test03()
{
	char buf[100];     // 안전 메모리 공간 확보
	char* pBuf;        // 안전 메모리 공간중의 출력 위치
	unsigned int addr; // 출력 위치 지정을 위한 입력 변수(주소)
	char kBuf[100];    // 출력 문자열 입력 공간
	printf("안전공간의 주소는 %d[%08x] 입니다.\n", (unsigned int)buf, buf);
	printf("입력을 시작할 주소를 입력하세요 : ");
	scanf("%d", &addr); // 안전공간 주소 참고
	pBuf = buf + addr;
	printf("문자열을 입력하세요 : ");
	scanf("%s", kBuf);
	Copy(pBuf, "kBuf"); //문자열 복사
	Dump(buf, 100);
}
void test04()
{
	char* arr[10] = { "aaaaa","bbbb","ccc","dd","eeeee" };
	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] : 0x%08x\n", i, arr[i]);
	}
}
void test05() // 구조체 테스트
{
	struct stTest
	{
		int i;
		float a;
		//char* name;
		char name[20];
	}
	s1 = { 1, 3.14, "삼천갑자 동방삭" };//
	//s1.name = "삼천갑자 동방삭";
	struct stTest s2 = s1;

	printf("sizeof(struct stTest) : %d\n", sizeof(struct stTest));

	printf("struct stTest S1 : %d %f %s\n", s1.i, s1.a, s1.name);
	printf("struct stTest S2 : %d %f %s\n", s1.i, s1.a, s1.name);
}
void test06()
{
	char* s1;// = "Good";
	char* s2;// = "afternoon";
	char buf[100];
	s1 = buf;
	s2 = buf + 50;
	scanf("%s", s1);
	scanf("%s", s2);
	//strcat Test
	printf("s1 : %s(%d)\n", s1, strlen(s1));
	printf("s2 : %s(%d)\n", s2, strlen(s2));
	strcpy(buf, s1);
	strcat(buf, s2);
	printf("strcat(s1,s2) : %s", buf);
	//sprintf(buf, "strcat(s1,s2) : %s%s", s1, s2); printf("%s", buf);
}
void test07()
{
	char buf[100];
	printf("문자열을 입력하세요 : "); scanf("%s", buf);
	printf("입력한 문자열의 길이는   [ %d ] 입니다.\n\n", Length(buf));
}


void Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0;
}
void Dump(char* p, int len) //메모리 공간 출력용 범용함수
{
	for (int i = 0; i < len; i++) //안전공간 메모리 덤프
	{
		if (i % 16 == 0) printf("\n%08x ", p);
		if (i % 8 == 0) printf("   ");
		printf("%02x", (unsigned char)*p++);

	}
}
int Length(char* str)// 문자열 str을 인수로 받아서 길이를 반환
{
	int len = 0; // 반환할 문자열의 길이
	while (1)
	{
		if (*(str + len) == 0) break; // 문자열의 끝(null)에 도달했으면 탈출
		len++;
	}
	return len;
}

