/*
 * Authors:  Soo Lee, Forrest Allen, Michael Volz
 * Date:    3/9/2019
 * File:    UrlValidatorTest.java
 * Description: Project Part B - tests for URLValidatorInCorrect source
 */

import junit.framework.TestCase;

public class UrlValidatorTest extends TestCase {

	  private boolean printStatus = false;
	  private boolean printIndex = false; // print index that indicates current scheme,host,port,path, query test were using.

	  public UrlValidatorTest(String testName) {
	    super(testName);
	  }

	  public void testManualTest()
	  {
	    UrlValidator urlValUnderTest = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	    System.out.println("\nAllowing all schemes: \n"); 
	    
	    // testing schemes
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com"));
    
	    System.out.println("www.google.com");
	    System.out.println(urlValUnderTest.isValid("www.google.com"));
	        
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("://www.google.com");
	    System.out.println(urlValUnderTest.isValid("://www.google.com"));

	    // testing authority
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com"));
	    
	    System.out.println("http://www.google.au");
	    System.out.println(urlValUnderTest.isValid("http://www.google.au"));
	    
	    System.out.println("http://www.google.uk");
	    System.out.println(urlValUnderTest.isValid("http://www.google.uk"));
	    
	    System.out.println("http://www.goo.gl");
	    System.out.println(urlValUnderTest.isValid("http://www.goo.gl"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google@.com");
	    System.out.println(urlValUnderTest.isValid("http://www.google@.com"));

	    System.out.println("http:// (blank) ");
	    System.out.println(urlValUnderTest.isValid("http:// "));
	    
	    System.out.println("http://www.google");
	    System.out.println(urlValUnderTest.isValid("http://www.google"));
	    
	    System.out.println("http://broken.hostname.org");
	    System.out.println(urlValUnderTest.isValid("http://broken.hostname.org"));
	    
	    System.out.println("http://1.2.3.4");
	    System.out.println(urlValUnderTest.isValid("http://1.2.3.4"));
	    	    

	    // testing ports
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com:25");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:25"));
	    
	    System.out.println("http://www.google.com:376");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:376"));
	    
	    System.out.println("http://www.google.com:4000");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:4000"));
	    
	    System.out.println("http://www.google.com:87000");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:87000"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google.com:");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:"));
	    
	    System.out.println("http://www.google.com:-80");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:-80a"));
	    
