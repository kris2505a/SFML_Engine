#pragma once

#ifdef ENGINE
	#define PH_ENG_API __declspec(dllexport)
#elif PROJECT
	#define PH_ENG_API __declspec(dllimport)
#endif

#define PI 3.141593