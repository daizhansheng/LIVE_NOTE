#include <stdio.h>

int main(int argc, const char *argv[])
{
	int year,month,day,hour,min,sec;
	year  = 2020;
	month = 3;
	day   = 2;
	hour  = 23;
	min   = 59;
	sec   = 55;

	while(1){
		sleep(1); //sleep（1）延时一秒钟
		sec ++;
		//请写出你的代码
		if(sec >= 60){
			sec = 0;
			min++;
			if(min >= 60){
				min = 0;
				hour++;
				if(hour >= 24){
					hour = 0;
					day++;
					
					if(month == 1 || month == 3 || month == 5 ||
					   month == 7 || month == 8 || month == 10 ||
					   month == 12){
						if(day >= 32){
							day = 1;
							month++;
						}			
					}else if(month == 4 || month == 6 || month == 9 ||
					   month == 11){
						if(day >= 31){
							day = 1;
							month ++;
						}
					}else{
						if((year%4 == 0 && year%100 !=0)||
							year%400 == 0){
							if(day >= 30){
								day = 1;
								month ++;
							}
						}else{
							if(day >= 29){
								day = 1;
								month++;
							}
						}	
					}
					if(month >= 13){
						month = 1;
						year++;
					}		

				}	
			
			}

		}
		
		printf("%4d-%02d-%02d %02d:%02d:%02d\r",year,month,day
				,hour,min,sec);
		fflush(stdout);//刷新标准输出的缓冲区

	}

	return 0;
}
