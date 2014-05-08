import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

class F{
	
	public static void main(String args[])
	{
		
		Scanner scan = new Scanner(System.in);
		
		while(true)
		{

			int N = Integer.parseInt(scan.next());
			int M = Integer.parseInt(scan.next());
			if (N==0 && M==0) { break; }
			
						
			for(int m=0; m<M; m++)
			{
				int[] tensus = new int[N];
				ArrayList<Integer> g = new ArrayList<Integer>();
				ArrayList<Integer> c = new ArrayList<Integer>();
				ArrayList<Integer> p = new ArrayList<Integer>();
				for (int n=0; n<N; n++)
				{
					tensus[n] = 0;
					String aString = scan.next();
					if (aString == "g") {
						g.add(n);
					}
					else if (aString == "c") {
						c.add(n);
					}
					else if (aString == "p") {
						p.add(n);
					}
				}
				if (g.isEmpty()==false && c.isEmpty()==false && p.isEmpty()==false) {
					//全員ばらばら
				}
				else if (g.isEmpty()==false && c.isEmpty() && p.isEmpty()) {
					//全員同じ
				}
				else if (g.isEmpty() && c.isEmpty()==false && p.isEmpty()) {
					//全員同じ
				}
				else if (g.isEmpty() && c.isEmpty() && p.isEmpty()==false) {
					//全員同じ
				}
				if (g.isEmpty()==false && c.isEmpty()==false && p.isEmpty()) {
					for (int gg : g) {
						tensus[gg]+=3;
					}
				}
				else if (g.isEmpty() && c.isEmpty()==false && p.isEmpty()==false) {
					for (int cc : c) {
						tensus[cc]+=6;
					}
				}
				else if (g.isEmpty()==false && c.isEmpty() && p.isEmpty()==false) {
					for (int pp : p) {
						tensus[pp]+=6;
					}
				}
				int maxx = 0;
				for (int i=0; i<N; i++) {
					if (tensus[i] >= maxx) {
						maxx = tensus[i];
					}
				}
				for (int i=0; i<N; i++) {
					if (tensus[i] == maxx) {
						System.out.println(i);
					}
				}
			}
			
		}
	}
}