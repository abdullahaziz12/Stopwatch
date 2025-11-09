#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	int hours,minute,seconds,total;
	cout<<"\n                        StopWatch"<<endl;
	cout<<"Enter hours:";
	cin>>hours;
	cout<<"Enter Minutes:";
	cin>>minute;
	cout<<"Enter Seconds:";
	cin>>seconds;
	total=(hours*60*60)+(minute*60)+(seconds);
	system("cls");
	cout<<"\n                        StopWatch"<<endl;
	for(int i=1;i<total;i++){
		if(minute==0 && seconds==0)
		{
			hours--;
			minute=59;
			seconds=60;
		}
	    else if(seconds==0 )
		{
			minute--;
			seconds=59;
		}
		
		cout<<"\n\t\t         "<<hours<<":"<<minute<<":"<<seconds;
		Sleep(1000);
		system("cls");
		cout<<"\n                        StopWatch"<<endl;
		seconds--;
	}
	cout<<"Time Out";
	return 0;
}
