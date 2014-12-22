import java.io.*;
import java.net.*;
import java.util.*; 

class serverClass
{
	public static void main(String arsg[])
	{
		try
		{
			ServerSocket s = new ServerSocket(2234);

			while(true)
			{
				System.out.println("Waiting for client to connect");
				Socket client = s.accept();
				System.out.println("Client accepted. Sending the Joke");
				PrintStream p = new PrintStream(client.getOutputStream(),true);
				String str[] = {"Be nice to the nerds, for all you know\nsgasg\n\nthey might be the next Bill Gates!","Artificial intelligence\nsafasf\n usually beats real stupidity.","CAPS LOCK – Preventing Login Since 1980.",
				"Computers make very fast,\n\n very accurate mistakes"};
				int no = (int)(Math.random()*4);
				System.out.println("the random number is "+no);
				p.println(str[no]);
				client.close();
			}
		}
		catch(Exception e)
		{

		}
		
	}
}
