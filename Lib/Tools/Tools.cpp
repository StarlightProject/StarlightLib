#include "Tools.h"

void StInitLog() {
	write.open("StLog.txt", std::ios::out | std::ios::app | std::ios::binary);
}

void StDestoryLog() {
	write.close();
}

void StRecordLog(unsigned int type,std::string message) {
	struct tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	if (ST_LOG_CONSOLE_ENABLE) {
		if(!ST_LOG_TYPE_OTHER)
			std::cerr << '[' << t.tm_hour << ':' << t.tm_min << ':' << t.tm_sec << ']';
		switch (type) {
		case ST_LOG_TYPE_INFO:
			std::cerr << "INFO:";
			break;
		case ST_LOG_TYPE_WARN:
			std::cerr << "WARN:";
			break;
		case ST_LOG_TYPE_ERROR:
			std::cerr << "ERROR:";
			break;
		case ST_LOG_TYPE_FAILED:
			std::cerr << "FAILED:";
			break;
		case ST_LOG_TYPE_OTHER:
			break;
		}
		std::cerr << message << "\n";
	}
	if (ST_LOG_FILE_ENABLE) {
		if (!ST_LOG_TYPE_OTHER)
			write << '[' << t.tm_hour << ':' << t.tm_min << ':' << t.tm_sec << ']';
		switch (type) {
		case ST_LOG_TYPE_INFO:
			write << "INFO:";
			break;
		case ST_LOG_TYPE_WARN:
			write << "WARN:";
			break;
		case ST_LOG_TYPE_ERROR:
			write << "ERROR:";
			break;
		case ST_LOG_TYPE_FAILED:
			write << "FAILED:";
			break;
		case ST_LOG_TYPE_OTHER:
			break;
		}
		write << message << "\n";
	}
}