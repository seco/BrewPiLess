#ifndef DataLogger_H
#define DataLogger_H

#define RETRY_TIME 5
#define MAX_RETRY_NUMBER 3


class DataLogger
{
public:
    DataLogger(void):_format(NULL),_method(NULL),_url(NULL),_contentType(NULL),_enabled(false),_period(0),_lastUpdate(0){}

    ~DataLogger() 
    {
    	if(_url) free(_url);
    	if(_method) free(_method);
    	if(_format) free(_format);
    	if(_contentType) free(_contentType);
    }

    void loadConfig(void);
    // web interface
	void updateSetting(AsyncWebServerRequest *request);
	void getSettings(AsyncWebServerRequest *request);
	
	void loop(time_t now);

protected:
	bool processJson(char* jsonstring);
	void sendData(void);
 	int dataSprintf(char *buffer,const char *format);
 	int printFloat(char* buffer,float value,int precision,bool valid);

	char* _url;
	char* _method;
	char* _format;
	char* _contentType;

	bool _enabled;
	time_t _period;
	time_t _lastUpdate;
};

#endif


























































































































































































































































































