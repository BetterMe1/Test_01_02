/*
date：2019/01/02
author:BetterMe1
program:判断字节序、value二进制位模式翻转、不使用（a+b）/2求平均值、
一组数据中找出只出现一次的数字、将内容为"student a am i"字符数组改为"i am a student"
compiler:Visual Studio 2013
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
1.大端字节序和小端字节序的概念：
大端（存储）方式：数据的低位保存在内存的高地址上，数据的高位保存在内存的低地址上。
小端（存储）方式：数据的低位保存在内存的低地址上，数据的高位保存在内存的高地址上。
设计一个小程序来判断当前机器的字节序。
*/
//int IslitttleEnd(){
//	int num = 0x11223344;
//	char *p = (char*)&num;//强制类型转换
//	if (*p == 0x11){
//		return 0;
//	}
//	return 1;
//}
//
//int main(){
//	if (IslitttleEnd() == 1){
//		printf("小端\n");
//	}
//	else{
//		printf("大端\n");
//	}
//	system("pause");
//	return 0;
//}
/*
2.编写函数：
unsigned int reverse_bit(unsigned int value);
这个函数的返回值value的二进制位模式从左到右翻转后的值。
如：
在32位机器上25这个值包含下列各位：
00000000000000000000000000011001
翻转后：（2550136832）
10011000000000000000000000000000
程序结果返回：
2550136832
*/

//无符号整型表示的范围是0-255
//分析：提取出传入参数二进制的每一位，存入数组，再将其反着计算出十进制结果作为返回值
//unsigned int reverse_bit(unsigned int value){
//	unsigned int re[32] = { 0 };//存放value二进制中的每一位
//	unsigned int ret = 0;
//	//反向存入数组
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
3.不使用（a+b）/2这种方式，求两个数的平均值。
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
4.编程实现：
一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
请找出这个数字。（使用位运算）
*/
//分析：
//找出单独出现的数字,便要排除成对出现的数字，
//而两数相等“按位异或”会得零，而零与任何数异或，得到任何数本身

//int main(){
//	int n = 0;
//	int arr[9] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
//	int len = sizeof(arr)/sizeof(arr[0]);//sizeof是一个单目操作符，不是库函数
//	int ret = arr[0];
//	for (int i = 1; i <len; i++){
//		ret = ret^arr[i];//相同时结果为0；即排除两数，不同时得到本身
//	}
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

/*
5.
有一个字符数组的内容为:"student a am i",
请你将数组的内容改为"i am a student".
要求：
不能使用库函数。
只能开辟有限个空间（空间个数和字符串的长度无关）。
student a am i
i ma a tneduts
i am a student
*/

/*
分析：先将字符串全部逆置，在将空格之间的字符串进行逆置
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
		//计算到空格之间的长度
		while (*r != ' '&& *r != '\0'){
			r++;
		}
		char* p = r;//记录右端
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