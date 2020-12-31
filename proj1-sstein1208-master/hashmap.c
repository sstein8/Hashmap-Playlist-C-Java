#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "hashmap.h"

struct HashMap* hm_create(char policy)  
{
  struct HashMap *hm = malloc(sizeof(struct HashMap)*1);
  hm->policy = policy;
  hm->numBuckets = NUM_BUCKETS;
  hm->buckets = malloc(sizeof(struct LList*)*(hm->numBuckets));
  for(int i = 0; i < hm->numBuckets; i++)
  {
    hm->buckets[i] = malloc(sizeof(struct LList));
    hm->buckets[i]->head = NULL;
  }
  return hm;
}

void printHashMap(struct HashMap *hm) 
{
  if(hm != NULL)
  {
    for(int i = 0; i < hm->numBuckets; i++)
    {
      struct LNode *tmp = hm->buckets[i]->head;
      while(tmp != NULL)
      {
        printf("Title: %s  Artist: %s  Duration: %d\n", tmp->title, tmp->artist,tmp->duration);
        tmp = tmp->next;

      }
    }
  }

}

struct LNode* hm_get(struct HashMap* hm, char* title, char* artist, int duration) {
  //retreive a node based off of the hash policy defined for the specific HashMap Struct
  //only retrun a node if all properties match
  //struct LNode *retSong = NULL;
  if(hm->policy == 'A')
  {
    int slot = hash_alphabetical(hm, title);
    struct LNode *ptr = hm->buckets[slot]->head;
    //struct LNode *ptr = bucketi;
    if(ptr == NULL)
    {
      return NULL;
    }
    else
    { //the list is not empty
        while (ptr != NULL)
        {
          if(compareEverything(title, ptr->title, artist, ptr->artist,  duration, ptr->duration)) //is true
          {
            return ptr;
          }
          ptr = ptr->next;
        }
    }
    return NULL;
  }
  else if(hm->policy == 'D')
  {
    int slot = hash_duration(hm, duration);
    struct LNode *ptr = hm->buckets[slot]->head;
    //struct LNode *ptr = bucketi;
    if(ptr == NULL)
    {
      return NULL;
    }
    else
    { //the list is not empty
        while (ptr != NULL)
        {
          if(compareEverything(title, ptr->title, artist, ptr->artist,  duration, ptr->duration)) //is true
          {
            return ptr;
          }
          ptr = ptr->next;
        }
    }
  }
  return NULL;
  
}

int hm_put(struct HashMap* hm, char* title, char* artist, int duration) {
  //printf("adding node");
  //adds song to HashMap
  //returns 0 for success, -1 otherwise
  if(hm->policy == 'A')
  {
    int slot = hash_alphabetical(hm, title);
    //printf("slot: %d  title: %s\n", slot, title);
    //slot = 3;
    addToListSongName(title, artist, duration, hm->buckets[slot]);
    //addToListSongName(hm->buckets[slot], title, artist, duration);
 
  }
  else if(hm->policy == 'D')
  {
    int slot = hash_duration(hm, duration);
    addToListDuration(title, artist, duration, hm->buckets[slot]);
    //addToListDuration(title, artist, duration, hm->buckets[slot]);
  }
  return 0;
}

int hm_remove(struct HashMap* hm, char* title, char* artist, int duration) 
{
  if(hm->policy == 'A')
  {
    int slot = hash_alphabetical(hm, title);
    //slot = 3;
    struct LNode *bucketi = hm->buckets[slot]->head;
    if (bucketi == NULL)
    {
      return 1;
    }
    else //the list is not empty
    {
      struct LNode *ptr = bucketi;
      struct LNode *prev = bucketi;
    
      //more than 1 song in list
      while(1)
      {
        //printf("while loop %s\n",title);
        if(compareEverything(title, ptr->title, artist, ptr->artist, duration, ptr->duration))
        {
          //printf("inside while %s\n", ptr->title);
          if(ptr == bucketi)
          {
            hm->buckets[slot]->head = ptr->next;
          }
          else
          {
            prev->next = ptr->next;
          }
          return 0;
          
        }
        if (ptr->next == NULL)
        {
          break;
        }
        else
        {
          prev = ptr;
          ptr = ptr->next;
        }

      }
    }
    return -1;
  }
    
  else if(hm->policy == 'D')
  {
    //printf("indide remove\n");
    int slot = hash_duration(hm, duration);
    //slot = 3;
    struct LNode *bucketi = hm->buckets[slot]->head;
    if (bucketi == NULL)
    {
      return 1;
    }
    else //the list is not empty
    {
      struct LNode *ptr = bucketi;
      struct LNode *prev = bucketi;
    
      //more than 1 song in list
      while(1)
      {
        //printf("while loop %s\n",title);
        if(compareEverything(title, ptr->title, artist, ptr->artist, duration, ptr->duration))
        {
          //printf("inside while %s\n", ptr->title);
          if(ptr == bucketi)
          {
            hm->buckets[slot]->head = ptr->next;
          }
          else
          {
            prev->next = ptr->next;
          }
          return 0;
          
        }
        if (ptr->next == NULL)
        {
          break;
        }
        else
        {
          prev = ptr;
          ptr = ptr->next;
        }

      }
    }
  }
  return -1;
  
}


