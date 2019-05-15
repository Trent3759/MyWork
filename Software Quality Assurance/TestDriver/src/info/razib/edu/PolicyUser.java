package info.razib.edu;

public class PolicyUser {// This is our Super Class

	String userId, SessionId;
	int MCC, MNC;
	boolean service;
	
	public PolicyUser(){
		userId = "u000";
		SessionId = "s000";
		MCC = 1;
		MNC = 909;
		service = false;
	
	}
	
	public PolicyUser(String userId, int MCC, int MNC){
		this();
		this.userId = userId;
		this.MCC = MCC;
		this.MNC = MNC;
		
	}
	
	public String getSessionId(){
		return SessionId;
	}
	
	public String getUserId(){
		return userId;
	}
	
	public int getMCC(){
		return MCC;
	}
	
	public int getMNC(){
		return MNC;
	}
	
	public static void printUserDetails(){
		System.out.print("This is a test message inside PolicyUser class\r");
		
	}
	
	

}
