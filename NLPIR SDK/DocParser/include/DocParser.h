/****************************************************************************
*
* DocParser  (c) 2019-2020
*     Dr. Kevin Zhang (Hua-Ping Zhang)
*     All rights reserved.
* 
*	强大的文档解析的工具，可以解析doc,docx,pdf,excel,ppt,htm,txt等常见文档；
*	可以识别pdf里面的图片；
*	并读取文档中的图片与表格信息
*
* This file is the confidential and proprietary property of
* Kevin Zhang and the possession or use of this file requires
* a written license from the author.
* Filename:
* Abstract:
*          DocParser.h: definition of the NLPIR Parser API
* Author:   Kevin Zhang
*          Email: pipy_zhang@msn.com kevinzhang@bit.edu.cn
*			Weibo: http://weibo.com/drkevinzhang
*			Homepage: http://www.nlpir.org
* Date:     2019-12-10
*
* Notes:
*
****************************************************************************/
#if !defined(__DOCPARSER_DOC_PARSER_H_INCLUDED__)
#define __DOCPARSER_DOC_PARSER_H_INCLUDED__

#ifdef OS_LINUX
#define DOCPARSER_API extern "C" 
#else
#ifdef DOCPARSER_EXPORTS
#define DOCPARSER_API extern "C" __declspec(dllexport)
#else
#define DOCPARSER_API extern "C"  __declspec(dllimport)
#endif
#endif

//内部兼容使用

#ifdef DOCPARSER_INTERNAL_CALL
#define DOCPARSER_API 
#endif

#define DP_HANDLE  unsigned long long 

/*********************************************************************
*
*  Func Name  : DP_Init
*
*  Description: Init Document Parser
*               The function must be invoked before any operation listed as following
*
*  Parameters : const char * sInitDirPath=NULL
*				 sDataPath:  Path where Data directory stored.
*				 the default value is NULL, it indicates the initial directory is current working directory path
*				 encode: encoding code;
*				 sLicenseCode: license code for unlimited usage. common user ignore it
*  Returns    : success or fail
*  Author     : Kevin Zhang
*  History    :
*              1.create 2013-6-8
*********************************************************************/
DOCPARSER_API int DP_Init(const char * sDataPath = 0, const char*sLicenceCode = 0);

/*********************************************************************
*
*  Func Name  : DP_Exit
*
*  Description: Destroy  Document Parser
*               The function must be invoked before quit the system
*
*  Parameters :void
*  Returns    : void
*  Author     : Kevin Zhang
*  History    :
*              1.create 2020-3-19
*********************************************************************/
DOCPARSER_API void DP_Exit(void);

/*********************************************************************
*
*  Func Name  : DP_File2Txt
*
*  Description: Parse any file to txt json string
*				file type: zip/rar/tar/7z/bz/
*						   doc/docx/xls/xlsx/ppt/pptx
*						   pdf/txt/eml/html
*
*  Parameters : const char *sDocFilename: document filename
*
*
*  Returns    : const char*: the result json string with utf-8 encoded
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2020-3-18
*********************************************************************/
DOCPARSER_API const char* DP_File2Txt(const char *sFilename);

/*********************************************************************
*
*  Func Name  : DP_GetFileExt
*
*  Description: 返回能处理的文档文件格式后缀
*
*  Parameters : const char *sDocFilename: document filename
*
*
*  Returns    : const char*: the result string
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2020-3-18
*********************************************************************/
DOCPARSER_API const char* DP_GetFileExt();

/*********************************************************************
*
*  Func Name  : DP_Parse
*
*  Description: Parse a document file
*
*
*  Parameters : const char *sDocFilename: document filename
*
*				 
*  Returns    : DP_HANDLE: the result handle
*				-1, if failure
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2003-12-22
*********************************************************************/
DOCPARSER_API DP_HANDLE DP_Parse(const char *sDocFilename);

/*********************************************************************
*
*  Func Name  : DP_GetText
*
*  Description: 获取文档的文本正文
*
*
*  Parameters : DP_HANDLE: 文档分析结果的handle
*
*
*  Returns    : const char *: 文本内容 纯文本内容
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2019-12-10
*********************************************************************/
DOCPARSER_API const char * DP_GetText(DP_HANDLE handle);

/*********************************************************************
*
*  Func Name  : DP_GetTextE
*
*  Description: 获取文档的文本正文
*
*
*  Parameters : DP_HANDLE: 文档分析结果的handle
*
*
*  Returns    : const char *: 文本内容，带格式的JSON串
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2019-12-10
*********************************************************************/
DOCPARSER_API const char * DP_GetTextE(DP_HANDLE handle);

/*********************************************************************
*
*  Func Name  : DP_GetTables
*
*  Description: 获取文档的表格详细信息
*
*
*  Parameters : DP_HANDLE: 文档分析结果的handle
*
*
*  Returns    : JSON格式的表格内容字符串
*	
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2019-12-10
*********************************************************************/
DOCPARSER_API const char * DP_GetTables(DP_HANDLE handle);

/*********************************************************************
*
*  Func Name  : DP_GetFigures
*
*  Description: 获取文档的图片详细信息
*
*
*  Parameters : DP_HANDLE: 文档分析结果的handle
*
*
*  Returns    : JSON格式的图片内容字符串
*
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2019-12-10
*********************************************************************/
DOCPARSER_API const char * DP_GetFigures(DP_HANDLE handle);

/*********************************************************************
*
*  Func Name  : DP_ReleaseHandle
*
*  Description: 释放分析结果
*
*
*  Parameters : DP_HANDLE: 文档分析结果的handle
*
*
*  Returns    : void
*
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2019-12-10
*********************************************************************/
DOCPARSER_API void DP_ReleaseHandle(DP_HANDLE handle);

/*********************************************************************
*
*  Func Name  : DP_GetLastErrorMsg
*
*  Description: GetLastErrorMessage
*
*
*  Parameters : void
*
*
*  Returns    : the result buffer pointer
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2014-2-27
*********************************************************************/
DOCPARSER_API const char * DP_GetLastErrorMsg();

#endif
