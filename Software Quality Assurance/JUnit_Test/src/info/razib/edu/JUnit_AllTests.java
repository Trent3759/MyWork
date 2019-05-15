package info.razib.edu;
import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

@RunWith(Suite.class)
@SuiteClasses({ JUnit_LocalUser.class, JUnit_RoamingUser.class, JUnit_PolicyUser.class })
public class JUnit_AllTests {
	//nothing to go here. 
}