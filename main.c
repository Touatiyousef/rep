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
int total_cpu_anc=0;
int total_cpu_diff=0;
cpu cpu;

int total_cpu;
while(1)
{
collecte_donnees(&cpu);	




printf("\n\n\n\n**********Total Cpu*****************\n\n\n\n\n");


printf("cpu_user = %s\n", cpu.user );
printf("cpu_nice = %s\n", cpu.nice );
printf("cpu_system = %s\n", cpu.system );
printf("cpu_idle = %s\n", cpu.idle);
printf("cpu_iowait = %s\n", cpu.iowait);
printf("cpu_irq = %s\n", cpu.irq);
printf("cpu_softirq = %s\n", cpu.softirq);
printf("cpu_steal_time = %s \n",cpu.steal_time);
printf("cpu_guest_system = %s\n",cpu.guest_system) ; 



total_cpu = atoi(cpu.user)+atoi (cpu.system )+atoi(cpu.idle)+atoi (cpu.iowait )+atoi(cpu.irq)+atoi (cpu.softirq )+atoi(cpu.steal_time)+atoi (cpu.guest_system );
printf("cpu_total from the last snapshot = %d \n", total_cpu);

sleep(5) ;

total_cpu_diff = total_cpu - total_cpu_anc ;
printf("cpu_total diff=  %d \n", total_cpu_diff);

total_cpu_anc=total_cpu;



printf("\n\n\n\n**********Total Memory*****************\n\n\n\n\n");

mem mem;
collecte(&mem) ; 
	
	printf("mem_total = %lu\n", mem.MemTotal );
	printf("mem_available = %lu\n", mem.MemFree);
	printf("mem_free = %lu\n", mem.MemAvailable);
	printf("buffers = %lu\n", mem.Buffers);
	printf("cached = %lu\n", mem.Cached);









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
