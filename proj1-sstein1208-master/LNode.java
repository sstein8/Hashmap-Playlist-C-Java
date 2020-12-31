public class LNode {
	public String artist;
	public String title;
	public int duration;
	public LNode next;
	/* You may not add more data members to this class. */

	public LNode(String title, String artist, int duration) {
		// Fill in
    this.artist = artist;
    this.title = title;
    this.duration = duration;
	}
}
