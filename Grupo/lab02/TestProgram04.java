import java.io.*;

public class TestProgram04{
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

            double num1 = Double.parseDouble(reader.readLine());
            double num2 = Double.parseDouble(reader.readLine());

            JobOptions job = new JobOptions();
            job.setX(num1);
            job.setY(num2);

            System.out.println(job.getAdd());
        } catch (IOException e) {
            System.out.println("Error reading input: " + e.getMessage());
        }
    }
}
