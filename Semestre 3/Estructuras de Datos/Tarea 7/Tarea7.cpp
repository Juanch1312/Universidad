#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <functional>
#include <ctime>
#include "list.h"


int main() {
	default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distribution(0, 1000000);
	auto dice = bind(distribution, generator);
	float TimeBubble,TimeInsert,TimeSelect,TimeShell,TimeMerge,TimeQuick;
	float timeInitial,timeFinish;
	List <int>ListBubble;
	List <int>ListInsert;
	List <int>ListSelect;
	List <int>ListShell;
	List <int>ListMerge;


	printf("\t%c",201);
	for(int i=0;i<30;i++){
		printf("%c",205);
	}
	printf("%c\n",187);
	printf("\t%c\tSorting Methods\t       %c\n",186,186);
	printf("\t%c",200);
	for(int i=0;i<30;i++){
		printf("%c",205);
	}
	printf("%c\n",188);
	for (int i = -1; i < 99999; i++) {
		ListBubble.insertData(i,dice());
		ListInsert.insertData(i,dice());
		ListSelect.insertData(i,dice());
		ListShell.insertData(i,dice());
		ListMerge.insertData(i,dice());
	}
	timeInitial = clock();
	ListBubble.sortDataBubble();
	timeFinish = clock();
	TimeBubble= (float)(timeFinish - timeInitial) / CLOCKS_PER_SEC;
	cout<<"Bubble Finish"<<endl;

	timeInitial=0;
	timeFinish=0;
	timeInitial = clock();
	ListInsert.sortDataInsert();
	timeFinish = clock();
	TimeInsert= (float)(timeFinish - timeInitial) / CLOCKS_PER_SEC;
	cout<<"Insert Finish"<<endl;

	timeInitial=0;
	timeFinish=0;
	timeInitial = clock();
	ListSelect.sortDataSelect();
	timeFinish = clock();
	TimeSelect= (float)(timeFinish - timeInitial) / CLOCKS_PER_SEC;
	cout<<"Select Finish"<<endl;

	timeInitial=0;
	timeFinish=0;
	timeInitial = clock();
	ListShell.sortDataShell();
	timeFinish = clock();
	TimeShell= (float)(timeFinish - timeInitial) / CLOCKS_PER_SEC;
	cout<<"Shell Finish"<<endl;

	timeInitial=0;
	timeFinish=0;
	timeInitial = clock();
	ListMerge.sortDataMerge();
	timeFinish = clock();
	TimeMerge= (float)(timeFinish - timeInitial) / CLOCKS_PER_SEC;
	cout<<"Merge Finish"<<endl;

	ListBubble.deleteAll();
	for (int i = -1; i < 99999; i++) {
		ListBubble.insertData(i,dice());
	}
	timeInitial=0;
	timeFinish=0;
	timeInitial = clock();
	ListBubble.sortDataQuick();
	timeFinish = clock();
	TimeQuick= (float)(timeFinish - timeInitial) / CLOCKS_PER_SEC;
	cout<<"Quick Finish"<<endl<<endl;


	cout<<"Times:"<<endl<<endl;
	cout<<"Bubble: "<<TimeBubble<<" Seconds"<<endl;
	cout<<"Insert: "<<TimeInsert<<" Seconds"<<endl;
	cout<<"Select: "<<TimeSelect<<" Seconds"<<endl;
	cout<<"Shell: "<<TimeShell<<" Seconds"<<endl;
	cout<<"Merge: "<<TimeMerge<<" Seconds"<<endl;
	cout<<"Quick: "<<TimeQuick<<" Seconds"<<endl;






	return 0;
}