	    System.out.println("http://www.google.com:80a");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:80a"));

	    
	    // testing specific paths
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com/mytestpath");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com/mytestpath"));
	    
	    System.out.println("http://www.google.com/");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com/"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google.comtest1");
	    System.out.println(urlValUnderTest.isValid("http://www.google.comtest1"));
	    
	    System.out.println("http://www.google.com//test1");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com//test1"));
	    
	    System.out.println("http://www.google.com/..");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com/.."));
	    
	    System.out.println("http://www.google.com/../");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com/../"));
	    
	    System.out.println("http://www.google.com       /");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com         /"));
	    

	    // testing various options
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com/test1/test1");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com/test1/test1"));
	    
	    System.out.println("http://www.google.com/test1/");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com/test1/"));
	    
	    System.out.println("http://www.google.com/test1test1");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com/test1test1"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google.comtest1test1");
	    System.out.println(urlValUnderTest.isValid("http://www.google.comtest1test1"));
	    
	    System.out.println("http://www.google.com/test1//test1");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com/test1//test1"));

	    
	    // testing queries
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com?action=view");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com?action=view"));
	    
	    System.out.println("http://www.google.com?action=view&hi=hello");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com?action=view&hi=hello"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google.com?action");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com?action="));
	    
	    System.out.println("http://www.google.com=view");
	    System.out.println(urlValUnderTest.isValid("http://www.google.comaction=view"));
	    
	    System.out.println("http://www.google.com??action=view");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com??action=view"));

	    // shifting to NOT allow fragments
	    UrlValidator urlValUnderTestNF = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS);
	    System.out.println("\nAllowing No Fragments: \n");

	    
	    // testing schemes
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com"));
	    
	    System.out.println("www.google.com");
	    System.out.println(urlValUnderTestNF.isValid("www.google.com"));
	    
	    System.out.println("h3tp://www.google.com");
	    System.out.println(urlValUnderTestNF.isValid("h3tp://www.google.com"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http:/www.google.com");
	    System.out.println(urlValUnderTestNF.isValid("://www.google.com"));
	    
	    System.out.println("://www.google.com");
	    System.out.println(urlValUnderTestNF.isValid("://www.google.com"));

	    // testing authority
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com"));
	    
	    System.out.println("http://www.google.au");
	    System.out.println(urlValUnderTest.isValid("http://www.google.au"));
	    
	    System.out.println("http://www.google.uk");
	    System.out.println(urlValUnderTest.isValid("http://www.google.uk"));
	    
	    System.out.println("http://www.goo.gl");
	    System.out.println(urlValUnderTest.isValid("http://www.goo.gl"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google@.com");
	    System.out.println(urlValUnderTest.isValid("http://www.google@.com"));

	    System.out.println("http:// (blank) ");
	    System.out.println(urlValUnderTest.isValid("http:// "));
	    
	    System.out.println("http://www.google");
	    System.out.println(urlValUnderTest.isValid("http://www.google"));
	    
	    System.out.println("http://broken.hostname.org");
	    System.out.println(urlValUnderTest.isValid("http://broken.hostname.org"));
	    
	    System.out.println("http://1.2.3.4");
	    System.out.println(urlValUnderTest.isValid("http://1.2.3.4"));


	    // testing ports
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com:25");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:25"));
	    
	    System.out.println("http://www.google.com:376");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:376"));
	    
	    System.out.println("http://www.google.com:4000");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:4000"));
	    
	    System.out.println("http://www.google.com:87000");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:87000"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google.com:");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com:"));
	    
	    System.out.println("http://www.google.com:-80");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com:-80a"));
	    
	    System.out.println("http://www.google.com:80a");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com:80a"));

	    // testing specific paths
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com/test1");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com/test1"));
	    
	    System.out.println("http://www.google.com/");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com/"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google.comtest1");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.comtest1"));
	    
	    System.out.println("http://www.google.com//test1");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com//test1"));
	    
	    System.out.println("http://www.google.com/..");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com/.."));
	    
	    System.out.println("http://www.google.com/../");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com/../"));
	    

	    // testing various options
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com/test1/test1");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com/test1/test1"));
	    
	    System.out.println("http://www.google.com/test1/");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com/test1/"));
	    
	    System.out.println("http://www.google.com/test1test1");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com/test1test1"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google.comtest1test1");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.comtest1test1"));
	    
	    System.out.println("http://www.google.com/test1//test1");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com/test1//test1"));
	    

	    // testing queries
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com?action=view");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com?action=view"));
	    
	    System.out.println("http://www.google.com?action=view&hi=hello");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com?action=view&hi=hello"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google.com?action");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com?action="));
	    
	    System.out.println("http://www.google.com=view");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.comaction=view"));
	    
	    System.out.println("http://www.google.com??action=view");
	    System.out.println(urlValUnderTestNF.isValid("http://www.google.com??action=view"));

	    UrlValidator urlValUnderTestALU = new UrlValidator(UrlValidator.ALLOW_LOCAL_URLS);
	    System.out.println("\nAllowing local urls: \n");

	    // testing schemes
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com"));
	    
	    System.out.println("www.google.com");
	    System.out.println(urlValUnderTestALU.isValid("www.google.com"));
	    
	    System.out.println("h3tp://www.google.com");
	    System.out.println(urlValUnderTestALU.isValid("h3tp://www.google.com"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http:/www.google.com");
	    System.out.println(urlValUnderTestALU.isValid("://www.google.com"));
	    
	    System.out.println("://www.google.com");
	    System.out.println(urlValUnderTestALU.isValid("://www.google.com"));

	    // authority
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com"));
	    
	    System.out.println("http://www.google.au");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.au"));
	    
	    System.out.println("http://www.google.uk");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.uk"));

	    System.out.println("http://www.goo.gl");
	    System.out.println(urlValUnderTestALU.isValid("http://www.goo.gl"));
	    
	    System.out.println("http://hostname");
	    System.out.println(urlValUnderTestALU.isValid("http://hostname"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google@.com");
	    System.out.println(urlValUnderTest.isValid("http://www.google@.com"));

	    System.out.println("http:// (blank) ");
	    System.out.println(urlValUnderTest.isValid("http:// "));
	    
	    System.out.println("http://www.google");
	    System.out.println(urlValUnderTest.isValid("http://www.google"));
	    
	    System.out.println("http://broken.hostname.org");
	    System.out.println(urlValUnderTest.isValid("http://broken.hostname.org"));
	    
	    System.out.println("http://1.2.3.4");
	    System.out.println(urlValUnderTest.isValid("http://1.2.3.4"));

	    // testing ports
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com:25");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:25"));
	    
	    System.out.println("http://www.google.com:376");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:376"));
	    
	    System.out.println("http://www.google.com:4000");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:4000"));
	    
	    System.out.println("http://www.google.com:87000");
	    System.out.println(urlValUnderTest.isValid("http://www.google.com:87000"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google.com:");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com:"));
	    
	    System.out.println("http://www.google.com:-80");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com:-80a"));
	    
	    System.out.println("http://www.google.com:80a");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com:80a"));

	    // path
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com/test1");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com/test1"));
	    
	    System.out.println("http://www.google.com/");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com/"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google.comtest1");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.comtest1"));
	    
	    System.out.println("http://www.google.com//test1");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com//test1"));
	    
	    System.out.println("http://www.google.com/..");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com/.."));
	    
	    System.out.println("http://www.google.com/../");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com/../"));

	    
	    // testing options
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com/test1/test1");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com/test1/test1"));
	    
	    System.out.println("http://www.google.com/test1/");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com/test1/"));
	    
	    System.out.println("http://www.google.com/test1test1");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com/test1test1"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google.comtest1test1");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.comtest1test1"));
	    
	    System.out.println("http://www.google.com/test1//test1");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com/test1//test1"));

	    
	    // testing queries
	    System.out.println("\nExpected to PASS:");
	    System.out.println("http://www.google.com?action=view");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com?action=view"));
	    
	    System.out.println("http://www.google.com?action=view&hi=hello");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com?action=view&hi=hello"));
	    
	    System.out.println("\nExpected to FAIL:");
	    System.out.println("http://www.google.com?action");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com?action="));
	    
	    System.out.println("http://www.google.com=view");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.comaction=view"));
	    
	    System.out.println("http://www.google.com??action=view");
	    System.out.println(urlValUnderTestALU.isValid("http://www.google.com??action=view"));

	  }

	  // testing schemes 
	  public void testYourFirstPartition() {
	    System.out.println("\nTesting various Schemes:\n");

	    String[] myScheme = {"http://", "h3tp://", "://", ":/", " "};
	    UrlValidator schemeVal = new UrlValidator(myScheme, 0);
	    for (int i = 0; i < myScheme.length; i++) {
	      String testScheme = myScheme[i];
	      System.out.println("\nTesting " + testScheme);
	      boolean valid = schemeVal.isValidScheme(testScheme);
	      if (valid == false && i == 0 || valid == false && i == 1 || valid == true && i == 2 || valid == true && i == 3 || valid == false && i == 4) {
	        System.out.println("FAILED, invalid scheme\n");
	      } else {
	    	System.out.println("PASSED\n");
	      }
	    }
	  }

	  // testing paths
	  public void testYourSecondPartition() {
		  System.out.println("\nTesting Path:\n");

		  String[] myPath = {"/test1", "//test1", "/", "test1", ".."};
		  UrlValidator pathVal = new UrlValidator(myPath, 0);
		  for (int i = 0; i < myPath.length; i++) {
		      String testPath = myPath[i];
		      System.out.println("\nTesting " + testPath);
		      boolean valid = pathVal.isValidPath(testPath);
		      if (valid == false && i == 0 || valid == true && i == 1 || valid == false && i == 2 || valid == true && i == 3) {
		        System.out.println("FAILED, invalid path\n");
		      } else {
		    	System.out.println("PASSED\n");
		      }
		    }    
	  }


	  public void testIsValid() {
	    int errors = 0;
	    int loop_cnt = 10;
	    int kdx = 0;

	    // set up valid parts
	    String[] badUrls = new String[loop_cnt];
	    String[] validSchemes = {"http://", "", "h3tp://"};
	    String[] validAuthority = {"www.google.com", "google.com"};
	    String[] validPort = {":80", ":9", ":100"};
	    String[] validPath = {"/page2", "/"};
	    String[] validQueries = {"?action=view", " "};


	    // randomize valid each round and loop through "loop_cnt" times
	    System.out.println("\nTesting Known Valid Part Inputs:\n");
	    for(int idx = 0; idx < loop_cnt; idx++) {
	      // randomize
	      int schemeInt = (int) (Math.random() * 2);
	      int authorityInt = (int) (Math.random() * 2);
	      int portInt = (int) (Math.random() * 3);
	      int pathInt = (int) (Math.random() * 2);
	      int optionsInt = (int) (Math.random() * 3);
	      int queriesInt = (int) (Math.random() *2);

	      // make string of valid parts in valid order
	      String url = validSchemes[schemeInt] + validAuthority[authorityInt] + validPort[portInt] + validPath[pathInt] + validQueries[queriesInt];
	      UrlValidator validator = new UrlValidator();

	      // check if it was marked valid
	      boolean valid = validator.isValid(url);

	      // if not valid, increase bug count and store url
	      if(valid == false) {
	        errors++;
	        badUrls[kdx] = url;
	        kdx++;
	      }
	    }
	    // print results
	    System.out.println("\nErrors Count: " + errors + "\n");
	    System.out.println("\nBad URLs: \n");
	    for (int j = 0; j < badUrls.length; j++) {
	      if(badUrls[j] != null){
	    	System.out.println(badUrls[j] + "\n");
	      }
	    } 
	  }

	  public void testisValidQueryUnitTest()
	  {
		  UrlValidator val = new UrlValidator();
		  System.out.println("\nUnit Test of isValidQuery\n");
		  System.out.println("\nTesting query ?action=read");
		  System.out.println("Result: " + val.isValidQuery("?action=read"));
		  System.out.println("\nTesting query null");
		  System.out.println("Result: " + val.isValidQuery(""));
		  System.out.println("\nTesting query ?page=2&test=0");
		  System.out.println("Result: " + val.isValidQuery("?page=2&test=0"));
	  }
	  
	  public void testisValidSchemeUnitTest()
	  {
		  UrlValidator val = new UrlValidator();
		  System.out.println("\nUnit Test of isValidScheme\n");
		  System.out.println("\nTesting scheme http");
		  System.out.println("Result: " + val.isValidScheme("http"));
		  System.out.println("\nTesting scheme https");
		  System.out.println("Result: " + val.isValidScheme("https"));
		  System.out.println("\nTesting scheme aaa");
		  System.out.println("Result: " + val.isValidScheme("abc"));
		  System.out.println("\nTesting scheme ftp");
		  System.out.println("Result: " + val.isValidScheme("faa"));
		  
	  }

}