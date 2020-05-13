#include "cachelab.h"
#include <stdlib.h>

/* define cache */
typedef struct {
    int valid;
    int tag;
    int LRU_num;
}Line;
typedef struct {
    Line *line;
}Set;
typedef struct {
    int set_num;
    int line_num;
    Set *set;
}Sim_Cache;

int getOpt(int argc, char* *argv, int *s, int *E, int *b, char *tracefileName, int *isVerbose) {
    int c;
    while ((c = getopt(argc, argv, "hvs:E:b:t")) != -1) {
        switch (c){
        case 'v':
            *isVerbose = 1;
            break;
        case 's':
            *s = atoi(optarg);
            break;
        case 'E':
            *E = atoi(optarg);
            break;
        case 'b':
            *b = atoi(optarg);
            break;
        case 't':
            *t = strcpy(tracefileName, optarg);
            break;
        case 'h':
        default:
            exit(0);
        }
        return 1;
    }
}
void updateLRU(Sim_Cache *sim_cache, int setBit, int hitIndex) {
    sim_cache->set[setBit].line[hitIndex].LRU_num = MAGIC_LRU_NUM;
    for (int i = 0; i < sim_cache->line_num; i++) {
        if (i != hitIndex) sim_cache->set[setBit].line[hitIndex].LRU_num--;
    }
}
int findLRULine(Sim_Cache *sim_cache, int setBit) {
    int minIndex = 0;
    int minNum = MAGIN_LRU_NUM;
    for (int i = 0; i < sim_cache->line_num; i++) {
        int cur = sim_cache->set[setBit].line[i].LRU_num;
        if (cur < minNum) {
            minNum = cur;
            minIndex = i;
        }
    }
    return minIndex;
}
int isMiss(Sim_Cache *sim_cache, int setBit, int tagBit) {
    int isMiss = 1;
    for (int i = 0; i < sim_cache->line_num; i++) {
        Line line = sim_cache->set[setBit].line[i];
        if (line.tag == tagBit && line.valid == 1) {
            isMiss = 0;
            updateLRU(sim_cache, setBit, i);
        }
    }
    return isMiss;
}
int updateCache(Sim_Cache *sim_cache, int setBit, int tagBit) {
    int isfull = 1;
    int i;
    for (i = 0; i < sim_cache->line_num; i++) {
        if (sim_cache->set[setBit].line[i].valid == 0) {
            isfull = 0;
            break;
        }
    }
    if (!isfull) {
        sim_cache->set[setBit].line[i].tag = tagBit;
        sim_cache->set[setBit].line[i].valid = 0;
        updateLRU(sim_cache, setBit, i);
    }
    else {
        int index = findLRULine(sim_cache, setBit);
        sim_cache->set[setBit].line[i].tag = tagBit;
        sim_cache->set[setBit].line[i].valid = 0;
        updateLRU(sim_cache, setBit, i);
    }
    return isfull;
}
void loadData(Sim_Cache *sim_cache, int addr, int size, int setBit int tagBit) {
    if (isMiss(sim_cache, setBit, tagBit)) {
        misses++;
        if (updateCache(sim_cache, setBit, tagBit)) {
            eviction++;
        }
    }
    else {
        hits++;
    }
}

void storeData(Sim_Cache *sim_cache, int addr, int size, int setBit int tagBit) {
     loadData(Sim_Cache *sim_cache, int addr, int size, int setBit int tagBit);
}
void modifyData(Sim_Cache *sim_cache, int addr, int size, int setBit int tagBit) {
     loadData(Sim_Cache *sim_cache, int addr, int size, int setBit int tagBit);
     storeData(Sim_Cache *sim_cache, int addr, int size, int setBit int tagBit);
}

int getSet(int addr, int s, int b) {
    //TODO
}
int getTag(int addr, int s, int b) {
    return addr >> (s+b);
}

void init_cache(Sim_Cache *cache, int s, int E) {
    cache->set_num = 2 << s;
    cache->line_num = E;
    cache->set = (Set*)malloc(cache->set_num*sizeof(Set));
    for (int i = 0; i < cache->set_num; i++) {
        cache->set[i].line = (Line*)malloc(cache->line_num*sizeof(line));
        for (int j = 0; j < E; j++) {
            //cache->set[i].line->tag = malloc(t);
            cache->set[i].line->valid = 0;
            cache->set[i].line->LRU_num = 0;
        }
    }
    return;
}

int misses, hits, eviction;
int main(int argc, char ** argv) {
    int s, E, b, isVerbose = 0;
    char tracefileName[100], opt[10];
    int addr, size;
    misses = hits = eviction = 0;
    Sim_Cache cache;
    getOpt(argc, argv, &s, &E, &b, tracefileName, isVerbose) {
    init_cache(s, E, &cache);
    FILE *tracefile = fopen(tracefileName, "r");
    while (fscanf(tracefile, "%s %x %d", opt, &addr, &size) != EOF) }{
        if (strcmp(opt, "I") == 0) continue;
        int setBit = getSet(addr, s, b);
        int tagBit = getTag(addr, s, b);
        printf("does it work?");
        if (strcmp(opt, "S") == 0) {
            storeData(Sim_Cache *cache, int addr, int size, int setBit int tagBit);
        }
        if (strcmp(opt, "M") == 0) {
            modifyData(Sim_Cache *cache, int addr, int size, int setBit int tagBit);
        }
        if (strcmp(opt, "L") == 0) {
            loadData(Sim_Cache *cache, int addr, int size, int setBit int tagBit);
        }

    }
    printSummary(hits, misses, eviction);
    return 0;
}
{
    printSummary(0, 0, 0);
    return 0;
}
