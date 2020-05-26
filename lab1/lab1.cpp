/*
	� ���������� ���������� ������ ������ ��������� �������� ����� ������ �� �����������
	��� ���������� ������ �������, ������� ������� ��������� ��� ������������������ 
	������������������ ������, ������� ��������� ��������������� �����������������, 
	�������  ��� ���� �� ������������ �������.

	��������� ������������������ �������� ��� ������� �������:
	1. �������� (���������, ���������������� ������ ��������) �������� ����� ���������;
	2. �������������� (Build/Compile  ***.cpp ��� Ctrl+F7)
		���������: ���� ���� ���� �������� �������������, �� ������� ��� ����������� 
			������������, �.�. ��������� ������� ������ (errors) � ��������������
			(warnings), ����������� ��� ���������� ������� ����������� �����;
	3. ����������� ������(Build/Build ***.exe ��� F7)
		��������� 1: ���� ���� ���� ������������, �� ������������ �����������, �.�. 
			��������� ����������������� ������ ���������� ����� � � ������ ����������
			������ ������ ������� ���������� �� ���������� ������������ ���������;
		��������� 2: ����� ���, ��� ������� ������, ������� ���������  � ���, ��� 
			����������� ��� ����� ��������� ���������� ��� ��������� - 
				(Build/Configuration Manager.../Configuration - Debug - ��� ������ �������);
	4. ��������� �� ������������ ��� ������� ��������� ���� ��������(breakpoints) - F9 ��� 
		������ �������� ����� ������� �� ����� ����� ������ ���� ��������������; 
	5. ��������� ��������� � ������ ������� 
		(Debug/Start... ���  F5);

  ���������: ��� ������������� ���� �������� ��������� ���������� ������ � ��������������� 
		������ ����, ������ �� ������ ������� ������� ������� �� �� ����� ����� ������� � 
		������� ������ �� Tool Bar, � ��� ��������� ����� ��������� ��������������.

*/

#include  <iostream>		//��� ������������� ������� �����/������

int nTwin=1;			//���������� ����������
namespace TwinSpace{ int nTwin=2;}	//���������� ��������� �
						//������������ ���� - TwinSpace

#define	  stop __asm nop	//� ������� ���������������� ������ "������" �������.
							//��� ���������������� ����� ������ ��� ����, �����
							//����� ���� ��������� �� ���� ������ ����� ��������.

