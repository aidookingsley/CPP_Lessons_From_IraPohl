// Distance to the moon converted to kilometers
public class Moon {
    public static void main(String[] s) {
        int moon = 238857;
        int moon_kilo;
        System.out.println("Earth to moon = " + moon + " mi.");
        moon_kilo = (int) (moon * 1.609);
        System.out.println("Kilometers = " + moon_kilo + " km. ");
    }

}