#pragma once

#ifdef TESSERACTFRAMEWORK_EXPORTS
#define TESSERACTFRAMEWORK_API __declspec(dllexport)
#else
#define TESSERACTFRAMEWORK_API __declspec(dllimport)
#endif