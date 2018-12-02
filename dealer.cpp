#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>

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

  for (int i = 0; i < number_of_trials; i++){
    pid_t pid = fork();
    int status;
    if (pid == -1){
      //failure
      cerr << "fork failed" << endl;
      exit(EXIT_FAILURE);
    }
    else if (pid == 0){
      //child
      execvp("./hand",argv);
      cerr << "exec failed" << endl;
      exit(0);
    }
    else{
      //parent
      pid = wait(&status);
    }
  }
  
}
