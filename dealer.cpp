#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  int opt;
  int number_of_trials=atoi(argv[argc-1]);
  int percentage;
  bool pflag = false;
  bool verbose = false;
  opt = getopt(argc, argv, "p:v");
  while (opt !=-1){
    switch (opt){
    case 'p':
      pflag = true;
      percentage = atoi(optarg);
      break;
    case 'v':
      verbose = true;
      break;
    default: /* '?' */
      exit(EXIT_FAILURE);
    }
    opt = getopt(argc, argv, "p:v");
  }
  if (pflag == false || number_of_trials<=0){
    cout << "Must include -p option" << endl << "Must include number of trials last" << endl;
    exit(EXIT_FAILURE);
  }

  cout << percentage << endl << number_of_trials << endl;
  if (verbose == true)
    cout << "v" << endl;
}
