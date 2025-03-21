import java.io.*;

public class TestProgram03 {

    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            double num1 = Double.parseDouble(reader.readLine());
            double num2 = Double.parseDouble(reader.readLine());

            Program p03 = new Program();
            p03.setX(num1);
            p03.setY(num2);

            System.out.println(p03.getAdd());
        } catch (IOException e) {
            System.err.println("Error leyendo la entrada: " + e.getMessage());
        } catch (NumberFormatException e) {
            System.err.println("La entrada no es un número válido.");
        }
    }
}
