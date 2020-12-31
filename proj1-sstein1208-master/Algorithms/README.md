## Phase 1: Algorithms

Before writing your code you must prepare pseudocode algorithms for each of the different functions. You must submit these in this README.md by the deadline. You are encouraged to submit much sooner so that you can make progress on your coding -- if you submit sooner, you will get feedback sooner! Keep in mind that your algorithms should be language agnostic since you will be using this for both C and Java.

`struct hashmap* hm_create(char policy)` (C only)

- Create the HashMap and allocate space for the linked lists contained within. The insertion policy will be determined by the policy character
    - `A` denotes alphabetical song title
    - `D` denotes song duration
    
```
struct hashmap* hm_create(char policy)
{
	//Create the HashMap and allocate space for the linked lists contained within. The insertion policy will be determined by the policy character

	Create a pointer to a struct HashMap called *hashmap
	Allocate space using malloc so that *hashmap is the size of a struct HashMap;

	hashmap->policy = policy;

	//allocate array of numBuckets entries with each element being a pointer to struct LList 

	Using a for loop(i = 0; i < numBuckets; i++)
		buckets[i] = makeList();

	Return hashmap;
}
```

`int hm_put(…)`

- Add a song to the HashMap.
- Return `0` on success, `-1` otherwise.

```
int hm_put(Struct HashMap *hashmap, char* artistName, char* songName, int duration)
{
	//adds song to HashMap
	//returns 0 for success, -1 otherwise

	if the hashmap->policy == A
		create an int var called slot = hashA(songName);
		//check if bucket is empty or not
		
		addToListSongName(artistName, songName, duration, bucket[slot])
		return 0;

	elseif hashmap->policy == D
		create an int var called slot = hashD(duration);
		//check if bucket is empty or not
		
		addToListDuration(artistName, songName, duration, bucket[slot]);
		return 0;

	return -1; //if not successful
}
```

`int hash_alphabetical(…)`

- The alphabetical hash will take the given song title and return an int specifying which bucket to add to. This can be done by taking the sum of the ASCII codes of all the characters, then modulo by the number of buckets, and return the result.

```
int hash_alphabetical(char *songName, int numBuckets)
{
	Declare char array;
	Store the songName in the char array;
	create an int variable to hold the length of the song title;

	Beginning with int sum = 0 and int i = 0, create a while loop that loops through the songName until one of the chars = '\0' and computes the sum += (int) array[i];
	//This adds up each ascii value in the string

	int hashA = sum % numBuckets;
	return hashA;
	//This is the bucket in which the song is added to
	
}
```

`int hash_duration(…)`

- The duration hash will take the given song duration and return an int specifying which bucket to add to. This can be done by taking the duration modulo by the number of buckets, and return the result.

```
int hash_duration(int duration, int numBuckets)
{

	Declare an int hashD that holds duration % numBuckets;
	Return hashD;

}
```

`struct LNode* hm_get(…) / LNode hm_get(…)`

- hm_get should retrieve a node using the hash policy defined for the specific HashMap struct. Only return a node if ALL properties match (i.e. title, artist AND duration).
- Returns the node if found, `NULL` otherwise

```
struct LNode* hm_get(Struct HashMap *hashmap, char* artistName, char* songName, int duration) / LNode hm_get(Struct HashMap *hashmap, char* artistName, char* songName, int duration)
{
	//retreive a node based off of the hash policy defined for the specific HashMap Struct
	//only retrun a node if all properties match
	//return the node if founf, NULL otherwise

	if the hashmap->policy == A
		create an int var called slot = hashA(songName);
		if head of list @ buckets[slot] == null
			return null

		else //the list is not empty
				Create a Struct LNode pointer called ptr and have it point to the head of the list;
				Create another Struct LNode pointer called prev and have it also point to the head of the list;

				While ptr next is not null 
					if compareEverything(artistName, ptr->artistName, songName, ptr->songName, duration, ptr->duration) is true
						return song node; 

					else
						return NULL; //None of the songs in the list had all of the matching attributes
						

	elseif hashmap->policy == D
		create an int var called slot = hashD(duration);
		if head of list @ buckets[slot] == null
			return null

		else //the list is not empty
				Create a Struct LNode pointer called ptr and have it point to the head of the list;
				Create another Struct LNode pointer called prev and have it also point to the head of the list;

				While ptr next is not null 
					if compareEverything(artistName, ptr->artistName, songName, ptr->songName, duration, ptr->duration) is true
						return song node; 

					else
						return NULL; //None of the songs in the list had all of the matching attributes
	
}
```

`int hm_remove(…)`