int main()
{

 //**********************************************************
	//������� 1. ������ � ����������. ������� ���� ������. �������� ��������� �� �����, 
	//������� �� ���������� ���������� � ��������������� ��������� (�������, ��� 
	//���������� ������, ��������� ��� int, �������-��������).
	//�������� �������� �� ������ ������������� ���������� signed � unsigned ����� ����� 
	//������, � ����� �� ���������� ������������� ������������� ����� �����.

	
	char cByte = 'A'; // 65 'A'
	cByte    = 0x42;  // 66 'B'
	cByte    = 66;    // 66 'B'
	cByte    = -1;    // -1 '�'

	unsigned char ucByte = 0x41; // 65 'A'
	ucByte   = 'B';				 // 66 'B'
	ucByte   =	-1;				 // 255 '�'

	int iInt =  0xffffffff;		 // -1

	unsigned int uiInt = 0xffffffff; // 4294967295

	float fFloat = 1.f;				 // 1.00000000 32
	double dDouble = 1.;			 // 1.0000000000000000 64

	// ��������� ��������, ����������� �����. � ������������ ��������,
	// ��� ������� ��������� � ����������. ��������� ������� ����� ���� 
	// ��������� � ���������������.

	double d = 0.1234567890123456789123456789; // 0.12345678901234568
	float  f = 0.1234567890123456789123456789; // 0.123456791

	d	=	1.; //1.0000000000000000
	d	=	0.999999999999999999999999999999999; //1.0000000000000000

	stop
	
	// � ������������ �������� ���������, ������������ ���������� sizeof ���
	// ���������� ���� wchar_t (�� ������)
	wchar_t cw = L'�'; // 1060 '�'
	size_t n = sizeof(cw); // 2

	stop


// **************************************************************
	//������� 2a. ������� ���������� ����� ������.
	//��������� ������� ���������� ��� ���������� (1) � (2):
	//�������� ���� (�������� � ����) ��������������, ������� ������ ��������� ����������

	iInt=1;
	double dDouble1=iInt/3;		// (1) 3 -> int, iInt(1) / int(3) = 0, 0 -> doule, dDouble1 = double(0.0)
	double dDouble2=iInt/3.;	// (2) iInt - > doule, double(1.0) / double(3.0) = 0.(3) = dDouble2


	// ��������������� ����������.
	// ��������� ����� C ��������� "����������" ������������
	// (��� � ������� (1) � (2)). ��������� ���������� ���������� ����� (1) � (2)
	// (�������� ���������� dDouble, fFloat, nInt, sShort, cByte), ���������� ������� 
	// ��������� ������������ ��� ���������� ������ � ��������� ���������.
	// ��������� ������, ���� ������������ ������� ����������, ��� ��� ������ �� ����������.
	// ��������� (� ������������) �������������� (warnings) �����������.

	short sShort;
	dDouble=fFloat=iInt=sShort=cByte=3.3/3;			// (1) dDouble = 1.0000000000000000

	cByte = 3.3 / 3; // cByte = 1
	double dDouble3 = (fFloat = (iInt = (sShort = (cByte = 3.3 / 3))));
	
	cByte=sShort=iInt=fFloat=dDouble=3.3/3;			// (2) cByte = 1
	cByte = (sShort = (iInt = (fFloat = (dDouble = 3.3 / 3))));

	//���� ��� ��� ������ "����������" ������������� �������� ���������� �����, ��� ����� 
	// �������� � ������������� ����������� - ��������� (� ������������), � �����?
	// �������� ���� ��������������, ������� ������ ��������� ����������

	iInt	=	257;
	cByte	=	iInt; // lost - [0000 0000 0000 0000 0000 0001] 0000 0001

	unsigned char cN1=255, cN2=2, cSum;
	cSum = cN1 + cN2; // 

	//-----------------------------------------
	//iInt = 257;
	//  mov         dword ptr[iInt], 101h
	//cByte = iInt;
	//  mov         al, byte ptr[iInt]
	//	mov         byte ptr[cByte], al

	//unsigned char cN1 = 255, cN2 = 2, cSum;
	//  mov         byte ptr[cN1], 0FFh
	//	mov         byte ptr[cN2], 2
	//	cSum = cN1 + cN2; 

	//MOVZX Copies the contents of the source operand (register or memory location) to the destination operand (register) 
	//and zero extends the value.

	//  movzx       eax, byte ptr[cN1]
	//	movzx       ecx, byte ptr[cN2]
	//	add         eax, ecx
	//	mov         byte ptr[cSum], al
	//-----------------------------------------

	//�������� ���������� ������� � ����������� ����. ��������� (� ������������),
	//������ � ��������� ������ �� ���������� ����� �� ��������� �����
	// �������� ���� ��������������, ������� ������ ��������� ����������
	int iSum = cN1+cN2; //

	// unsigned char cN1 -> int cN1
	// unsigned char cN2 -> int cN2
	// int iSum = int cN1 + int cN2

	/*
		movzx       eax, byte ptr[cN1]
		movzx       ecx, byte ptr[cN2]
		add         eax, ecx
		mov         dword ptr[iSum], eax
	*/

	//��������, ������ ��� �������� ���������� �������� (���������� � �������� �������) 
	// � ������� (1) � (2) ���������� ������ ����������
	// �������� ���� ��������������, ������� ������ ��������� ���������� � ���������,
	// ��� ��� ���� ����������
	char c1=0xff, c2=2; // c1 = -1 c2 = 2
	unsigned char uc1=0xff, uc2=2; // uc1 = 255 uc = 2
	int iSum1= c1 + c2;   //(1) iSum = 1
	int iSum2= uc1 + uc2; //(2) iSum = 257

	/*
	MOVSX moves a signed value into a register and sign-extends it with 1.
	MOVZX moves an unsigned value into a register and zero-extends it with zero.
	*/

	/*
		int iSum1 = c1 + c2; 
	movsx       eax, byte ptr[c1]
	movsx       ecx, byte ptr[c2]
	add         eax, ecx
	mov         dword ptr[iSum1], eax
	
		int iSum2 = uc1 + uc2;  
	movzx       eax, byte ptr[uc1]
	movzx       ecx, byte ptr[uc2]
	add         eax, ecx
	mov         dword ptr[iSum2], eax
	*/

	stop

	
// ***********************************************************
	//������� 2b. ����� ���������� ����� ������.
	//������������������ ��������� (�������� ���������� dDouble) � ������ (3)
	// �������� ���� ��������������, ������� ������ ��������� ����������
	int nTmp=100, nn=3;
	dDouble=3.3 + nTmp / nn; // (3) 36.299999999999997

	/*
	The IDIV (signed divide) instruction performs signed integer division, using the same operands as the DIV instruction.

		mov         eax, dword ptr[nTmp]
		cdq
		idiv        eax, dword ptr[nn]
		cvtsi2sd    xmm0, eax
		addsd       xmm0, mmword ptr[__real@400a666666666666 (0848C88h)]
		movsd       mmword ptr[dDouble], xmm0


	Microsoft Specific
	Generates the Convert Double Word Integer to Scalar Double - Precision Floating - Point Value(cvtsi2sd) instruction.
	*/

	//�������� ��������� ��� ������ �������� � ������� ��������� ������
	//���������� ����

	double dResult1 = 3.3 + static_cast<double>(nTmp) / nn; // 36.633333333333333

	/*
	DIVSD � Divide Scalar Double-Precision Floating-Point Value

		cvtsi2sd    xmm0,dword ptr [nTmp]
		cvtsi2sd    xmm1,dword ptr [nn]
		divsd       xmm0,xmm1
		addsd       xmm0,mmword ptr [__real@400a666666666666 (0848C88h)]
		movsd       mmword ptr [dResult1],xmm0
	*/

	//double dDouble3=...
		
	stop

// *******************************************************
	// ������� 3. ������� ��������, ������� ��������� �
	//				����� ������������� ����������

	//   � ���� ��������� ���������� ������ ���������� � ����� � ��� �� ������ 
	// nTwin - ���� ����������, ������ ���������� � ����� ������������ ����, 
	// (���������� ���� � ������ ������) ������ - ��������� ������ ������� main(), 
	// ��������� - ��������� ��������� ������ �����. 
	//   � ������ ������� ��������� � ���������� ������ ��������� ����������, � ����� 
	// �� ������� ���������� ���� ���������, � ����� ���� ������������� � ��������� 
	// ��� ���� �������, �������� ����������� � ������� ������� 
	//	��� ���������� ������� ������������� ������������ ������ "Locals" � "Watches"
	// ���������: - � ���� "Watches" ����� ��������� ��� nTwin
	//			��� � ::nTwin, ������� ��� � TwinSpace::nTwin
	

	nTwin=100;
	TwinSpace::nTwin = 300;
	nTwin++;
	// �������� �������� �� ��������� "����" ���������. ���� ��������� ���������� nTwin
	// �� ��������� ������ ��� �� ���������� (� ��������� ���� �� ����������), �� �����
	// ��� ��� � ����� ������� main ��� �������� (� ��� �����). ���� ������ �  ���� 
	// "Watches" ��������� ������ nTwin, �� �������� ����� ���������� �������� ����, ��� 
	// �� ����������� ��������� ���������� (���-�� ����� -858993460 ��� 0xcccccccc), 
	// ���� ������ ��������� ���������� �������� ���������� ����������, ����������� �����.
	// ���������� ��� ���� ��� ��������� �����.
	// ���� ���� ������� ������ �������� ���������� ����������, �� ���� ���� ������� � ����
	// "Watches" ���������� ������� ���������, �.�. �������� ��� ::nTwin.
	// ����������: ��� ��� ���� �������� �� ��, ����� �� ��������� ��������� ����.
	int nTwin;
	nTwin=200;	
	::nTwin++;  
	{
		int nTwin;
		nTwin=-1;
		::nTwin++;
		TwinSpace::nTwin++;
	}

	nTwin--;


// *******************************************************
	// ������� 4. ������������ ������ ������ - static
	// �) ��� ������ �������� ����� �������� �������� ��������� nLocal# � nStatic#.
	// �) ��������, ����� ����������� ������������� ����� ����������?
	// �) �������� (� �����������) ������� ����� �������� ������������� 
	//     ���������� nStatic1 � nStatic2 � �������� �������� ������, 
	//     �������� �� ���������� nLocal2.

	for (int i=0; i<3; i++)
	{
		static int nStatic1 = 100;
		int nLocal1 = 100;
		int nLocal2 = 200;
		static int nStatic2 = nLocal2++ * 2;
		nStatic1++;
		nStatic2++;
		nLocal1++;
		stop

	}
	// ��������:
	//   �) ��� ���������� ��������� ��������� nStatic1?
	//   �) ��� ��� ���������� ���������������� ?
	for (int i=0; i<3; i++)
	{
		static int nStatic1;
		nStatic1 = 100;
		int nLocal1 = 100;
		nStatic1++;
		nLocal1++;
		stop

	}



// *******************************************************
	// ������� 5. ������������ - enum
	// �������� �������� �� ����� � ������� ������������� ��������
	// �������� ������� �� �����, ������� �� ����������, �������
	// ��������� ���������� myColors


	enum eColors
	{
		BLACK,
		BLUE,
		GREEN,
		RED=5,
		YELLOW,
		WHITE=RED+4
	};

	enum eDigits
	{
		ONE = 1,
		TWO,
		THREE,
		FOUR,
		FIVE
	};

	eDigits digit;
	digit = ONE;
	digit = TWO;
	digit = THREE;
	digit = FOUR;
	digit = FIVE;

	eColors   myColors;	//���������� ���������� ���� eColors 
	myColors=BLACK;
	myColors=BLUE;
	myColors=GREEN;
	myColors=RED;
	myColors=YELLOW;
	myColors=WHITE;

	int nnn = BLACK; //����� ������������� ���������� ����� ���������
					 //�������� �� ������ ���������������� ��������

	//����������� ��������� ����� ������������ � ����������:
	nnn = BLUE | YELLOW;

	//���������������� ��������� ������ � ��������
	//�������� ��  ������ ��� ���������� 
//	myColors = 1;	//������������� ��������� ����� �������, ����� ���������� �� ������� ������
	myColors = BLUE;

	// ��������� ��������� ������������ �� ����� ������������ � ��� ���������� myColors?
//	myColors = 123;
	myColors = static_cast<eColors>(123);

	stop


// *******************************************************
	// ������� 6.1 ���������� ��� bool
	// �������� ������� �� �����, ������� �� ����������
	// ���������� b � ��������������� ���������. �������� ��� �������� � ������������

	int nNumber = 1;
	bool b = (nNumber != 0); //
	b = (nNumber == 0); //
	b = (nNumber > 0); //
	b = (nNumber > 1); //
	b = 5; //

	//�� ������ ������ ������������� ���������� �������� � ������
	//���� ��� ���������� ����� ��� ������� �������������� (������)
	//�������� ��������: ��� �������������� �������� ���������� ���������� ����������?
	int tmp =  b + 1; //

	//������� 6.2 � ������������� ��������� (������� �� ��� ����������) ���������� ���
	// ������������ �� ���������� ���������: ���������� �������� ������ ��������� ���,
	// �� ������ ����� ���������� �� ��������, ��� ���� ������ 400-� ��� ��� ���� 
	// ����������. �.�. 1823 - �� ����������, 1824 - ����������, 1900 - �� ����������,
	// 2000 - ����������.
	// �������� �������� ����, ����� ���:
	// ���������� ���������� isLeapYear ��������� �������� true, ���� ���, ��������
	// ���������� year - ����������.
	// ����������: �� ���� ������������ ����������� if-else, ��������� ���������� � switch
	//             ���� �������� ���������� ��������� � ���� ������.
	{
		//������� ������� ���� ��� ��������:  1823, 1900 - �� ����������, 1824, 2000 - ����������

		//��������� �������� 
		//bool isLeapYear = 
		// ��������� �������� � ���������
		stop
	}

// *******************************************************
	// ������� 7. ����������� const � ����������

	{
		//���������������� ��������� ��� ������� � ��������� (� ������������)
		//������ ��� ���������� 

		//	const int nN; //
		//	nN = 1; //
	}



// ********************************************************
	//������� 8. ���������� �������� ��������� � ��������� ���������.

	//������� 8.1 �������� �������� ����, ������� ��������� ��� �������, 
	//���������� � ���������� ch � ��������������� �������.
	//��������� ������������� �������� ��������, ����� ������������ ���� �����
	//��� ����� ������ �������, ������� ������ �� �������������
	//���������: �������� ������ � ��������� ����������� ��������, ��� �������� � �������
	// ����� ASCII ��� ������ ����� ������� �������� �� 0x20 ������ ���� 
	// ��������������� ����� �������� ��������.
	{
		// ����������� �������� ���������� ch � ������� ������ �����
		char ch ;
		
		//... �������� �������
		// ����� ��������� � ��������� �������� ��� ������ "���" �� �����
		stop
	}


	//������� 8.2 �������� �������� ����, ������� ��������� � ������� if (if/else)
	//��������� ������: ���� x ������ ��� ����� 0, y=0
	//���� x ������ 0 �� ������ 1, �� y=x,
	//���� x ������ ��� ����� 1, �� y=1
	//���������: ������ ���� ������ ��� ����� ���� x � y?
	{
	}

	//������� 8.3 �������� �������� ����, ������� ��������� � ������� switch
	//��������� ������: � ���������� cInput ���� char ���� �������� �������,
	//���������� ����� ��������.
	//���� ������ ������ 'y' (�.�. yes) � ����� ��������, �� ���������
	//���������� � �������� ���������� x
	//���� ������ ������ 'n' (�.�. no) � ����� ��������, �� ���������
	//���������� � �������� (x * 2)
	//���� ����� ������ �����, �� ������� ��������� �� ������
	{
		char ch;
		//������������ ��������
		//switch
	}
	// ********************************************************
	//������� 9. �����.

	//������� 9.1 �������� �������� ����, ������� ��������� � ������� for
	//��������� ������: ����� ����� ��������� ��������� ����� �����.
	//������� ������� � ������� ������ ����� ��� � ������� ������� �������.
	//������������� ������ �� ����� ������ ������� ������, ��� �������.
	{
		
		//������������ ������� ���������

		//��������� ������������ ��������
		
		// ��������� �����
		// ��������� � ��������� ��������
		stop
	}


	//������� 9.2 �������� �������� ����, ������� ��������� � ������� do-while
	//��������� ������: �� ������ �������� ����� ������ � ������� ����� ��������
	// � �������� ����, ���� �������� ������������� �������: 
	// �������� ������ ��� ����� 10 � ������.
	//���������: �������� �� �������� � �������������� �������� ������� �� �������
	//������ ���������� ����� ������������� ���. ���������� ����������� ��������������
	//�������.
	
	{

	}

	//������� 9.3 �������� �������� ����, ������� ��������� � ������� while
	//��������� ������: ������� int x = 0; 
	//�� ������ �������� x=x+1, sum=sum+1/x
	//����� �������� x, ��� ������� sum>1.7
	{

	}
	return 0;//��� ���������� ����������
}	// ����� ������� main()

