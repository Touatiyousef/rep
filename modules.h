typedef struct cpu cpu ;

struct cpu {
	char cpu_user[50];
	char cpu_nice[50];
	char cpu_system[50];
	char cpu_idle[50];
	char cpu_iowait[50];
	char cpu_irq[50];
	char cpu_softirq[50];
	char cpu_steal_time[50];
	char cpu_guest_system[50];
		} ;
     extern void collecte_donnees_cpu (cpu* Cpu) ; 


typedef struct mem mem ;

struct mem {
	char mem_total [50];
	char mem_available[50];
	char mem_free[50];
	char buffers[50];
	char cached[50];
		} ;
		extern void collecte_donnees_ram (mem* Mem) ;




typedef struct statStuff statStuff ;
struct statStuff { 
    int pid;			// %d 
    char comm[256];		// %s
    char state;			// %c
    unsigned long utime;	// %lu
    unsigned long stime; 	// %lu
  
} ; 

extern  int readStat(int pid ,statStuff *s);

typedef struct statmStuff statmStuff ;

struct statmStuff { 
    unsigned long size; 
    unsigned long resident; 
    unsigned long share; 
    unsigned long text; 
    unsigned long lib; 
    unsigned long data; 
    unsigned long dt; 
} ; 

extern int readStatm(int pid,statmStuff *s);



