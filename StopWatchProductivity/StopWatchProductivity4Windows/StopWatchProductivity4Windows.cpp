#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>

using namespace std;
using namespace this_thread;
using namespace chrono;

unsigned long long getSeconds ();
int pow(int n, int e);

int main () {
  unsigned long long secs = 0;
  secs = getSeconds();
  ofstream write;
  double tempHours;
  while (true) {
    secs += 1;
    write.open("TotalTimeInProduction", ios::trunc);
    tempHours = secs/3600.0;
    cout << secs << "s (" << tempHours << "h)" << endl;
    write << secs << "s (" << tempHours << "h)";
    write.close();
    sleep_for(seconds(1));
    system("cls");
  }
}

unsigned long long getSeconds () {
  int FirstPos;
  unsigned long long time = 0;
  ifstream read;
  char line [80];
  read.open("TotalTimeInProduction");
  if (read.good()) {
	  read.getline(line, 80);
	  for (int i = 0; i<80; i++) {
		if (line[i] == 's') {
		  FirstPos = i;
		}
	  }
	  int round = 0;
	  for (int p = (FirstPos-1); p>=0; p--) {
	    int character =(int) (line[p]-48);
	    time += character*pow(10, round);
		round++;
	  }
	  read.close();
	  return time;
  } else {
		read.close();
		return 0;
	}
}

int pow (int n, int e) {
  int number = 1;
  for (int i = 0; i<e; i++) {
    number *= n;
  }
  return number;
}
