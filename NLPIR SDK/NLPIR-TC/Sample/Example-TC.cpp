// win_cDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "NLPIR-TC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef OS_LINUX
#ifdef NLPIR_STATIC
#pragma comment(lib, "../../../bin/ICTCLAS/NLPIR-TCStatic.lib")
#else

#ifndef WIN64
#pragma comment(lib, "../../../bin/ICTCLAS/NLPIR-TC.lib")
#else
#pragma comment(lib, "../../../bin/ICTCLAS/x64/NLPIR-TC.lib")
#endif
#endif

#endif

int main(int argc,char *argv[])
{
	if (argc<3)
	{
		printf("Usage: %s [Data_Path] [input_filename]\n", argv[0]);
	}
	//��ʼ���ִ����
	if (!NLPIRTC_Init(argv[1]))//�����ڵ�ǰ·����; "D:/NLPIR/Data-TC/"  "D:/NLPIR/Data-TC/testFanti.txt"
	{
		printf("ICTCLAS-TC INIT FAILED! Error message=%s\n",NLPIRTC_GetLastErrorMsg());
		return -1;
	}
	printf("ICTCLAS-TC INIT success!\n");
	char sResultFile[1023];
	strcpy(sResultFile, argv[2]);
	strcat(sResultFile, "_result.txt");
	NLPIRTC_FileProcess(argv[2], sResultFile);
	NLPIRTC_Exit();
	
	return 0;
}	