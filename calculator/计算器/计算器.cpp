// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
void duru(char a[], int zu, int yo, float *x)
{
	char b[100];
	int q = 0, w, pp;
	w = zu + 1;
	for (; w != yo;)
	{
		b[q] = a[w];
		q++;
		w++;
	}
	*x = atof(b);
	pp = 0;
	for (; pp < 100; pp++)
		b[pp] = ' ';



}

void kuohaojisuan(char a[], int zuo, int you)
{
	int i = zuo, dingwei, left, right, qing, li, pp, ceshi;
	float x, y, jie;
	char b[100];
	a[zuo] = ' ';
	a[you] = ' ';

	for (; i < you;)
	{
		for (; a[i] != '*'&&a[i] != '/'&&i<you;)
			i++;
		ceshi = i - 1;
		for (; a[ceshi] == ' '&&ceshi>zuo;)
			ceshi--;
		if (ceshi == zuo)
		{
			i = i + 1;
			for (; a[i] != '+'&&a[i] != '-'&&i < you;)
				i++;
		}


		if (i<you)
		{
			dingwei = i - 1;
			for (; a[dingwei] != '+'&&a[dingwei] != '-'&&dingwei>zuo&&a[dingwei] != '*'&&a[dingwei] != '/';)
				dingwei--;
			if (a[dingwei] == '-')
			{
				ceshi = dingwei - 1;
				for (; a[ceshi] == ' '&&ceshi > zuo;)
					ceshi--;
				if (ceshi == zuo)
					dingwei = ceshi;

			}
			left = dingwei;
			duru(a, dingwei, i, &x);
			dingwei = i + 1;
			for (; a[dingwei] != '+'&&a[dingwei] != '-'&&dingwei < you&&a[dingwei] != '*'&&a[dingwei] != '/';)
				dingwei++;
			if (a[dingwei] == '-')
				ceshi = dingwei - 1;
			for (; a[ceshi] == ' ';)
				ceshi--;
			if (ceshi == i)
			{
				dingwei++;
				for (; a[dingwei] != '+'&&a[dingwei] != '-'&&dingwei < you&&a[dingwei] != '*'&&a[dingwei] != '/';)
					dingwei++;
			}
			right = dingwei;
			duru(a, i, dingwei, &y);
			if (a[i] == '*')
				jie = x*y;
			else
				jie = x / y;
			sprintf(b, "%f", jie);
			qing = left + 1;
			li = 0;
			a[i] = ' ';
			for (; qing != right; qing++)
			{
				a[qing] = b[li];
				li++;
			}
			pp = 0;
			for (; pp < 100; pp++)
				b[pp] = ' ';
		}
	}


	i = zuo;
	for (; i < you;)
	{
		for (; a[i] != '+'&&a[i] != '-'&&i<you;)
			i++;

		ceshi = i - 1;
		for (; a[ceshi] == ' '&&ceshi>zuo;)
			ceshi--;
		if (ceshi == zuo)
		{
			i = i + 1;
			for (; a[i] != '+'&&a[i] != '-'&&i < you;)
				i++;
		}




		if (i<you)
		{
			dingwei = i - 1;
			for (; a[dingwei] != '+'&&a[dingwei] != '-'&&dingwei>zuo;)
				dingwei--;
			if (a[dingwei] == '-')
			{
				ceshi = dingwei - 1;
				for (; a[ceshi] == ' '&&ceshi > zuo;)
					ceshi--;
				if (ceshi == zuo)
					dingwei = ceshi;

			}
			left = dingwei;
			duru(a, dingwei, i, &x);
			dingwei = i + 1;
			for (; a[dingwei] != '+'&&a[dingwei] != '-'&&dingwei < you;)
				dingwei++;
			if (a[dingwei] == '-')
				ceshi = dingwei - 1;
			for (; a[ceshi] == ' ';)
				ceshi--;
			if (ceshi == i)
			{
				dingwei++;
				for (; a[dingwei] != '+'&&a[dingwei] != '-'&&dingwei < you&&a[dingwei] != '*'&&a[dingwei] != '/';)
					dingwei++;
			}
			right = dingwei;
			duru(a, i, dingwei, &y);
			if (a[i] == '+')
				jie = x + y;
			else
				jie = x - y;
			sprintf(b, "%f", jie);
			qing = left + 1;
			li = 0;
			a[i] = ' ';
			for (; qing != right; qing++)
			{
				a[qing] = b[li];
				li++;
			}
			pp = 0;
			for (; pp < 100; pp++)
				b[pp] = ' ';
		}
	}
}


int main()
{
	for (;;)
	{
		printf("\n");
		char str[1000];
		int weizhi = 0, zongshu = 0, n = 0, p = 0;
		int i = 0, you = 0, zuo = 0;
		float jieguo;
		printf("> ");
		for (; str[i - 1] != '\n'; i++)
			str[i] = getchar();
		zongshu = i - 2;
		for (; str[n] == ' ';)
			n++;
		if (str[n] == '-')
		{
			zongshu = zongshu + 1;
			p = zongshu;
			for (; p != 0; p--)
				str[p] = str[p - 1];
			str[0] = '0';
		}
		zongshu = zongshu + 2;
		str[zongshu] = ')';
		p = zongshu - 1;

		for (; p != 0; p--)
			str[p] = str[p - 1];
		str[0] = '(';

		for (; you < zongshu;)
		{
			for (; str[you] != ')';)
				you++;
			zuo = you;
			for (; str[zuo] != '(';)
				zuo--;
			kuohaojisuan(str, zuo, you);
		}

		jieguo = atof(str);
		printf("= %.2f", jieguo);//���������λС�� 
		/*��Ϊ�м������float���档 ���Դ������ֵ��ʵ��ֵ�Ľ���ֵ��
		���索��0.1���Ժ�����0.09999999999999.�����Ժ�Ҫע��� */


	}
	return 0;
}
