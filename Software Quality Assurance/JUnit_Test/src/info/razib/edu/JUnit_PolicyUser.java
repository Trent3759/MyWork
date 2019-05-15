package info.razib.edu;

import static org.junit.Assert.*;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class JUnit_PolicyUser {
	private final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
	private PolicyUser user;

	@Before
	public void setUp() {
		user = new PolicyUser();
	}
	
	@After
	public void cleanUp(){
		user = null;
	}
	
	@Test
	public void testPolicyUser() {
		assertEquals("u000", user.userId);
		assertEquals("s000", user.SessionId);
		assertEquals(1, user.MCC);
		assertEquals(909, user.MNC);
		assertFalse(user.service);
	}

	@Test
	public void testPolicyUserStringIntInt() {
		user = new PolicyUser("u104", 24, 1088);
		assertEquals("u104", user.userId);
		assertEquals("s000", user.SessionId);
		assertEquals(24, user.MCC);
		assertEquals(1088, user.MNC);
		assertFalse(user.service);
	}

	@Test
	public void testGetSessionId() {
		assertEquals("s000", user.getSessionId());
	}

	@Test
	public void testGetUserId() {
		assertEquals("u000", user.getUserId());
	}

	@Test
	public void testGetMCC() {
		assertEquals(1, user.getMCC());
	}

	@Test
	public void testGetMNC() {
		assertEquals(909, user.getMNC());
	}

	@Test
	public void testPrintUserDetails() {
		System.setOut(new PrintStream(outContent));
		PolicyUser.printUserDetails();
		String output = "This is a test message inside PolicyUser class\r";
		assertEquals(output, outContent.toString());
		System.setOut(null);
	}

}
