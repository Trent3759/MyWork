package info.razib.edu;
import java.io.*;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class JUnit_LocalUser {
	private final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
	private LocalUser user;
	
	@Before
	public void setUp() {
		user = new LocalUser("3229456",55,125);
	}
	
	@After
	public void cleanUp(){
		user = null;
	}
	
	@Test
	public void testPrintUserDetails() {
		System.setOut(new PrintStream(outContent));
		LocalUser.printUserDetails();
		String output = "This is a test message inside LocalUser class"
				+ System.lineSeparator();
		assertEquals(output, outContent.toString());
		System.setOut(null);
	}

	@Test
	public void testLocalUser() {
		assertEquals("3229456", user.userId);
		assertEquals(55, user.MCC);
		assertEquals(125, user.MNC);
		assertEquals("prepaid", user.userCategory);
	}

	@Test
	public void testSetUserService() {
		assertFalse(user.setUserService());
		user.MCC = 1;
		user.MNC = 70;
		assertTrue(user.setUserService());
		user.MCC = 0;
		assertFalse(user.setUserService());
		user.MCC = 1; user.MNC = 0;
		assertFalse(user.setUserService());
	}

	@Test
	public void testGetUserCategory() {
		assertEquals("prepaid", user.getUserCategory());
		user.userId = "255666224";
		assertEquals("postpaid", user.getUserCategory());
	}

}
