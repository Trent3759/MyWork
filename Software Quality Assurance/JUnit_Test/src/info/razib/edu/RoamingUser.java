package info.razib.edu;

public class RoamingUser extends PolicyUser{

	public RoamingUser(String userId, int MCC, int MNC) {
		super(userId, MCC, MNC);
	}
	
public boolean setUserService(){
		
		if(this.MCC == 1 && ((this.MNC == 12) || (this.MNC == 120))){
			this.service = true;
			return true;
		}
		
		return false;
	}

}
