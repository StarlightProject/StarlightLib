#ifndef _TOOLS_H_
#define _TOOLS_H_

/*If you want to disable log file, you can change this value to 0*/
#define ST_LOG_FILE_ENABLE		1
/*If you want to disable log console, you can change this value to 0*/
#define ST_LOG_CONSOLE_ENABLE	1

#define ST_LOG_TYPE_INFO			0
#define ST_LOG_TYPE_WARN			1
#define ST_LOG_TYPE_ERROR		2
#define ST_LOG_TYPE_FAILED		3
#define ST_LOG_TYPE_OTHER		4

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

static std::ofstream write;

void StInitLog();
void StDestoryLog();
void StRecordLog(unsigned int type, std::string message);

#endif