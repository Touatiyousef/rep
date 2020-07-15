struct cpu
{
    char user[50];
    char nice[50];
    char system[50];
    char idle[50];
    char iowait[50];
    char irq[50];
    char softirq[50];
    char steal_time[50];
    char guest_system[50];
};

typedef struct cpu cpu;
extern void collecte_donnees (cpu* cpu);

typedef struct mem mem ;

struct mem {
	unsigned long MemTotal ;
	unsigned long MemFree;
	unsigned long MemAvailable;
	unsigned long Buffers;
	unsigned long Cached;
		} ;
extern void collecte (mem* Mem);



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



