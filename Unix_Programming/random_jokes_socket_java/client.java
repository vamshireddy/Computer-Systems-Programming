import java.util.*;
import java.io.*;
import java.net.*;


class client
{
	public static void main(String args[])
	{
		try{
		Socket sock = new Socket("127.0.0.1",2234);
		BufferedReader b = new BufferedReader(new InputStreamReader(sock.getInputStream()));
		String line;
		while((line = b.readLine())!=null)
		{
			System.out.println(line);
		}
		sock.close();
		}
		catch(Exception e)
		{
			System.out.println("Exception \n");
		}
	}
}
