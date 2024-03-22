#include <stdio.h>

void test01(); // �Լ��� prototype
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();

void Dump(char* p, int len); // �޸� ���� ��¿� �����Լ�

// -----�Լ��� ���� -----
// Prototype : void copy(char* p1, char* p2);
// �Լ��� : Copy
// ��� : p2 ���ڿ��� �μ��� �޾Ƽ� p1 ���ڿ��� ����
// �μ� : Ÿ�ٹ��ڿ�,�ҽ����ڿ� - char *p1, char *p2
// ���ϰ� : void
void Copy(char* p1, char* p2);

// -----�Լ��� ���� -----
// Prototype : int Lenght(char* str)
// �Լ��� : Length
// ��� : ���ڿ��� �μ��� �޾Ƽ� ���ڿ��� ���̸� ��ȯ
// �μ� : ���ڿ� - char *str
// ���ϰ� : ���ڿ��� ���� - int len
int Length(char* str);






main()
{
	int n;
	void* pF[] = { test01, test02, test03, test04, test05, test06, test07 };
	void (*pFunc) ();
	while (1)
	{
		printf("\n\n\n\n\n");
		printf("1, ����Ű�� ���� ���ڿ� ��� �̼�\n");
		printf("2, ���ڿ��� ���� �迭\n");
		printf("3, ������ ��ġ ����\n");
		printf("4, �����͸� �̿��� ���ڿ� ����� �Լ�\n");
		printf("5, ����ü �׽�Ʈ\n");
		printf("6, ǥ���Լ� �׽�Ʈ\n");
		printf("7, Length �Լ� �׽�Ʈ\n");
		printf("0, ��  ��\n");
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
	// ������ ����
	char vchar;
	int vint;
	long vlong;
	float vfloat;
	double vdouble;

	// ������ �ʱ�ȭ
	/*vchar = 'f';
	vint = 10;
	vlong = 4000000000;
	vfloat = 3.14159265;
	vdouble = 314159265.123456789;

	printf("\n�ȳ��ϼ���?\n");
	printf("%8x \n%8x \n%8x \n%8x\n", &vchar, &vint, &vlong, &vfloat);
	scanf("%c %d %d %f", &vchar, &vint, &vlong, &vfloat);
	printf("���� ��� �׽�Ʈ : [%12d]\n", vint); // 4byte
	printf("�Ǽ� ��� �׽�Ʈ : [%12.8f]\n", vfloat); // 4
	printf("���� ��� �׽�Ʈ : [%12e]\n", vdouble); // 4byte

	printf("8���� ��� �׽�Ʈ : [%12o]\n", vint); // 4byte
	printf("16���� ��� �׽�Ʈ : [%12x]\n", vint); // 4byte

	printf("���� ��� �׽�Ʈ : [%c]\n", vchar); // 1byte
	printf("���� ���� �׽�Ʈ : [%c]\n", vchar + 1); */ // 4byte
	//�ȳ��ϼ���?
	char* str[] = { "Zero","One","Two","Three","Four","Five",
		"Six","Seven","Eight","Nine" }; //���ڿ� ������ �迭
	printf("���� Ű�� �Է��ϼ���. �ش��ϴ� ���ܾ �˷��帮�ڽ��ϴ�.\n");
	printf("���α׷��� �����÷��� 'Q' Ű�� �Է��ϼ���. \n\n");
	int n = 1;
	while (n)
	{
		printf(">");
		char c = getch(); //no echo : Ű���� ������� �ʰ� ��ȯ 
		/*char c1 = getchar(); // [enter] �ʿ�.

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
void test02() //���ڿ��� ���ڹ迭
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
	char buf[100];     // ���� �޸� ���� Ȯ��
	char* pBuf;        // ���� �޸� �������� ��� ��ġ
	unsigned int addr; // ��� ��ġ ������ ���� �Է� ����(�ּ�)
	char kBuf[100];    // ��� ���ڿ� �Է� ����
	printf("���������� �ּҴ� %d[%08x] �Դϴ�.\n", (unsigned int)buf, buf);
	printf("�Է��� ������ �ּҸ� �Է��ϼ��� : ");
	scanf("%d", &addr); // �������� �ּ� ����
	pBuf = buf + addr;
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", kBuf);
	Copy(pBuf, "kBuf"); //���ڿ� ����
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
void test05() // ����ü �׽�Ʈ
{
	struct stTest
	{
		int i;
		float a;
		//char* name;
		char name[20];
	}
	s1 = { 1, 3.14, "��õ���� �����" };//
	//s1.name = "��õ���� �����";
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
	printf("���ڿ��� �Է��ϼ��� : "); scanf("%s", buf);
	printf("�Է��� ���ڿ��� ���̴�   [ %d ] �Դϴ�.\n\n", Length(buf));
}


void Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0;
}
void Dump(char* p, int len) //�޸� ���� ��¿� �����Լ�
{
	for (int i = 0; i < len; i++) //�������� �޸� ����
	{
		if (i % 16 == 0) printf("\n%08x ", p);
		if (i % 8 == 0) printf("   ");
		printf("%02x", (unsigned char)*p++);

	}
}
int Length(char* str)// ���ڿ� str�� �μ��� �޾Ƽ� ���̸� ��ȯ
{
	int len = 0; // ��ȯ�� ���ڿ��� ����
	while (1)
	{
		if (*(str + len) == 0) break; // ���ڿ��� ��(null)�� ���������� Ż��
		len++;
	}
	return len;
}

