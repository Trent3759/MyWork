package info.razib.edu;

import java.io.*;

public class TestDriver {
	public static void main (String [] args){
		//file is located in local project directory
		
		processUsersFromFile("user.txt");

		
	}
	
	public static void processUsersFromFile(String fileName){
		try {
			String line = null;
			
			
			//read text with default incoding
			FileReader fileReader = new FileReader(fileName);
			
			//wrap FileReader in BufferedReader
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			
			while ((line = bufferedReader.readLine()) != null){
				LocalUser user = new LocalUser(line, 1, 70);				
				
				String message = user.getUserId() + " is a local " + 
						user.getUserCategory() + " user";
				System.out.println(message);
				
				//add setUserService for more coverage
			}
			
			bufferedReader.close();
		} 
		catch (Exception E){
			System.out.println(E);
		}
	}
}
