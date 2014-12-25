import java.util.Scanner;


class D{
	
	public static void main(String args[])
	{
		
		Scanner scan = new Scanner(System.in);
		
		while(true) {
			String ip;
			String[] ips;
			int mask;
			
			ip = scan.next();
			if (ip.equals("0.0.0.0")) { break; }
			ips = ip.split("\\.");
			
			for (String aString : ips) {
				System.out.print(aString + " ");
			}
			System.out.println();

			
			mask = Integer.parseInt(scan.next());

			
			
		}
	}
}