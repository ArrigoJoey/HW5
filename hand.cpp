#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  int percentage;
  int opt = getopt(argc, argv, "p:v");
  while(opt != -1){
    if (opt == 'p'){
      percentage = atoi(optarg);
    }
    opt = getopt(argc, argv, "p:v");
  }
  cout << "p is " << percentage << endl;
}
