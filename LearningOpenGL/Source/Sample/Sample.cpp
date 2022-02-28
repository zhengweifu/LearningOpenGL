#include "Sample/Sample.h"

#include "Util/Util.h"

LEARN_OPENGL_BEGIN

FSample::FSample(int Width, int Height, const char* Title)
	: m_Width(Width)
	, m_Height(Height)
	, m_Title(Title)
{
	WCHAR AssetsPath[512];
	GetAssetsPath(AssetsPath, _countof(AssetsPath));
	m_AssetsPath = AssetsPath;
}


FSample::~FSample()
{
}

LEARN_OPENGL_END