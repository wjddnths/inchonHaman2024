#include <stdio.h>
#include <conio.h>
int test01(); // �Լ��� prototype
void test02(int a);
main()
{
	//test01();
	test02(1);
}
int test01()
{
	// ������ ����
	//char vchar;
	//int vint;
	//long vlong;
	//float vfloat;
	//double vdouble;

	// ������ �ʱ�ȭ
	//vchar = 'f';
	//vint = 10;
	//vlong = 4000000000;
	//vfloat = 3.14159265;
	//vdouble = 314159265.123456789;

    //printf("\n�ȳ��ϼ���?\n");
	//printf("%8x \n%8x \n%8x \n%8x\n", &vchar, &vint, &vlong, &vfloat);
	//scanf("%c %d %d %f", &vchar, &vint, &vlong, &vfloat);
	//printf("���� ��� �׽�Ʈ : [%12d]\n", vint); // 4byte
	//printf("�Ǽ� ��� �׽�Ʈ : [%12.8f]\n", vfloat); // 4
	//printf("���� ��� �׽�Ʈ : [%12e]\n", vdouble); // 4byte
	
	//printf("8���� ��� �׽�Ʈ : [%12o]\n", vint); // 4byte
	//printf("16���� ��� �׽�Ʈ : [%12x]\n", vint); // 4byte

	//printf("���� ��� �׽�Ʈ : [%c]\n", vchar); // 1byte
	//printf("���� ���� �׽�Ʈ : [%c]\n", vchar + 1); // 4byte
	//�ȳ��ϼ���?
	char* str[] = {"Zero","One","Two","Three","Four","Five",
		"Six","Seven","Eight","Nine"}; //���ڿ� ������ �迭
	printf("���� Ű�� �Է��ϼ���. �ش��ϴ� ���ܾ �˷��帮�ڽ��ϴ�.\n");
	printf("���α׷��� �����÷��� 'Q' Ű�� �Է��ϼ���. \n\n");
	int n = 1;
     while (n)
	{
		printf(">");
		char c = getch(); //no echo : Ű���� ������� �ʰ� ��ȯ 
		/*char c1 = getchar(); // [enter] �ʿ�.

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
void test02(int a) //���ڿ��� ���ڹ迭
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
