#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//Function called when you invoke ./chain -h
void help()
{
   fprintf(stderr, "Help Menu:\n\n");
   fprintf(stderr, "Usage:\n");
   fprintf(stderr, "chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile\n\n");
   fprintf(stderr, "nprocs - Number of processes [default 4]\n");
   fprintf(stderr, "nchars - Number of characters read into the buffer [default 80]\n");
   fprintf(stderr, "sleeptime - Time to sleep in each iteration [default 3s]\n");
   fprintf(stderr, "niters - Numbner of iterations in the loop\n");
   fprintf(stderr, "textfile - File containing text to be read through stdin\n");
   exit(0);
}

int main(int argc, char *argv[])
{
   //Defaults set for variables
   pid_t childpid = 0;
   int i, opt, nprocs = 4, nchars = 80, sleeptime = 3, niters = 1;

   //Get options set up
   while ((opt = getopt(argc, argv, "hp:c:s:i:")) != -1)
   {
      switch (opt)
      {
         case 'h':
            help();
            break;
         case 'c':
            nchars = atoi(optarg);
            break;
         case 's':
            sleeptime = atoi(optarg);
            break;
         case 'i':
            niters = atoi(optarg);
            break;
         case 'p':
            nprocs = atoi(optarg);
            break;
         default:
            fprintf(stderr, "Unknown option provided, exiting...\n");
            exit(-1);
      }
   }

   //Test statement to see if parameters were getting passed correctly
   //printf("nproc:%d nchars:%d sleeptime:%d niters:%d\n", nprocs, nchars, sleeptime, niters);

   for (i = 1; i < nprocs; i++)
   {
     if (childpid = fork())
     {
         //Test output to see 
         //fprintf(stderr, "Parent process (%d) has forked a child\n", childpid);
         //only the parent gets into this block of code
         break;
      }

      if (childpid == -1)
      {
         perror("chain: Error: Fork failed\n");
         exit(-1);
      }
   }

   //I wasn't sure where to use niters, but multiplying it by the sleeptime
   sleep(sleeptime * niters);
   wait(NULL);

   //Allocate mybuf, +1 for the '\0'
   char *mybuf = malloc(sizeof(char) * (nchars + 1));
   int singleChar;

   //Get chars 1 at a time and store in mybuf
   for (int k = 0; k < nchars; k++)
   {
      singleChar = getchar();
      mybuf[k] = (char)singleChar;
   }

   mybuf[nchars] = '\0';

   //Output statement
   fprintf(stderr, "PID:%ld  Buffer:%s\n", (long)getpid(), mybuf);

   return 0;
}