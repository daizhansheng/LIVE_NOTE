#include <stdio.h>

int getWeekdayByYearday(int iY, int iM, int iD) 
{
	int iWeekDay = -1; 
	if (1 == iM || 2 == iM) 
	{   
		iM += 12; 
		iY--;
	}   
	iWeekDay = (iD + 1 + 2 * iM + 3 * (iM + 1) / 5 + iY + iY / 4 - iY / 100 + iY / 400) % 7;
	
	return iWeekDay;
}

int cal_leap_year(int year)
{
	if(((year%4 == 0)&&(year%100 != 0)) || (year%400 == 0)){
		return 1;	//润年	
	}
	return 0;//平年
}

int month_day(int month,int leap)
{
	if((month == 1) ||(month == 3) ||(month == 5)||(month == 7)||
		(month == 8) ||(month == 10)||(month == 12))
		return 31;

	if((month == 4) ||(month == 6) ||(month == 9)||(month == 11))
		return 30;

	if(month == 2 && leap == 1)
		return 29;
	
	if(month == 2 && leap == 0)
		return 28;

	return 0;
}

void print_month(int week,int day)
{
	int i,j;
	printf("\tSun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	for(i=0; i<week; i++){ //根据这个月的第一天是周几来
		printf("\t");      //向后跳过多个\t
	}
	
	for(i=1,j=week; i<=day;j++,i++){//打印这个月的天数，但是 
		if(j > 6){                  //每到周六后你需要换行
			j = 0;
			puts("");
		}
		printf("\t%d",i);
	}
	puts("");
	puts("");
}

void print_date(int year,int month,int leap,int mod)
{
	int week,day;
	if(mod == 1){//打印整年日历
		for(month=1; month<=12; month++){
			printf("%d-%d\n",year,month);
			week = getWeekdayByYearday(year,month,1);
			//getWeekdayByYearday这个函数是根据年，月，日计算是
			//周几的函数0-6   周日-周六
			day = month_day(month,leap);
			//计算这个月份有多少天
			print_month(week,day);		
		}
	}else{//打印当前月的日历
		printf("%d-%d\n",year,month);
		week = getWeekdayByYearday(year,month,1);
		day = month_day(month,leap);
		print_month(week,day);		
	}
}

int main(int argc, const char *argv[])
{
	int chose,leap;
	//chose代表的是打印年的日历，还是月的日历
	//leap 1闰年 0平年
	int year,month;
	//年 月
	puts("*********************Please chose*************************");
	puts("*************1.Print a year's calendar *******************");
	puts("*************2.Print a month's calendar*******************");
	puts("**********************************************************");
	printf("your chose: ");
	scanf("%d",&chose);

	if(chose == 1){ //打印一年的日历
		printf("input(year) > ");
		scanf("%d",&year); //输入年份
		if(year <= 0){
			puts("input error!");	
			return -1;
		}
		
		leap = cal_leap_year(year); //计算平年还是闰年
		print_date(year,month,leap,1);//打印函数,最后一个参数1代表打印整年

	}else if(chose == 2){//打印一个月的日历
		printf("input(eg:xxx,xx)> ");
		scanf("%d,%d",&year,&month);
		
		if((year <= 0)||((month<=0) || (month>12))){
			puts("input error!");	
			return -1;
		}

		leap = cal_leap_year(year);
		print_date(year,month,leap,0);
	}else{
		puts("input error!");	
		return -1;
	}

	return 0;
}
