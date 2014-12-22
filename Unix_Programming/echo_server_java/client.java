import java.util.*;
import java.io.*;
import java.net.*;

class client
{
	public static void main(String arg[])
	{
	try{
		Socket s = new Socket("127.0.0.1",4321);
		BufferedReader is = new BufferedReader(new InputStreamReader(s.getInputStream()));
		PrintWriter os = new PrintWriter(s.getOutputStream(),true);
		os.println("1023142140");
		String line = is.readLine();
		System.out.println(line);
		s.close();
	   }
	   catch(Exception e)
	   {
	   }
	}
}
