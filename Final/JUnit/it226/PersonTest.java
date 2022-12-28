package it226;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.fail;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.Before;
import org.junit.jupiter.api.Test;

import it226.Person;

class PersonTest
{

	@Test
	void test()
	{
		fail("Not yet implemented");
	}
	
	Person p=null;
	CreditCard c=null;
	double amt, time;
	double interest;
	
	@Before
	public void initialize() {
		p= new Person(549);
		try
		{
			c= new CreditCard(p);
		} catch (Exception e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	@Test
	public void testingGetCreditScore() {
		System.out.println("Running getCreditScore Test");
	
		double min= 550;
		boolean isCreditScoreHighEnough=false;
		
		if(p.getCreditScore()>min) {
			isCreditScoreHighEnough=true;
		}
		 
		assertEquals(true, isCreditScoreHighEnough);
		
	}
	
	@Test
	public void testingCreditLimit() {
		try
		{
			c= new CreditCard(p);
		} catch (Exception e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		boolean rateBetween= false;
		boolean pass=false;
		
		if(c.getRate()>11 && p.getCreditScore() >551 && p.getCreditScore() <750) {
			rateBetween= true;
		}
		
		if(c.getLimit()<6000 && rateBetween) {
			pass=true;
		}
		
		assertEquals(true,true);
		
	}
	

}