- Remove a song from the HashMap that has the given title, artist, and duration.
- Return `0` on success, `1` if not found, `-1` otherwise.

```
int hm_remove(Struct HashMap *hashmap, char* artistName, char* songName, int duration)
{
	//Remove a song from the HashMap that has the given title, artist, and duration.
	//Return 0 on success, 1 if not found, -1 otherwise

	if the hashmap->policy == A
		create an int var called slot = hashA(songName);
		if head of list @ buckets[slot] == null
			return null

		else //the list is not empty
				Create a Struct LNode pointer called ptr and have it point to the head of the list;
				Create another Struct LNode pointer called prev and have it also point to the head of the list;

				While ptr next is not null 
					if compareEverything(artistName, ptr->artistName, songName, ptr->songName, duration, ptr->duration) is true
						take the next pointer and store it as the next pointer to the previous pointer;
						//this takes the curret song node out of the list
						return 0;

					else
						return 1; //song was not found
						

	elseif hashmap->policy == D
		create an int var called slot = hashD(duration);
		if head of list @ buckets[slot] == null
			return null

		else //the list is not empty
				Create a Struct LNode pointer called ptr and have it point to the head of the list;
				Create another Struct LNode pointer called prev and have it also point to the head of the list;

				While ptr next is not null 
					if compareEverything(artistName, ptr->artistName, songName, ptr->songName, duration, ptr->duration) is true
						take the next pointer and store it as the next pointer to the previous pointer;
						//this takes the curret song node out of the list
						return 0
					else
						return 1; //None of the songs in the list had all of the matching attributes

	return -1;
	
}

```

`void hm_destroy(struct hashmap* hm)` (C only)

- Deallocate (free) the HashMap that is passed in and **all of its elements**.

```
void hm_destroy(struct hashmap* hm)
{
	for loop to move through each bucket
		while the bucket is not null
			//step through the linked list L that the bucket points to and delete each node
			while the next song is not null
				free the song
				move the song pointer over by one;
		
		free the whole bucket;
		free the whole hashmap;
}
```




Extra Methods
---------------
```
struct LNode *makeNode(char* artistName, char* songName, int duration)
{
	//we need to create the node(song entry)
	Create a node called song of type LNode;
		//struct LNode *song;
	Allocate space for that song node so that it is the size of a struct LNode;
	Set the artistName of song;
  	Set the songName of song;
  	Set the duration of song;
  	Set the next pointer to NULL;

  	return song;
	
}
```

```
struct LList* makeList () 
{ 
	Create a Struct LList pointer called L; 
  	Allocate L enough space so that it is the size of a struct LList;
  	Set the head of list L to NULL;
  	return L;
} 
```

```
int comapreStrings(char *s1, char *s2)
{
	if s1 comes earlier or equal to s2's place in the alphabet,
		return true;
	else
		return false;
}
```

```
int comapreDurations(int d1, int d2)
{
	if d1 is less than or equal to d2,
		return true;
	else
		return false;
}
```

```
void addToListSongName (char* artistName, char* songName, int duration, struct LList *list) 
{
	If the head of the list == null
		create a new song node and set it as the head;
		set the node next to it as null;

	else //the list is not empty
		Create a Struct LNode pointer called ptr and have it point to the head of the list;
		Create another Struct LNode pointer called prev and have it also point to the head of the list;

		While ptr next is not null //insert a song alphabetically into the list
			if compareStrings function(songName, ptr->songName) is true //songName is less than the value of the songName in the list
				//insert it before the next song that comes alphabetically after it
				Store the next node from the current into a Struct LNode pointer called tmp;
				makeNode and store it in prev->next node;
				Prev->next->next = value stored in tmp;


	
}
```

```
void addToListDuration (char* artistName, char* songName, int duration, struct LList *list) 
{
	If the head of the list == null
		create a new song node and set it as the head;
		set the node next to it as null;

	else //the list is not empty
		Create a Struct LNode pointer called ptr and have it point to the head of the list;
		Create another Struct LNode pointer called prev and have it also point to the head of the list;

		While ptr next is not null //insert a song based off of its duration compared to the duration of the other songs
			if compareDuration function(duration, ptr->duration) is true 
				//insert it before the next song that has a duration greater than it
				Store the next node from the current into a Struct LNode pointer called tmp;
				makeNode and store it in prev->next node;
				Prev->next->next = value stored in tmp;
}
```

```
int comapreEverything(char *a1, char *a2, char *s1, char *s2, int d1, int d2)
{
	if (a1 == a2 AND s1 == s2 AND d1 == d2)
		return true;
	else
		return false;
}
```



