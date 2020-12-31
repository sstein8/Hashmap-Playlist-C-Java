public class HashMap {

    // For testing, you can change this constant
    // BE SURE TO CHANGE IT BACK TO 5 BEFORE SUBMITTING
    private final int NUM_BUCKETS = 5;
    public LList[] buckets;
    public char policy;
    /* You may not add more data members to this class. */
    

    public HashMap(char policy) {
        // Implement the constructor
        this.buckets = new LList[NUM_BUCKETS];
        this.policy = policy;
        for(int i = 0; i < NUM_BUCKETS; i++)
        {
          this.buckets[i] = new LList();
          this.buckets[i].head = null; //do we need to set equal to null?
        }
    }

    public void printHashMap() {
      LNode tmp = null;
      for(int i = 0; i < NUM_BUCKETS; i++)
      {
        tmp = this.buckets[i].head;
        while(tmp != null)
        {
          System.out.println("Title: " + tmp.title + " Artist: " + tmp.artist + " Duration: " + tmp.duration);
          tmp = tmp.next;
        }
      }

    }

    public LNode hm_get(String title, String artist, int duration) {
      if(this.policy == 'A')
      {
        int slot = hash_alphabetical(title);
        LNode ptr = this.buckets[slot].head;
        if(ptr == null)
        {
          return null;
        }
        else
        { //the list is not empty
            while (ptr != null)
            {
              if(title.equals(ptr.title) && artist.equals(ptr.artist) && duration == (ptr.duration)) //is true
              {
                return ptr;
              }
              ptr = ptr.next;
            }
        }
        return null;
      }
      else if(this.policy == 'D')
      {
        int slot = hash_duration(duration);
        LNode ptr = this.buckets[slot].head;
        //struct LNode *ptr = bucketi;
        if(ptr == null)
        {
          return null;
        }
        else
        { //the list is not empty
            while (ptr != null)
            {
              if(title.equals(ptr.title) && artist.equals(ptr.artist) && duration == (ptr.duration)) //is true
              {
                return ptr;
              }
              ptr = ptr.next;
            }
        }
      }
      return null;
      
    }

    public int hm_put(String title, String artist, int duration) {
      if(this.policy == 'A')
      {
        int slot = hash_alphabetical(title);
        addToListSongName(title, artist, duration, buckets[slot]);
      }
      else if(this.policy == 'D')
      {
        int slot = hash_duration(duration);
        addToListDuration(title, artist, duration, buckets[slot]);
      }
	    return 0;
    }

    public int hm_remove(String title, String artist, int duration) {
      if(this.policy == 'A')
      {
        int slot = hash_alphabetical(title);
        //slot = 3;
        LNode bucketi = this.buckets[slot].head;
        if (bucketi == null)
        {
          return 1;
        }
        else //the list is not empty
        {
          LNode ptr = bucketi;
          LNode prev = bucketi;
        
          //more than 1 song in list
          while(1 != 0)
          {
            if(title.equals(ptr.title) && artist.equals(ptr.artist) && duration == (ptr.duration)) //is true
            {
              if(ptr == bucketi)
              {
                this.buckets[slot].head = ptr.next;
              }
              else
              {
                prev.next = ptr.next;
              }
              return 0;
              
            }
            if (ptr.next == null)
            {
              break;
            }
            else
            {
              prev = ptr;
              ptr = ptr.next;
            }

          }
        }
        return -1;
      }
        
      else if(this.policy == 'D')
      {
        //printf("indide remove\n");
        int slot = hash_duration(duration);
        //slot = 3;
        LNode bucketi = this.buckets[slot].head;
        if (bucketi == null)
        {
          return 1;
        }
        else //the list is not empty
        {
          LNode ptr = bucketi;
          LNode prev = bucketi;
        
          //more than 1 song in list
          while(1 != 0)
          {
            if(title.equals(ptr.title) && artist.equals(ptr.artist) && duration == (ptr.duration)) //is true
            {
              if(ptr == bucketi)
              {
                this.buckets[slot].head = ptr.next;
              }
              else
              {
                prev.next = ptr.next;
              }
              return 0;
              
            }
            if (ptr.next == null)
            {
              break;
            }
            else
            {
              prev = ptr;
              ptr = ptr.next;
            }

          }
        }
      }
      return -1;
          
    }

    public int hash_alphabetical(String title) {
      int sum = 0;
      char[] titleArray = title.toCharArray(); 
      if(title != null)
      {
        for(int i = 0; i < titleArray.length; i++)
        {
          sum += (int)titleArray[i];
        }
      }
      int hashA = sum % NUM_BUCKETS;
      return hashA;
      //This is the bucket in which the song is added to
    }

    public int hash_duration(int duration) {
      int hashD = duration % NUM_BUCKETS;
      return hashD;
    }

    void addToListSongName (String title, String artist, int duration, LList list)
    {
    
      if (list.head == null) 
      {
        list.head = makeNode(title, artist, duration);
      }
      else 
      {
        LNode ptr = list.head;
        LNode prev = list.head;
        
      //more than 1 song in list
       LNode tmp = makeNode(title, artist, duration);
        
        while(1 != 0)
        {
          int compare = title.compareToIgnoreCase(ptr.title);
          if(compare <= 0 )
          {
            tmp.next = ptr;
            if(ptr == list.head)
            {
              list.head = tmp;
            }
            else
            {
              prev.next = tmp;
            }
            break;
          }
          if (ptr.next == null)
          {
            ptr.next = tmp;
            tmp.next = null;
            break;
          }
          else
          {
            prev = ptr;
            ptr = ptr.next;
          }
        }
        
      }
    }

    void addToListDuration(String title, String artist, int duration, LList list)
    {
      if (list.head == null) 
      {
        list.head = makeNode(title, artist, duration);
      }
      else 
      {
        LNode ptr = list.head;
        LNode prev = list.head;
        
      //more than 1 song in list
        
        LNode tmp = makeNode(title, artist, duration);
        while(1 != 0)
        {
          if(compareDurations(duration, ptr.duration))
          {
            tmp.next = ptr;
            if(ptr == list.head)
            {
              list.head = tmp;
            }
            else
            {
              prev.next = tmp;
            }
            break;
          }
          if (ptr.next == null)
          {
            ptr.next = tmp;
            tmp.next = null;
            break;
          }
          else
          {
            prev = ptr;
            ptr = ptr.next;
          }
        }
      }
    }
    
    boolean compareDurations(int d1, int d2)
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

    LNode makeNode(String title, String artist, int duration)
    {
      //we need to create the node(song entry)
      LNode song;
      song = new LNode(title, artist, duration);
      song.title = title;
      song.artist = artist;
      song.duration = duration;
      song.next = null;
      return song;
    }
    
    


      
}
