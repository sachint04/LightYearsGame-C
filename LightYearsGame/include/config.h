#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG // release build
	return "assets/";
#else // debug build
	return "D:/c++/LightYears/LightYearsGame/assets/";
#endif // 

}
