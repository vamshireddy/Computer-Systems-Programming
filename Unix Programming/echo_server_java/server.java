import java.util.*;
import java.io.*;
import java.net.*;


class server
{
	public static void main(String args[])
	{
	try{
	
		String line="";
		ServerSocket sock = new ServerSocket(4321);
		Socket client = sock.accept();
		System.out.println("CLient accepted \n");
		InputStreamReader is = new InputStreamReader(client.getInputStream());
		PrintWriter os = new PrintWriter(client.getOutputStream(),true);
		int a;
		while( (a = is.read())!='\n' )
		{
			System.out.println((char)a);
			line += (char)a;
		}
		System.out.println("The line is "+line);
		os.println(line);
		client.close();
		sock.close();
	  }
	  catch(Exception e)
	  {
	  }
	}
}
