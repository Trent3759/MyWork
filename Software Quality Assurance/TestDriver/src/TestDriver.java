import java.io.*;

public class TestDriver {
	public static void main(String[] args){
		System.out.println("Test Driver Started");
		
		
		//file is located in local directory
		String fileName = "user.txt";
		
		//set reference for one line at a time
		String line = null;
		
		try {
			//read file with default system encoding
			FileReader fileReader = new FileReader(fileName);

			//fileReader should be wrapped in BufferReader
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			
			while((line = bufferedReader.readLine()) != null){
				//test the individual data here
				System.out.println(line);
			}
			
			//close the file stream
			bufferedReader.close();
		}
		catch (Exception x) {
				System.out.println("File cannot be opened\n" + x);
			}
		}
		
}
