#include "Util/StringUtil.h"
//#include <windows.h>
#include <codecvt>

LEARN_OPENGL_BEGIN
//std::wstring FStringUtil::s2ws(const std::string& str)
//{
//	int bufLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
//	wchar_t* wstrbuf = new wchar_t[bufLen];
//	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wstrbuf, bufLen);
//	std::wstring temp(wstrbuf);
//	delete[] wstrbuf;
//	return temp;
//}
//
//std::string FStringUtil::ws2s(const std::wstring& wstr)
//{
//	int bufLen = ::WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
//	char* strbuf = new char[bufLen];
//	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, strbuf, bufLen, NULL, NULL);
//	std::string temp(strbuf);
//	delete[] strbuf;
//	return temp;
//}
std::wstring FStringUtil::s2ws(const std::string& str)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.from_bytes(str);
}

std::string FStringUtil::ws2s(const std::wstring& wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}
LEARN_OPENGL_END