void hm_destroy(struct HashMap* hm) 
{
  //free each individual linked list
  if(hm != NULL)
  {
    for(int i = 0; i < hm->numBuckets; i++)
    {
      struct LNode *tmp = hm->buckets[i]->head;
      while(tmp != NULL)
      {
        free(tmp);
        tmp = tmp->next;
      }
    }
  }
  //free the array of double-pointers
  free(hm->buckets);
  hm->buckets = NULL;
}

int hash_alphabetical(struct HashMap* hm, char* title)
{
  int sum = 0; 
  if((title != NULL)&&(hm != NULL))
  {
    int titleLength = strlen(title);
    for(int i = 0; i < titleLength; i++)
    {
      sum += (int)title[i];
    }

  }
  int hashA = sum % hm->numBuckets;
  return hashA;
  //This is the bucket in which the song is added to
}

int hash_duration(struct HashMap *hm, int duration) 
{
  int hashD = duration % hm->numBuckets;
  return hashD;
}

//additional methods

struct LNode* makeNode(char* title, char* artist, int duration)
{
  //we need to create the node(song entry)
  struct LNode *song;
  song = (struct LNode*)malloc(sizeof(struct LNode)*1);
  song->title = title;
  song->artist = artist;
  song->duration = duration;
  song->next = NULL;
  return song;
}

struct LList* makeList() 
{ 
  struct LList* L; 
  L = (struct LList*) malloc (sizeof(struct LList)); 
  L->head = NULL;  
  return L; 
} 


bool compareDurations(int d1, int d2)
{
  if (d1 <= d2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool compareEverything(char *a1, char *a2, char *s1, char *s2, int d1, int d2)
{
  if ((a1 == a2) && (s1 == s2) && (d1 == d2))
  {
    return true;
  }
  else
  {
    return false;
  }
  
}


void addToListSongName (char* title, char* artist, int duration, struct LList *list)
{
 
  if (list->head == NULL) 
  {
    list->head = makeNode(title, artist, duration);
  }
  else 
  {
    struct LNode *ptr = list->head;
    struct LNode *prev = list->head;
    
   //more than 1 song in list
    struct LNode *tmp = makeNode(title, artist, duration);
    
    while(1)
    {
    
      if(strcmp(title, ptr->title)<=0)
      //if(compareStrings(ptr->title, title))
      {
        tmp->next = ptr;
        if(ptr == list->head)
        {
          list->head = tmp;
        }
        else
        {
           prev->next = tmp;
        }
        break;
      }
      if (ptr->next == NULL)
      {
        ptr->next = tmp;
        tmp->next = NULL;
        break;
      }
      else
      {
        prev = ptr;
        ptr = ptr->next;
      }
    }
    
  }
}

void addToListDuration(char* title, char* artist, int duration, struct LList *list)
{
  if (list->head == NULL) 
  {
    list->head = makeNode(title, artist, duration);
  }
  else 
  {
    struct LNode *ptr = list->head;
    struct LNode *prev = list->head;
    
   //more than 1 song in list
    struct LNode *tmp = makeNode(title, artist, duration);
    while(1)
    {
      if(compareDurations(duration, ptr->duration))
      {
        tmp->next = ptr;
        if(ptr == list->head)
        {
          list->head = tmp;
        }
        else
        {
           prev->next = tmp;
        }
        break;
      }
      if (ptr->next == NULL)
      {
        ptr->next = tmp;
        tmp->next = NULL;
        break;
      }
      else
      {
        prev = ptr;
        ptr = ptr->next;
      }
    }
    
  }
  
}


