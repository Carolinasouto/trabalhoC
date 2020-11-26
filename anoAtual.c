#include <time.h>

int anoAtual(){
	int anoAtual;
    time_t data_ano;
    time(&data_ano);
  
    struct tm *data = localtime(&data_ano);

    anoAtual = (data->tm_year+1900);    
    
    return anoAtual;
}

