import java.util.Scanner;
import java.util.Calendar;


class C{
	
	public static void main(String args[])
	{
		int UJI52 = 52;
		
		Scanner scan = new Scanner(System.in);
		String a;
		int aa;
		Calendar calendar = Calendar.getInstance();
		
		while(true) {
			a = scan.next();
			if (a.equals("#")) {
				break;
			}
			aa = Integer.parseInt(a);
			
			int count = 0;
			int year = 0;
			int month = 0;
			int day = 0;
			int YY=0;
			calendar.set(aa,0,1);

			if (aa%400==0 || (aa%100!=0 && aa%4==0)) {
				YY = 366;
			}
			else {
				YY = 365;
			}
			for (int i=0; i<YY; i++) {

				if (calendar.get(Calendar.DAY_OF_WEEK) == Calendar.MONDAY)
				{
					count++;
				}
				year = calendar.get(Calendar.YEAR);
				month = calendar.get(Calendar.MONTH) + 1;
				day = calendar.get(Calendar.DATE);
				//System.out.println(year + "年" + month + "月" + day + "日 ");
				calendar.add(Calendar.DATE, 1);
			}
			if (count == UJI52) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
			
		}
	}
}