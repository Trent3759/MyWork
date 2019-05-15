package info.razib.edu;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class JUnit_RoamingUser {

	private RoamingUser user;

	@Before
	public void setUp() throws Exception {
		user =  new RoamingUser("r1003", 1, 12);
	}

	@After
	public void tearDown() throws Exception {
		user = null;
	}

	@Test
	public void testRoamingUser() {
		assertEquals("r1003", user.userId);
		assertEquals(1, user.MCC);
		assertEquals(12, user.MNC);
	}

	@Test
	public void testSetUserService() {
		assertTrue(user.setUserService());
		user.MNC = 0;
		assertFalse(user.setUserService());
		user.MNC = 120;
		assertTrue(user.setUserService());
		user.MCC = 0;
		assertFalse(user.setUserService());
	}

}
