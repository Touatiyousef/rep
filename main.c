#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modules.h"
#include <dirent.h>
#include <errno.h>

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>

#include <arpa/inet.h>
int main()
{ 
while(1)
{
 
	




printf("\n\n\n\n**********Total Cpu*****************\n\n\n\n\n");

cpu Cpu ; 
collecte_donnees_cpu(&Cpu);




printf("\n\n\n\n**********Total Memory*****************\n\n\n\n\n");

mem Mem ;
collecte_donnees_ram(&Mem) ; 



 DIR *dir;
 int *pids = malloc(sizeof(int) * 10);
 char buffer[100];
 int PIDN;
 struct dirent *ent;
 const char l[]="0123456789";

 const char cmd[] = "ps -eo pid --sort=-%cpu --no-header | head";
 unsigned long int stime_anc=0,utime_anc=0;

 FILE *fp = popen(cmd, "r");
 if (fp != NULL)
    {
    if ((dir = opendir("/proc")) == NULL)
        perror("operation error");
    else 
    {


        for (int i = 0; fgets(buffer, sizeof buffer, fp); i++)
            
		{sscanf(buffer, "%d", &pids[i]);
	  
	PIDN= pids[i];




		statStuff s ;
		readStat(PIDN ,&s);
		printf("\n\n\n\n**********DATA  per process*****************  PID = %d\n\n\n\n\n", s.pid);			
		printf("\n\n\n\n	         **Cpu of the current process, PID =   %d\n\n\n\n\n", s.pid);			

		printf("pid = %d\n", s.pid); 
		printf("comm = %s\n", s.comm); 
		printf("state = %c\n", s.state); 
		printf("utime = %lu\n", s.utime); 
		printf("stime = %lu\n", s.stime); 
		
		   


statmStuff stuff ;
readStatm(PIDN, &stuff);
printf("\n\n\n\n                    ** memory of the current process, PID  = %d\n\n\n\n\n", s.pid);
printf("pid = %d\n", s.pid); 
printf("size = %lu\n", stuff.size); 
printf("resident = %lu\n", stuff.resident); 
printf("share = %lu\n", stuff.share); 
printf("text = %lu\n", stuff.text); 
printf("lib = %lu\n", stuff.lib); 
printf("data = %lu\n", stuff.data); 
printf("dt = %lu\n", stuff.dt); 


            }
      
        closedir(dir);
 }
  pclose(fp);


 }
sleep(5);
}

return 0;

}
