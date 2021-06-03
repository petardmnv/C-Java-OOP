import java.io.File;
import java.util.Scanner;

public class ReadFromFile {
    //myString.split("\\s+");
    private File currentFile;
    public void readFile() throws Exception{
        try {
            File myObj = new File("filename.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                System.out.println(data);
            }
            myReader.close();
        } catch ( e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

}
