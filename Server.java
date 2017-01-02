package serial_socket;

import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

import jssc.SerialPort;
import jssc.SerialPortException;

public class Server {
	
	SerialPort sp;
	final String COM = "COM13";
	final int BYTE_NUMBER = 4;
	
	final String HOST = "localhost";
	final int PORT = 9999;
	ServerSocket ss;
	Socket conn;
	OutputStream os;
	
	public Server() {
		
		// Create serial port object
		sp = new SerialPort(COM);
	
		// Initialize socket server and connection socket
		try {
			ss = new ServerSocket();
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void sendData() {
		
		try {
			ss.bind(new InetSocketAddress(HOST, PORT));
			System.out.println("[+] Server listening on " + ss.getInetAddress() + ":" + ss.getLocalPort());
			ss.setReuseAddress(true);
			conn = ss.accept();
			System.out.println("[+] Connection receved from " + conn.getInetAddress() + ":" + conn.getPort());
			os = conn.getOutputStream();
			
			while(System.in.available() == 0) {
				//byte[] data = sp.readBytes(BYTE_NUMBER);
				int data = new Scanner(System.in).nextInt();
				System.out.println(data);
				os.write(data);
			}
			
			sp.closePort();
			conn.close();
			ss.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		} catch (SerialPortException e) {
			e.printStackTrace();
		}
	}

	public void startSerialPort() {
		
		try {
			sp.openPort();
			sp.setParams(SerialPort.BAUDRATE_9600,
			        SerialPort.DATABITS_8,
			        SerialPort.STOPBITS_1,
			        SerialPort.PARITY_NONE);
			sp.setFlowControlMode(SerialPort.FLOWCONTROL_RTSCTS_IN | 
                    SerialPort.FLOWCONTROL_RTSCTS_OUT);
		} catch (SerialPortException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String args[]) throws IOException, InterruptedException, SerialPortException {
		
		Server server = new Server();
		server.startSerialPort();
		server.sendData();
		
		/*SerialPort sp = new SerialPort("COM13");
		sp.openPort();
		sp.setParams(SerialPort.BAUDRATE_9600,
		        SerialPort.DATABITS_8,
		        SerialPort.STOPBITS_1,
		        SerialPort.PARITY_NONE);
		sp.setFlowControlMode(SerialPort.FLOWCONTROL_RTSCTS_IN | 
                SerialPort.FLOWCONTROL_RTSCTS_OUT);
		while(System.in.available() == 0) {
			byte[] data = sp.readBytes(1);
			System.out.println(new String(data));
		}
		
		sp.closePort();*/
	}
		
}

	
