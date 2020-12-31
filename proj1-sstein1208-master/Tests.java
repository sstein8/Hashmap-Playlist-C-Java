public class Tests {

	public static void addTestSimple() {
    System.out.println("Alphabetical Playlist");
    System.out.println("-----------------------");
		HashMap hm = new HashMap('A');
		hm.hm_put("Never Gonna Give You Up", "Rick Astley", 215);
		//hm.hm_put("snow", "Red Hot Chili Peppers", 300);
    hm.hm_put("Snow", "Red Hot Chili Peppers", 300);
    hm.hm_put("Ask", "The Smiths", 230);
    System.out.println("Printing 2 songs");
    hm.printHashMap();
    System.out.println("Getting Never Gonna Give You Up");
    LNode songA1 = hm.hm_get("Never Gonna Give You Up", "Rick Astley", 215);
    System.out.println("Title: " + songA1.title + " Artist: " + songA1.artist + " Duration: " + songA1.duration);
    System.out.println("Removing Snow");
    hm.hm_remove("Snow", "Red Hot Chili Peppers", 300);
    hm.printHashMap();

    System.out.println("-----------------------");
    System.out.println("Duration Sort Playlist");
    HashMap hm2 = new HashMap('D');
    hm2.hm_put("Never Gonna Give You Up", "Rick Astley", 215);
		hm2.hm_put("Snow", "Red Hot Chili Peppers", 300);
    hm2.hm_put("Ask", "The Smiths", 230);
    System.out.println("Printing 2 songs");
    hm2.printHashMap();
    System.out.println("Getting Never Gonna Give You Up");
    LNode songD1 = hm2.hm_get("Never Gonna Give You Up", "Rick Astley", 215);
    System.out.println("Title: " + songD1.title + " Artist: " + songD1.artist + " Duration: " + songD1.duration);
    System.out.println("Removing Snow");
    hm2.hm_remove("Snow", "Red Hot Chili Peppers", 300);
    hm2.printHashMap();

    System.out.println("-----------------------");
    System.out.println("Another Alphabetical Sort Playlist");
    HashMap hm3 = new HashMap('A');
    hm3.hm_put("Never Gonna Give You Up", "Rick Astley", 215);
		hm3.hm_put("Snow", "Red Hot Chili Peppers", 300);
    hm3.hm_put("Ask", "The Smiths", 230);
    System.out.println("Printing 2 songs");
    hm3.printHashMap();
    System.out.println("Getting Never Gonna Give You Up");
    LNode songA2 = hm2.hm_get("Never Gonna Give You Up", "Rick Astley", 215);
    System.out.println("Title: " + songA2.title + " Artist: " + songA2.artist + " Duration: " + songA2.duration);
    System.out.println("Removing Snow");
    hm3.hm_remove("Snow", "Red Hot Chili Peppers", 300);
    hm3.printHashMap();


	}

	public static void main (String[] argv) {
		addTestSimple();

		System.out.println("ALL TESTS PASSED");
	}
}