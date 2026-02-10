#include<iostream>
using namespace std;

class TimeConverter {
	public:
	int s,m,h,totlesecond;
	
	void time()
	{
	      cout<<"Enter totle Second :";
	      cin>>totlesecond;
	      h = totlesecond / 3600 ;  // 1 hours = 3600 seconds:
	      m = (totlesecond % 3600)/60  ;
	      s = totlesecond % 60;
	      
	      cout<<"HH:MM:SS = "<<h<<":"<<m<<":"<<s<<endl;
	      
	}
	void sec(){
		cout<<"\nEnter the Hours :";
		cin>>h;
		cout<<"Enter the Minites :";
		cin>>m;
		cout<<"Enter the Second :";
		cin>>s;
		
		int totletime = (h * 3600)  + (m * 60) + s;
		cout<<"Totle Seconds = "<<totletime;
	}
};



int main(){
	TimeConverter ob;
	//scond convert to time
    ob.time();
    
    //time convert to second 
    ob.sec();
}

/*
Output :
Enter totle Second :3600
HH:MM:SS = 1:0:0
Enter the Hours :10
Enter the Minites :20
Enter the Second :20
Totle Seconds = 37220
*/
