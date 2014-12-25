import java.util.Scanner;

class A{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		String c;
		String name;
		String t;
		int T;
		c = scan.next();
		while(true) {
			t = scan.next();
			if (t.equals("#")) { break; }
			
			T = Integer.parseInt(t);
			for (int i=0; i<T; i++) {
				name = scan.next();
				System.out.println(name);
				if (c.equals(name) && ) {
					 = scan.next();
					System.out.println("犯人" + name);
				}
			}
		}
		//System.out.println("END");

	}
}