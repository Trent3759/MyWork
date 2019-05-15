
package info.razib.edu;

import java.io.*;


public class TestDriver {
	@SuppressWarnings("static-access")
	public static void main(String[] args){  
		
		
		//file is located in C:\\Temp\\
		//this will hopefully make it easier to place the text file for reading. 
		String fileName = "C:\\Temp\\user.txt";
		
		//set reference for one line at a time
		String line = null;
		
		try {
			//read file with default system encoding
			FileReader fileReader = new FileReader(fileName);

			//fileReader should be wrapped in BufferReader
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			
			while((line = bufferedReader.readLine()) != null){
				//test the individual data here
				LocalUser user = new LocalUser(line, 1, 70);
				System.out.println(user.getUserId() + " is a local " + user.getUserCategory() + " user.");
				
				
				
			}
			
			//close the file stream
			bufferedReader.close();
		}
		catch (Exception x) {
				System.out.println("File cannot be opened\n" + x);
			}
		}
		
}
