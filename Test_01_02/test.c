/*
date��2019/01/02
author:BetterMe1
program:�ж��ֽ���value������λģʽ��ת����ʹ�ã�a+b��/2��ƽ��ֵ��
һ���������ҳ�ֻ����һ�ε����֡�������Ϊ"student a am i"�ַ������Ϊ"i am a student"
compiler:Visual Studio 2013
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
1.����ֽ����С���ֽ���ĸ��
��ˣ��洢����ʽ�����ݵĵ�λ�������ڴ�ĸߵ�ַ�ϣ����ݵĸ�λ�������ڴ�ĵ͵�ַ�ϡ�
С�ˣ��洢����ʽ�����ݵĵ�λ�������ڴ�ĵ͵�ַ�ϣ����ݵĸ�λ�������ڴ�ĸߵ�ַ�ϡ�
���һ��С�������жϵ�ǰ�������ֽ���
*/
//int IslitttleEnd(){
//	int num = 0x11223344;
//	char *p = (char*)&num;//ǿ������ת��
//	if (*p == 0x11){
//		return 0;
//	}
//	return 1;
//}
//
//int main(){
//	if (IslitttleEnd() == 1){
//		printf("С��\n");
//	}
//	else{
//		printf("���\n");
//	}
//	system("pause");
//	return 0;
//}
/*
2.��д������
unsigned int reverse_bit(unsigned int value);
��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
�磺
��32λ������25���ֵ�������и�λ��
00000000000000000000000000011001
��ת�󣺣�2550136832��
10011000000000000000000000000000
���������أ�
2550136832
*/

//�޷������ͱ�ʾ�ķ�Χ��0-255
//��������ȡ��������������Ƶ�ÿһλ���������飬�ٽ��䷴�ż����ʮ���ƽ����Ϊ����ֵ
//unsigned int reverse_bit(unsigned int value){
//	unsigned int re[32] = { 0 };//���value�������е�ÿһλ
//	unsigned int ret = 0;
//	//�����������
//	for (int i = 0; i < 32; i++){
//		re[i] = (value>>i) & 1;
//	}
//	//10011000000000000
//	for (int i = 31; i >= 0; i--){
//		if (re[31 - i] == 1){
//			ret = ret + (2 << (i-1));
//		}
//	}
//	return ret;
//}
//int main(){
//	printf("%u\n",reverse_bit(25));
//	system("pause");
//	return 0;
//}
/*
3.��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��
*/
//int average(int a,int b){
//	a = a >> 1;
//	b = b >> 1;
//	return a + b;
//}
//int main(){
//	printf("%d\n",average(10, 20));
//	system("pause");
//	return 0;
//}

/*
4.���ʵ�֣�
һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
���ҳ�������֡���ʹ��λ���㣩
*/
//������
//�ҳ��������ֵ�����,��Ҫ�ų��ɶԳ��ֵ����֣�
//��������ȡ���λ��򡱻���㣬�������κ�����򣬵õ��κ�������

//int main(){
//	int n = 0;
//	int arr[9] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
//	int len = sizeof(arr)/sizeof(arr[0]);//sizeof��һ����Ŀ�����������ǿ⺯��
//	int ret = arr[0];
//	for (int i = 1; i <len; i++){
//		ret = ret^arr[i];//��ͬʱ���Ϊ0�����ų���������ͬʱ�õ�����
//	}
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

/*
5.
��һ���ַ����������Ϊ:"student a am i",
���㽫��������ݸ�Ϊ"i am a student".
Ҫ��
����ʹ�ÿ⺯����
ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
student a am i
i ma a tneduts
i am a student
*/

/*
�������Ƚ��ַ���ȫ�����ã��ڽ��ո�֮����ַ�����������
*/
char* reverse(char* a){
	char* l = a;
	char* r = a;
	while (*r != '\0'){
		r++;
	}
	while (l < r - 1){
		char temp = *l;
		*l = *(r - 1);
		*(r - 1) = temp;
		l++;
		r--;
	}
	l = a;
	r = a;
	while (*r != '\0'){
		//���㵽�ո�֮��ĳ���
		while (*r != ' '&& *r != '\0'){
			r++;
		}
		char* p = r;//��¼�Ҷ�
		while (l < r - 1){
			char temp = *l;
			*l = *(r - 1);
			*(r - 1) = temp;
			l++;
			r--;
		}
		if (*p == '\0'){
			return a;
		}
		l = p + 1;
		r = p + 1;
	}
	return a;
}
int main(){
	char a[] = "student a am i";
	char* ret = reverse(a);
	printf("%s\n", ret);
    system("pause");
	return 0;
}