package info.razib.edu;

import java.io.*;

public class TestDriverM {
	public static void main (String [] args){
		//file is located in local project directory
		
		processUsersFromFile("user.txt");
		
		//users.txt for code coverage
		processUsersFromFile("users.txt");
		
		//reset user variable just for introducing other code coverage. 
		LocalUser user = new LocalUser("3224411", 1, 70);
		user.setUserService();
		//change MCC and MNC variable to return false on setUserService
		user.MCC = 0;
		user.MNC = 0;
		user.setUserService();
		user.printUserDetails();
		user.userId = "222204456";
		user.getUserCategory();
		
		//get user id for code coverage
		System.out.println(user.getSessionId() + " is a user session ID.\n\n");
		System.out.println("User details of " + user.getUserId() + "\n-----------" + "\n MCC: " + 
				user.getMCC() + "\n MNC: " + user.getMNC() + "\n-----------\nEnd of user details." );
		
		//declare roamingUser as RoamingUser
		
		RoamingUser roamingUser = new RoamingUser("3226658", 1, 1);
		roamingUser.setUserService();
		roamingUser.MCC = 1;
		roamingUser.MNC = 12;
		roamingUser.setUserService();
		
		PolicyUser policyUser = new PolicyUser();
		policyUser.printUserDetails();
			
		
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
