#ifndef LL_H
#define LL_H
/* The code above prevents this library from being included more than once */

// For testing, you can change this constant
// BE SURE TO CHANGE IT BACK BEFORE SUBMITTING
#define NUM_BUCKETS 5

struct HashMap
{
  struct LList **buckets;
  int numBuckets;
  char policy;
};

struct LList
{
  struct LNode *head;
};

struct LNode {
  char* title;
  char* artist;
  int duration;
  struct LNode* next;
};

struct HashMap* hm_create(char policy);

void printHashMap(struct HashMap *hm);

struct LNode* hm_get(struct HashMap* hm, char* title, char* artist, int duration);

int hm_put(struct HashMap* hm, char* title, char* artist, int duration);

int hm_remove(struct HashMap* hm, char* title, char* artist, int duration);

void hm_destroy(struct HashMap* hm);

int hash_alphabetical(struct HashMap* hm, char* title);

int hash_duration(struct HashMap* hm, int duration);

#endif
