import java.net.*;
import java.io.*;

class Client {
    public static void main(String args[]) throws Exception {
        Socket s = new Socket("localhost", 5000);
        System.out.println("Connected");
        DataInputStream din = new DataInputStream(s.getInputStream());
        DataOutputStream dout = new DataOutputStream(s.getOutputStream());
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = "", str2 = "";
        while (!str.equals("stop")) {
            System.out.print("\nEnter a number : ");
            str = br.readLine();
            dout.writeUTF(str);
            dout.flush();
            str2 = din.readUTF();
            System.out.println("Server : " + str2);
        }

        dout.close();
        s.close();
    }
}
