#pragma once 
#include <string>
#include "Env.h"
LEARN_OPENGL_BEGIN
class FStringUtil
{
public:
	static std::wstring s2ws(const std::string& str);
	static std::string ws2s(const std::wstring& wstr);
private:
	FStringUtil() = default;
};
LEARN_OPENGL_END