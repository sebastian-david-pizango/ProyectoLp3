import java.util.Scanner;
public class TestProgram02{

	public static void main (String[] args){
		Scanner scan = new Scanner (System.in);
		Program pro02 = new Program();
		int x = scan.nextInt();
		int y = scan.nextInt();
		pro02.setX(x);
		pro02.setY(y);
		System.out.println(pro02.getAdd());
		
		
		}

}
