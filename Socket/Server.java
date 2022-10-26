import java.net.*;
import java.io.*;

class Server {

    static boolean isPrime(int n){
        if (n <= 1)
            return false;
        else if (n == 2)
            return true;
        else if (n % 2 == 0)
            return false;
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    public static void main(String args[]) throws Exception {
        ServerSocket ss = new ServerSocket(5000);
        System.out.println("Server started");
        System.out.println("Waiting for a client ...");
        Socket s = ss.accept();
        System.out.println("Client accepted");
        DataInputStream din = new DataInputStream(s.getInputStream());
        DataOutputStream dout = new DataOutputStream(s.getOutputStream());
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = "", str2 = "";
        while (!str.equals("stop")) {
            str = din.readUTF();
            int inp = Integer.parseInt(str); 
            
            System.out.println("Input: " + inp);
            
            if(isPrime(inp))
                dout.writeUTF(inp + " is prime number");
            else
                dout.writeUTF(inp + " is composite number");

            dout.flush();
        }
        din.close();
        System.out.println("Closing connection");
        s.close();
        ss.close();
    }
}
