package info.razib.edu;

public class LocalUser extends PolicyUser{ // Subclass
	// Inheritance gives LocalUser all the same fields and methods as PolicyUser
	// yet allows its code to focus exclusively on the features that make it unique.
	// Every class has one and only one direct superclass (i.e. single inheritance)

	String userCategory;
	
	public LocalUser(String userId, int MCC, int MNC) {
		super(userId, MCC, MNC);
		userCategory = "prepaid";
	}
	
	public boolean setUserService(){
		
		if(this.MCC == 1 && this.MNC == 70){
			this.service = true;
			return true;
		}
		
		return false;
	}
	
	public String getUserCategory(){
		if(this.userId.startsWith("322")){
			return this.userCategory;
		}else {
			this.userCategory = "postpaid";
			return this.userCategory;
		}
		
	}
	
	public static void printUserDetails (){// changed signature
		System.out.println("This is a test message inside LocalUser class");
	}
	
}
